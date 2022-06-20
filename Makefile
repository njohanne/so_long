# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 14:54:46 by njohanne          #+#    #+#              #
#    Updated: 2022/06/20 07:51:51 by njohanne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

BONUS_NAME	=	so_long_bonus

SRC		=	so_long.c \
			utils/ft_error.c \
			utils/ft_strlen.c \
			utils/ft_strjoin.c \
			utils/ft_split.c \
			utils/ft_putnbr.c \
			mand/ft_window.c \
			mand/ft_game.c \
			mand/check_map/ft_check_map.c \
			mand/check_map/ft_check_requirement.c

SRC_BONUS = bonus/so_long_bonus.c \
			utils/ft_error.c \
			utils/ft_strlen.c \
			utils/ft_strjoin.c \
			utils/ft_split.c \
			utils/ft_putnbr.c \
			utils/ft_itoa.c \
			bonus/check_map/check_map_bonus.c \
			bonus/check_map/ft_check_requirement_bonus.c \
			bonus/game/ft_window_bonus.c \
			bonus/game/ft_game_bonus.c \
			bonus/game/ft_line_window.c
			
CC = gcc			

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(SRC_BONUS:.c=.o)

%.o: %.c
	$(CC) -I./mlx -c $< -o $@

#FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./mlx
	$(CC) $(OBJS) -L ./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@mv mlx/libmlx.dylib .

%.o: %.c
	$(CC) -I./mlx -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	make -C ./mlx
	$(CC) $(BONUS_OBJS) -L ./mlx -lmlx -framework OpenGL -framework AppKit -fsanitize=address  -o $(BONUS_NAME)
	@mv mlx/libmlx.dylib .

clean :
	make -C ./mlx clean
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	@rm -f $(NAME) $(BONUS_NAME)

re : fclean all