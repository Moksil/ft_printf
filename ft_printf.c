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
	if (c == '%' || c == 's' || c == 'p' ||	c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
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

char	*ptr_to_spec_str(char *ptr)
{
	int		i;
	char	*spec_str;
	
	spec_str = NULL;
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
		spec_str = ft_strndup(ptr, i + 1);
	return (spec_str);
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
	ptr = ptr_to_spec_str(ptr);
	if (ptr)
		ret = str_to_struct(ptr);
	free(ptr);
	return (ret);
}



int	d_handling(va_list* ap)
{
	int		int_val;
	int		str_size;
	char	*val_to_str;

	int_val = va_arg(*ap, int);
	val_to_str = ft_itoa(int_val);
	str_size = ft_strlen(val_to_str);
	write(1, val_to_str, str_size);
	free(val_to_str);
	return (str_size);
}

// int	s_handling(va_list* ap)
// {
// 	int		int_val;
// 	int		str_size;
// 	char	*val_to_str;

// 	int_val = va_arg(*ap, int);
// 	val_to_str = ft_itoa(int_val);
// 	str_size = ft_strlen(val_to_str);
// 	write(1, val_to_str, str_size);
// 	free(val_to_str);
// 	return (str_size);
// }

int	specified_call(va_list* ap, char specifier)
{
	int ret;
	if (specifier == 'd')
		ret = d_handling(ap);
	else
		ret = 0;
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	t_spec	spec_info;
	const char	*prev;
	const char	*cur;
	int		i;
	int		ret;
	va_list *ap;
	va_list sp;

	va_start(sp, str);
	ap = &sp;
	ret = 0;
	i = 1;
	prev = str;
	cur = ft_strchr(str, '%');
	while (cur)
	{
		spec_info = get_specifier_info(str, i++);
		write(1, prev, cur - prev);
		ret += specified_call(ap, spec_info.specifier) + (cur - prev);
		cur += spec_info.len;
		prev = cur;
		cur = ft_strchr(cur, '%');
	}
	write(1, prev, ft_strchr(str, '\0') - prev);
	ret += ft_strchr(str, '\0') - prev;
	return (ret);
	// spec_set.specifier = 0;
	// spec_set.s_ptr = NULL;
	// va_list ap;
	// va_start(ap, str);
	// i = 1;
	// while (spec_set.s_ptr != get_specifier(str, i).s_ptr)
	// {
		// spec_set = get_specifier(str, i++);
		// write(1, str, spec_set.s_ptr - str);
		// size += spec_set.s_ptr - str;
		// str += spec_set.s_ptr - str;
		// size += specified_call(ap, spec_set.specifier);
	// }
	// if (spec_set.specifier == 'd')
	// {
	// 	int_val = va_arg(ap, int);
	// 	val_to_str = ft_itoa(int_val);
	// 	write(1, val_to_str, sizeof(val_to_str));
	// 	free(val_to_str);
	// }

	// va_end(ap);
}