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
	}
	if (ptr)
	{
		ret.specifier = *(ptr);
		ret.s_ptr = ptr - 1;
	}
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	t_spec	spec_set;
	char	*val_to_str;
	int		int_val;

	spec_set.specifier = 0;
	va_list ap;
	va_start(ap, str);
	spec_set = get_specifier(str, 1);
	write(1, str, spec_set.s_ptr - str);
	if (spec_set.specifier == 'd')
	{
		int_val = va_arg(ap, int);
		val_to_str = ft_itoa(int_val);
		write(1, val_to_str, sizeof(val_to_str));
		free(val_to_str);
	}

	va_end(ap);
	return (0);
}