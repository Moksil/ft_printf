CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libftprintf.a

SOURCE = 	ft_printf.c \
			is_specifier.c is_flag.c max_in_2_int.c max_in_3_int.c \
			str_validation.c get_valid_spec.c \
			get_nbr_length.c get_unbr_length.c get_hexa_len_int.c get_hexa_len_long.c \
			put_nbr.c put_nbr_u.c put_hexa_from_long.c put_hexa_from_int.c \
			get_specifier_info.c spec_init.c spec_parsing.c \
			check_minus_flag.c check_zero_flag.c check_plus_flag.c \
			check_space_flag.c check_sharp_flag.c check_width.c check_precision.c \
			call_dispenser.c mod_op_handling.c c_handling.c s_handling.c \
			d_handling.c u_handling.c p_handling.c lower_x_handling.c upper_x_handling.c \
			fadding_space.c fadding_zero.c

LIBDIR = libft
HEADERS = includes
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

.PHONY: all clean fclean re bonus