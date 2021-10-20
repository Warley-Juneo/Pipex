LIBFT_PATH		= ./libft
LIBFT			= $(LIBFT_PATH)/libft.a

SOURCE			= main.c pipex.c first_comand.c second_comand.c

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

norm:
				norminette *c && norminette ./libft/*c

.PHONY:			all clean fclean re run norm
