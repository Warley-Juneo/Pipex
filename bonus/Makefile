# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 15:29:27 by wjuneo-f          #+#    #+#              #
#    Updated: 2021/11/18 15:29:28 by wjuneo-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH		= .././libft
LIBFT			= $(LIBFT_PATH)/libft.a

SOURCE			= pipex_bonus.c

OBJECTS			= $(SOURCE:.c=.o)

HEADER			= pipex.h
NAME			= pipex.a

CC				= clang
RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(LIBFT_PATH)

all:		$(LIBFT) $(NAME)

$(NAME):	$(OBJECTS)
			cp	$(LIBFT) $(NAME)
			$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re: 			clean fclean all

run:
				clang -Wall -Werror -Wextra $(SOURCE) pipex.a

runb:
				clang -Wall -Werror -Wextra pipex_bonus.c pipex.a

norm:
				norminette *c && norminette ./libft/*c

.PHONY:			all clean fclean re run norm
