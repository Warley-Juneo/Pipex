LIBFT_UTILS		= ./src_utils

SOURCE			= main.c format_comands.c pipex.c ./src_utils/ft_split.c
SOURCE			+= ./src_utils/ft_strdup.c ./src_utils/ft_strlen.c
SOURCE			+= ./src_utils/ft_strncmp.c ./src_utils/ft_substr.c ./src_utils/ft_calloc.c
SOURCE			+= ./src_utils/ft_strlcpy.c ./src_utils/ft_memset.c ./src_utils/ft_memcpy.c
SOURCE			+= ./src_utils/ft_strjoin.c spaces_treats.c

OBJECTS			= $(SOURCE:.c=.o)

HEADER			= pipex.h
NAME			= pipex

CC				= clang
RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror -std=c11 -ggdb3
AR 				= ar
ARFLAGS			= rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(LIBFT) $(NAME)

$(NAME):		$(LIBFT) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

clean:
				$(RM) $(OBJECTS)

fclean:			clean
				$(RM) $(NAME)

re: 			clean fclean all

run:
				clang $(SOURCE) pipex

.PHONY:			all clean fclean re run
