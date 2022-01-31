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

int	ft_printf(const char *str, ...)
{
	int i;
	t_spec	spec_info;
	const char	*prev;
	const char	*cur;
	int		ret;
	va_list *ap;
	va_list sp;
	
	i = 1;
	va_start(sp, str);
	ap = &sp;
	ret = str_validation(str);
	if (ret == -1)
		return (ret);
	prev = str;
	cur = ft_strchr(str, '%');
	while (cur)
	{
		spec_info = get_specifier_info(str, i++);
		// write(1, "flag : ", 8);
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