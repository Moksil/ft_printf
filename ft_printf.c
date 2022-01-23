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

t_spec	get_specifier(const char *str, int n)
{
	int	i;
	char *ptr;
	t_spec ret;

	ret.s_ptr = NULL;
	ret.specifier = 0;
	i = 0;
	ptr = ft_strchr(str, '%');
	while (ptr)
	{
		ptr++;
		i++;
		if (i == n)
			break;
		ptr = ft_strchr(ptr, '%');
		ret.specifier = *(ptr);
		ret.s_ptr = ptr - 1;
	}
	return (ret);
}

int	specified_call(va_list ap, char specifier)
{
	int size;

	if (specifier == 'd')
		return (d_handling(ap));
}

int	d_handling(va_list ap)
{
	int		int_val;
	int		size;
	char	*val_to_str;

	int_val = va_arg(ap, int);
	val_to_str = ft_itoa(int_val);
	size = sizeof(val_to_str);
	write(1, val_to_str, size);
	free(val_to_str);
	return (size);
}


int	ft_printf(const char *str, ...)
{
	t_spec	spec_set;
	char	*val_to_str;
	int		int_val;
	int		size;
	int		i;

	spec_set.specifier = 0;
	spec_set.s_ptr = NULL;
	va_list ap;
	va_start(ap, str);
	i = 1;
	while (spec_set.s_ptr != get_specifier(str, i).s_ptr)
	{
		spec_set = get_specifier(str, i++);
		write(1, str, spec_set.s_ptr - str);
		size += spec_set.s_ptr - str;
		str += spec_set.s_ptr - str;
		size += specified_call(ap, spec_set.specifier);
	}
	// if (spec_set.specifier == 'd')
	// {
	// 	int_val = va_arg(ap, int);
	// 	val_to_str = ft_itoa(int_val);
	// 	write(1, val_to_str, sizeof(val_to_str));
	// 	free(val_to_str);
	// }

	va_end(ap);
	return (0);
}