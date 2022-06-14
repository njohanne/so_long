/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:31:54 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/04 17:55:50 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

long	ft_pow10(long n)
{
	long	rez;

	rez = 1;
	if (n > 0)
	{
		n--;
		rez = ft_pow10(n) * 10;
	}
	return (rez);
}

int	ft_count(long n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	if (count != 0)
		count--;
	return (count);
}

void	ft_putnbr(int n)
{
	long	i;
	long	j;
	int		count;

	i = n;
	count = 0;
	if (n < 0)
	{
		i *= -1;
		ft_putchar('-');
	}
	count = ft_count(i);
	j = i;
	while (count >= 0)
	{
		i = j / ft_pow10(count);
		j = j % ft_pow10(count);
		ft_putchar((i + '0'));
		count--;
	}
}
