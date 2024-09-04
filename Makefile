NAME = libft.a
SRCS = ft_bzero.c ft_isascii.c ft_memset.c ft_strlcpy.c ft_tolower.c ft_isalnum.c \
ft_isdigit.c ft_memcpy.c ft_strchr.c ft_strlen.c ft_toupper.c ft_isalpha.c ft_isprint.c \
ft_memmove.c ft_strlcat.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = $(SRCS:.c=.o)
#ifdef WITH_BONUS
OBJS += $(BONUS_SRCS:.c=.o)
#sendif
CC = clang
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rsc

.PHONY: all fclean clean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

bonus: $(BONUS_SRCS:.c=.o)
	@make WITH_BONUS=1

clean:
	$(RM) $(OBJS) $(BONUS_SRCS:.c=.o)

fclean: clean
	$(RM) $(NAME) a.out
 
re: fclean all

run:
	$(CC) libft.a && ./a.out

rerun: re run

lldb:	all
		$(CC) libft.a && lldb --args ./a.out

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	$(CC) -nostartfiles -shared -o libft.so $(OBJS)
