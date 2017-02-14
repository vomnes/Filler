NAME = libft.a
SRC = ft_lstadd.c ft_memdel.c	ft_strcat.c	ft_strlcat.c ft_strrchr.c \
			ft_lstdel.c ft_memmove.c ft_strchr.c ft_strsplit.c \
			ft_lstdelone.c ft_memset.c ft_strclr.c ft_strlen.c ft_strstr.c \
			ft_atoi.c	ft_lstiter.c ft_putchar.c ft_strcmp.c	ft_strmap.c \
			ft_strsub.c ft_bzero.c ft_lstmap.c ft_putchar_fd.c ft_strcpy.c \
			ft_strmapi.c ft_strtrim.c ft_isalnum.c ft_lstnew.c ft_putendl.c \
			ft_strdel.c ft_strncat.c ft_tolower.c ft_isalpha.c ft_memalloc.c \
			ft_putendl_fd.c ft_strdup.c	ft_strncmp.c ft_toupper.c ft_isascii.c \
			ft_memccpy.c ft_putnbr.c ft_strequ.c ft_strncpy.c ft_isdigit.c \
			ft_memchr.c ft_putnbr_fd.c ft_striter.c	ft_strnequ.c ft_isprint.c \
			ft_memcmp.c	ft_putstr.c	ft_striteri.c	ft_strnew.c ft_itoa.c \
			ft_memcpy.c	ft_putstr_fd.c ft_strjoin.c ft_strnstr.c ft_islower.c \
			ft_isspace.c ft_isupper.c ft_min.c ft_swap.c ft_find_c.c \
			ft_lst_display_s.c ft_lst_display_int.c ft_lstsize.c ft_lstadd_end.c \
			ft_lst_strsplit.c ft_strnjoin.c ft_strndup.c ft_strddel.c ft_itoa_base.c \
			ft_strcjoin.c ft_putwchar.c ft_putwstr.c ft_wstrlen.c ft_lltoa.c \
			ft_lltoi.c ft_putnwstr.c ft_isxdigit.c ft_pow.c ft_hex_to_dec.c
OBJET = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

.PHONY: clean fclean all re

all: $(NAME)

$(NAME):	$(OBJET)
			@echo Compiling $(NAME)...
			@gcc -c $(FLAGS) $(SRC)
			@ar rc $(NAME) $(OBJET)
			@ranlib $(NAME)
			@echo ======[Done]======

%.o : %.c
			@echo "$(NAME) >>> Add/Update $^"

clean:
			@echo Clean objects
			@rm -rf $(OBJET)

fclean: clean
			@echo Clean $(NAME)
			@rm -rf $(NAME)

re: fclean all
