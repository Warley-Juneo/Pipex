LIBFT_PATH		= ./libft
LIBFT			= $(LIBFT_PATH)/libft.a

SOURCE			= main.c format_comands.c pipex.c

OBJECTS			= $(SOURCE:.c=.o)

HEADER			= pipex.h
NAME			= pipex

CC				= clang
RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror
AR 				= ar
ARFLAGS			= rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(LIBFT_PATH)

all:			$(LIBFT) $(NAME)

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

re: 			clean fclean all

run:
				clang $(SOURCE) pipex

norm:
				norminette *c && norminette ./libft/*c

.PHONY:			all clean fclean re run norm
