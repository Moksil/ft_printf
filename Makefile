CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libftprintf.a

SOURCE = ft_printf.c ft_putnbr_m_fd.c ft_putnbr_um_fd.c

LIBDIR = libft
HEADERS = includes
OBJECTS = $(SOURCE:.c=.o)

%o: %c
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) -I$(HEADERS) -I$(LIBDIR)

$(NAME): $(OBJECTS)
	$(MAKE) all -C ./libft
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJECTS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus