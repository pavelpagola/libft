CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

SRCS = ft_atoi.c ft_isascii.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
	ft_bzero.c ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
	ft_calloc.c ft_isprint.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
	ft_isalnum.c ft_itoa.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c \
	ft_isalpha.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

