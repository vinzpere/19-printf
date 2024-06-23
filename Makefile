# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpere <vpere@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 23:00:15 by vpere             #+#    #+#              #
#    Updated: 2024/05/31 17:38:35 by vpere            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c c_printf.c s_printf.c \
		u_printf.c int_printf.c x_printf.c p_printf.c\

OBJ = $(SRC:.c=.o)

AR		=	@ar -rc

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) ${OBJ}
	
$(OBJ) :
	$(CC) $(CFLAGS) -c $(@:.o=.c)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)


re : fclean $(NAME)

.PHONY: all fclean clean re bonus