/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:24:40 by njohanne          #+#    #+#             */
/*   Updated: 2022/06/14 16:56:01 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_itoa_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa_str(unsigned int n, int count, char *str)
{
	str[count + 1] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[count] = (n % 10) + '0';
		n /= 10;
		count--;
	}
	return (&str[0]);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				pol;
	int				count;
	unsigned int	nn;

	if (n < 0)
	{
		nn = n * -1;
		pol = -1;
		count = 1;
	}
	else
	{
		nn = n;
		pol = 1;
		count = 0;
	}
	count = count + ft_itoa_count(nn);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	if (pol == -1)
		str[0] = '-';
	count--;
	return (ft_itoa_str(nn, count, str));
}
