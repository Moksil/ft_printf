CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libftprintf.a

SOURCE = 	srcs/ft_printf.c \
			srcs/is_specifier.c \
			srcs/is_flag.c \
			srcs/max_in_2_int.c \
			srcs/max_in_3_int.c \
			srcs/str_validation.c \
			srcs/get_valid_spec.c \
			srcs/get_nbr_length.c \
			srcs/get_unbr_length.c \
			srcs/get_hexa_len_int.c \
			srcs/get_hexa_len_long.c \
			srcs/put_nbr.c \
			srcs/put_nbr_u.c \
			srcs/put_hexa_from_long.c \
			srcs/put_hexa_from_int.c \
			srcs/get_specifier_info.c \
			srcs/spec_init.c \
			srcs/spec_parsing.c \
			srcs/check_minus_flag.c \
			srcs/check_zero_flag.c \
			srcs/check_plus_flag.c \
			srcs/check_space_flag.c \
			srcs/check_sharp_flag.c \
			srcs/check_width.c \
			srcs/check_precision.c \
			srcs/call_dispenser.c \
			srcs/mod_op_handling.c \
			srcs/c_handling.c \
			srcs/s_handling.c \
			srcs/d_handling.c \
			srcs/u_handling.c \
			srcs/p_handling.c \
			srcs/lower_x_handling.c \
			srcs/upper_x_handling.c \
			srcs/fadding_space.c \
			srcs/fadding_zero.c

LIBDIR = libft
HEADERS = include
OBJECTS = $(SOURCE:.c=.o)

%o: %c
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) -I$(HEADERS) -I$(LIBDIR)

$(NAME):	$(OBJECTS)
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

bonus: $(NAME)

.PHONY: all clean fclean re bonus