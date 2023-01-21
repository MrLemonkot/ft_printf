# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 18:09:13 by akayle            #+#    #+#              #
#    Updated: 2022/01/12 17:22:42 by akayle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRCS		= ft_printf.c ft_printf_utils.c ft_printf_utils2.c
HEADER		= ft_printf.h
OBJS		= $(SRCS:%.c=%.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all:			$(NAME)

$(NAME):		$(OBJS) $(HEADER)
				ar rcs $(NAME) $?
%.o : %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
