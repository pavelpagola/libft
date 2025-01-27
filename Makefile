CC = clang
CFLAGS = -Wall -Werror -Wextra -I.

SRCS = ft_atoi.c ft_isascii.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
	ft_bzero.c ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
	ft_calloc.c ft_isprint.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
	ft_isalnum.c ft_itoa.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c \
	ft_isalpha.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_lstnew.c \
	ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	get_next_line_bonus.c get_next_line_utils_bonus.c ft_printf.c \
	ft_strcmp.c ft_read_file.c ft_malloc_v2.c get_next_line_utils_2_bonus.c \
	ft_sprintf.c ft_sprintf_2.c ft_sprintf_3.c ft_sprintf_4.c ft_sprintf_ltoa.c ft_sprintf_stoa.c \
	ft_strclean.c ft_strreplace.c ft_open.c ft_clean.c

OBJS = $(SRCS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re animation done
