LIBFT_PATH		= ./libft
LIBFT			= $(LIBFT_PATH)/libft.a

SOURCE			= main.c pipex.c first_comand.c second_comand.c

OBJECTS			= $(SOURCE:.c=.o)

HEADER			= pipex.h
NAME			= pipex.a

CC				= clang
RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJECTS) $(HEADER)
		$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re: clean fclean all

run:
				clang -Wall -Werror -Wextra *c && ./a.out

norm:
				norminette *c && norminette ./libft/*c

.PHONY:			all clean fclean re run norm
