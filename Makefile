# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 17:58:41 by obelaizi          #+#    #+#              #
#    Updated: 2022/11/10 01:45:54 by obelaizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

FLAGS= -Wall -Wextra -Werror

SRCS= ft_printf.c ft_put_exadicimal.c ft_put_pointer.c ft_putchar.c ft_putnbr_int.c ft_putnbr_unsigned.c ft_putstr.c ft_strdup.c ft_strlen.c

OBJS= $(SRCS:.c=.o)


all: $(NAME)

%.o: %.c ft_printf.h
	cc -c $(FLAGS) $<

$(NAME): $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) 

fclean:clean
	@rm -f $(NAME)

re: fclean all