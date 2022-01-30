/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:51:53 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/22 21:51:54 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_specifier(char c)
{
	if (c == '%' || c == 'c'|| c == 's' || c == 'p' ||	c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else if (c == 'C' || c == 'D'|| c == 'U')
		return (1);
	else
		return (0);
}

int		is_flag(char c)
{ 
	if (c == '-' || c == '.'|| c == '#' || c == ' ' || c == '+')
		return (1);
	else
		return (0);
}

int max_of_3(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b > c)
			return (b);
		else
			return (c);
	}
}

t_spec str_to_struct(char *spec_str)
{
	t_spec	ret;

	ret.specifier = 0;
	if (spec_str == NULL)
		return (ret);
	ret.specifier = spec_str[ft_strlen(spec_str) - 1];
	ret.len = (int)ft_strlen(spec_str);
	return (ret);
}

int	get_nbr_length(int n)
{
	int		ret;

	ret = 1;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
		ret += get_nbr_length((-1) * n);
	else if (n < 10)
		return (1);
	else
		ret += get_nbr_length(n / 10);
	return (ret);
}

int	get_unbr_length(unsigned int n)
{
	int		ret;

	ret = 1;
	if (n < 10)
		return (1);
	else
		ret += get_unbr_length(n / 10);
	return (ret);
}

int	get_hexa_len_int(unsigned int nbr, char flag)
{
	int		ret;

	ret = 1;
	if (nbr < 0)
		ret += get_hexa_len_int(0xFFFFFFFF + nbr + 1, flag) - 1;
	if (nbr < 16)
		return (1);
	else
		ret += get_hexa_len_int(nbr / 16, flag);
	return(ret);
}

int	put_hexa_from_int(unsigned int nbr, char flag)
{
	char	*base;

	if (flag == 'x')
		base = "0123456789abcdef";
	if (flag == 'X')
		base = "0123456789ABCDEF";
	if (nbr < 0)
		put_hexa_from_int(0xFFFFFFFF + nbr + 1, flag) - 1;
	if (nbr < 16)
		write(1, &base[nbr % 16], 1);
	else
	{
		put_hexa_from_int(nbr / 16, flag);
		write(1, &base[nbr % 16], 1);
	}
}

int	get_hexa_len_long(unsigned long nbr)
{
	unsigned long	ret;

	ret = 1;
	if (nbr < 16)
		return (1);
	else
		ret += get_hexa_len_long(nbr / 16);
	return(ret);
}

void	put_hexa_from_long(unsigned long nbr, char flag)
{
	char	*base;

	if (flag == 'x')
		base = "0123456789abcdef";
	if (flag == 'X')
		base = "0123456789ABCDEF";
	if (nbr < 16)
		write(1, &base[nbr % 16], 1);
	else
	{
		put_hexa_from_long(nbr / 16, flag);
		write(1, &base[nbr % 16], 1);
	}
}

void width_handling(t_spec spec_info, int arglength)
{
	int	i;
	int flag;
	
	flag = spec_info.plus_flag + spec_info.space_flag;
	i = 0;
	if(spec_info.width > spec_info.precision)
	{
		if (spec_info.precision > arglength)
		{
			while (i++ < spec_info.width - spec_info.precision - flag)
			{
				if (spec_info.zero_flag == 1)
					write(1, "0", 1);
				else
					write(1, " ", 1);
			}
		}
		while (i++ < spec_info.width - arglength)
		{
			if (spec_info.zero_flag == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	}
}

void put_precision_char(char specifier)
{
	if (specifier == '%')
		write(1, " ", 1);
	else
		write(1, "0", 1);
}

void precision_handling(t_spec spec_info, int arglength)
{
	int	i;

	i = 0;
	if (spec_info.plus_flag)
		write(1, "+", 1);
	else if(spec_info.space_flag)
		write(1, " ", 1);	
	if (spec_info.precision > arglength)
	{
		if(spec_info.width > spec_info.precision)
			while (i++ < spec_info.width - arglength)
				put_precision_char(spec_info.specifier);
		else
			while (i++ < spec_info.precision - arglength)
				put_precision_char(spec_info.specifier);
	}
}

int	mod_op_handling(t_spec spec_info)
{
	char	mod_op = '%';
	int		i;
	int		arglength;
	
	i = 0; 
	arglength = 1;
	if (spec_info.minus_flag == 1)
		write(1, &mod_op, arglength);
	precision_handling(spec_info, arglength);
	width_handling(spec_info, arglength);
	if (spec_info.minus_flag == 0)
		write(1, &mod_op, arglength);
	return (max_of_3(spec_info.width, spec_info.precision, arglength));
}

void d_print(t_spec spec_info, int sign, int d_val)
{
	int	arglength;
	
	arglength = get_nbr_length(sign * d_val);
	if (spec_info.minus_flag == 1)
	{
		if (sign == -1)
			write(1, "-", 1);
		precision_handling(spec_info, arglength);
		ft_putnbr_m_fd(sign * d_val, 1);
	}
	if (sign == 1)
		width_handling(spec_info, arglength);
	else
		width_handling(spec_info, arglength + 1);
	if (spec_info.minus_flag == 0)
	{
		if (sign == -1)
			write(1, "-", 1);
		precision_handling(spec_info, arglength);
		ft_putnbr_m_fd(sign * d_val, 1);
	}
}

int	d_handling(va_list* ap, t_spec spec_info)
{
	int sign;
	int	d_val;
	int	arglength;

	d_val = va_arg(*ap, int);
	if (d_val > 0)
		sign = 1;
	else
		sign = -1;
	arglength = get_nbr_length(d_val);
	d_print(spec_info, sign, d_val);
	return (max_of_3(spec_info.width, spec_info.precision, arglength));
}

int	u_handling(va_list* ap, t_spec spec_info)
{
	unsigned int	d_val;
	int				arglength;

	d_val = va_arg(*ap, int);
	arglength = get_unbr_length(d_val);
	if (spec_info.minus_flag == 1)
	{
		precision_handling(spec_info, arglength);
		ft_putnbr_um_fd(d_val, 1);
	}
	width_handling(spec_info, arglength);
	if (spec_info.minus_flag == 0)
	{
		precision_handling(spec_info, arglength);
		ft_putnbr_um_fd(d_val, 1);
	}
	return (max_of_3(spec_info.width, spec_info.precision, arglength));
}

int	c_handling(va_list* ap, t_spec spec_info)
{
	char	ch_val;
	ch_val = va_arg(*ap, int);
	write(1, &ch_val, 1);
	return (1);
}

int	s_handling(va_list* ap, t_spec spec_info)
{
	char	*s_ptr;
	int		str_size;
	
	s_ptr = va_arg(*ap, char *);
	if (s_ptr == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	str_size = ft_strlen(s_ptr);
	write(1, s_ptr, str_size);
	return (str_size);
}

int	lower_x_handling(va_list* ap, t_spec spec_info)
{
	int		int_val;
	int		arglength;

	int_val = va_arg(*ap, int);
	arglength = get_hexa_len_long(int_val);
	if (spec_info.zero_flag == 1 && spec_info.sharp_flag == 2)
		write(1, "0x", 2);
	if (spec_info.minus_flag == 1)
	{
		precision_handling(spec_info, arglength);
		if (spec_info.zero_flag == 0 && spec_info.sharp_flag == 2)
			write(1, "0x", 2);
		put_hexa_from_int(int_val, 'x');
	}
	width_handling(spec_info, arglength + spec_info.sharp_flag);
	if (spec_info.minus_flag == 0)
	{
		precision_handling(spec_info, arglength);
		if (spec_info.zero_flag == 0 && spec_info.sharp_flag == 2)
			write(1, "0x", 2);
		put_hexa_from_int(int_val, 'x');
	}
	return (max_of_3(spec_info.width, spec_info.precision, arglength));
}

int	upper_x_handling(va_list* ap, t_spec spec_info)
{
	int		int_val;
	int		arglength;

	int_val = va_arg(*ap, int);
	arglength = get_hexa_len_long(int_val);
	if (spec_info.zero_flag == 1 && spec_info.sharp_flag == 2)
		write(1, "0X", 2);
	if (spec_info.minus_flag == 1)
	{
		precision_handling(spec_info, arglength);
		if (spec_info.zero_flag == 0 && spec_info.sharp_flag == 2)
			write(1, "0X", 2);
		put_hexa_from_int(int_val, 'X');
	}
	width_handling(spec_info, arglength + spec_info.sharp_flag);
	if (spec_info.minus_flag == 0)
	{
		precision_handling(spec_info, arglength);
		if (spec_info.zero_flag == 0 && spec_info.sharp_flag == 2)
			write(1, "0X", 2);
		put_hexa_from_int(int_val, 'X');
	}
	return (max_of_3(spec_info.width, spec_info.precision, arglength));
}

int	p_handling(va_list* ap, t_spec spec_info)
{
	void	*p_ptr;
	int		arglength;

	p_ptr = va_arg(*ap, void *);
	arglength = get_hexa_len_long((long)p_ptr);
	if (spec_info.zero_flag == 1)
		write(1, "0x", 2);
	if (spec_info.minus_flag == 1)
	{
		precision_handling(spec_info, arglength);
		if (spec_info.zero_flag == 0)
			write(1, "0x", 2);
		put_hexa_from_long((long)p_ptr, 'x');
	}
	width_handling(spec_info, arglength + 2);
	if (spec_info.minus_flag == 0)
	{
		precision_handling(spec_info, arglength);
		if (spec_info.zero_flag == 0)
			write(1, "0x", 2);
		put_hexa_from_long((long)p_ptr, 'x');
	}
	return (max_of_3(spec_info.width, spec_info.precision, arglength));
}

int	call_dispenser(va_list* ap, t_spec s)
{
	int ret;
	if (s.specifier == '%')
		ret = mod_op_handling(s);
	else if (s.specifier == 'd' || s.specifier == 'D' || s.specifier == 'i')
		ret = d_handling(ap, s);
	else if (s.specifier == 'c' || s.specifier == 'C')
		ret = c_handling(ap, s);
	else if (s.specifier == 's')
		ret = s_handling(ap, s);
	else if (s.specifier == 'p')
		ret = p_handling(ap, s);
	else if (s.specifier == 'u' || s.specifier == 'U')
		ret = u_handling(ap, s);
	else if (s.specifier == 'x')
		ret = lower_x_handling(ap, s);
	else if (s.specifier == 'X')
		ret = upper_x_handling(ap, s);
	else
		ret = 0;
	return (ret);
}

char	*spec_validate(char *ptr)
{
	int		i;
	
	i = 0;
	while (ptr && ptr[i])
	{
		i++;
		if (is_flag(ptr[i]))
			continue ;
		if (ft_isdigit(ptr[i]))
			continue ;
		if (is_specifier(ptr[i]))
			break ;
		break ;
	}
	if (ptr && is_specifier(ptr[i]))
		return (ptr);
	return (NULL);
}

const char	*get_valid_spec(const char *mod_op_ptr)
{
	int			i;
	const char	*spec_ptr;
	
	i = 0;
	spec_ptr = mod_op_ptr;
	while (mod_op_ptr && *(++spec_ptr))
	{
		if (is_flag(*spec_ptr))
			continue ;
		if (ft_isdigit(*spec_ptr))
			continue ;
		if (is_specifier(*spec_ptr))
			break ;
		break ;
	}
	if (mod_op_ptr && is_specifier(*spec_ptr))
		return (spec_ptr);
	return (NULL);
}

int	str_validation(const char *str)
{
	const char		*mod_op_ptr;
	const char		*spec_ptr;

	mod_op_ptr = ft_strchr(str, '%');
	while (mod_op_ptr)
	{
		spec_ptr = get_valid_spec(mod_op_ptr);
		if (spec_ptr == NULL)
			return (-1);
		if (*spec_ptr == '%')
			spec_ptr++;
		mod_op_ptr = ft_strchr(spec_ptr, '%');
	}
	return (0);
}

// va_list의 인자 수 찾아서 그와 같은 수의 valid 한 specifier가 존재하는지 확인
// else -> ft_printf에서 -1	Return
// printf_validation

// flag : [-], [0], [+], [ ], [#]
t_spec	check_minus_flag(t_spec ret, char *mod_op_ptr, int i)
{
	if (i == 1 && mod_op_ptr[i] == '-')
		ret.minus_flag = 1;
	if (mod_op_ptr[i] == '-'
		&& (mod_op_ptr[i - 1] == '0' || mod_op_ptr[i - 1] == ' '
			|| mod_op_ptr[i - 1] == '+' || mod_op_ptr[i - 1] == '#' ))
	{
		if (ret.zero_flag == 1)
			ret.zero_flag = 0;
		ret.minus_flag = 1;
	}
	return (ret);
}

t_spec	check_zero_flag(t_spec ret, char *mod_op_ptr, int i)
{
	if (i == 1 && mod_op_ptr[i] == '0')
		ret.zero_flag = 1;
	if (ret.minus_flag == 0 && mod_op_ptr[i] == '0'
		&& (mod_op_ptr[i - 1] == ' ' || mod_op_ptr[i - 1] == '+'
			|| mod_op_ptr[i - 1] == '#' ))
		ret.zero_flag = 1;
	return (ret);
}

t_spec	check_plus_flag(t_spec ret, char *mod_op_ptr, int i)
{
	if (i == 1 && mod_op_ptr[i] == '+')
		ret.plus_flag = 1;
	if (mod_op_ptr[i] == '+'
		&& (mod_op_ptr[i - 1] == '-' || mod_op_ptr[i - 1] == '0'
			|| mod_op_ptr[i - 1] == ' ' || mod_op_ptr[i - 1] == '#'))
	{
		if (ret.space_flag == 1)
			ret.space_flag = 0;
		ret.plus_flag = 1;
	}
	return (ret);
}

t_spec	check_space_flag(t_spec ret, char *mod_op_ptr, int i)
{
	if (i == 1 && mod_op_ptr[i] == ' ')
		ret.space_flag = 1;
	if (ret.plus_flag == 0 && mod_op_ptr[i] == '0'
		&& (mod_op_ptr[i - 1] == ' ' || mod_op_ptr[i - 1] == '+'
			|| mod_op_ptr[i - 1] == '#' ))
		ret.space_flag = 1;
	return (ret);
}

t_spec	check_sharp_flag(t_spec ret, char *mod_op_ptr, int i)
{
	if (i == 1 && mod_op_ptr[i] == '#')
		ret.sharp_flag = 2;
	if (mod_op_ptr[i] == '#'
		&& (mod_op_ptr[i - 1] == '-' || mod_op_ptr[i - 1] == '0'
			|| mod_op_ptr[i - 1] == '+' || mod_op_ptr[i - 1] == ' '))
		ret.sharp_flag = 2;
	return (ret);
}

t_spec	check_width(t_spec ret, char *mod_op_ptr, int i)
{
	if (mod_op_ptr[i] != '0' && ft_isdigit(mod_op_ptr[i])
		&& (mod_op_ptr[i - 1] == '-' || mod_op_ptr[i - 1] == ' '
			|| mod_op_ptr[i - 1] == '+' || mod_op_ptr[i - 1] == '#'
			|| mod_op_ptr[i - 1] == '%' || mod_op_ptr[i - 1] == '0'))
		ret.width = ft_atoi(&mod_op_ptr[i]);
	return (ret);
}

t_spec	check_precision(t_spec ret, char *mod_op_ptr, int i)
{
	if (mod_op_ptr[i] == '.')
	{
		if (ft_isdigit(mod_op_ptr[i + 1]))
			ret.precision = ft_atoi(&(mod_op_ptr[i + 1]));
		else
			ret.precision = 0;
	}
	return (ret);
}

t_spec	spec_init(void)
{
	t_spec	ret;

	ret.minus_flag = 0;
	ret.zero_flag = 0;
	ret.plus_flag = 0;
	ret.space_flag = 0;
	ret.sharp_flag = 0;
	ret.width = 0;
	ret.precision = 0;
	ret.len = 0;
	ret.specifier = 0;
	return (ret);
}

t_spec	spec_parsing(char *mod_op_ptr)
{
	int		i;
	t_spec	ret;

	ret = spec_init();
	i = 1;
	ret.specifier = mod_op_ptr[i];
	while (!is_specifier(ret.specifier))
	{
		ret = check_minus_flag(ret, mod_op_ptr, i);
		ret = check_zero_flag(ret, mod_op_ptr, i);
		ret = check_plus_flag(ret, mod_op_ptr, i);
		ret = check_space_flag(ret, mod_op_ptr, i);
		ret = check_sharp_flag(ret, mod_op_ptr, i);
		ret = check_width(ret, mod_op_ptr, i);
		ret = check_precision(ret, mod_op_ptr, i);
		ret.specifier = mod_op_ptr[++i];
	}
	ret.len = i + 1;
	return (ret);
}


// printf의 인수 str과 n을 인자로 받아 n번째 형식지정자의 정보를 포함한 구조체를 반환
t_spec	get_specifier_info(const char *str, int n) 
{
	int		i;
	char	*ptr;
	t_spec	ret;

	ret.specifier = 0;
	ptr = ft_strchr(str, '%');
	i = 1;
	while (ptr && i++ < n)
	{
		if (*(ptr + 1) == '%')
			ptr = ft_strchr(ptr + 2, '%');
		else
			ptr = ft_strchr(ptr + 1, '%');
	}
	i = 0;
	ret = spec_parsing(ptr);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	t_spec	spec_info;
	const char	*prev;
	const char	*cur;
	int		ret;
	va_list *ap;
	va_list sp;
	
	va_start(sp, str);
	ap = &sp;
	ret = str_validation(str);
	if (ret == -1)
		return (ret);
	i = 1;
	prev = str;
	cur = ft_strchr(str, '%');
	while (cur)
	{
		spec_info = get_specifier_info(str, i++);
		// write(1, "flag : ", 7);
		// if (spec_info.minus_flag == 1)
		// 	write(1, "-", 1);
		// if (spec_info.zero_flag == 1)
		// 	write(1, "0", 1);
		// if (spec_info.plus_flag == 1)
		// 	write(1, "+", 1);
		// if (spec_info.space_flag == 1)
		// 	write(1, " ", 1);
		// if (spec_info.sharp_flag == 2)
		// 	write(1, "#", 1);
		// printf(", width : %d, ", spec_info.width);
		// printf("precision : %d\n", spec_info.precision);
		write(1, prev, cur - prev);
		ret += call_dispenser(ap, spec_info) + (cur - prev);
		cur += spec_info.len;
		prev = cur;
		cur = ft_strchr(cur, '%');
	}
	write(1, prev, ft_strchr(str, '\0') - prev);
	ret += ft_strchr(str, '\0') - prev;
	return (ret);
}