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

static int	printer(const char *str, va_list *ap)
{
	t_spec		spec_info;
	const char	*prev;
	const char	*cur;
	int			ret;
	int			i;

	ret = 0;
	prev = str;
	cur = ft_strchr(str, '%');
	i = 1;
	while (cur)
	{
		spec_info = get_specifier_info(str, i++);
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

int	ft_printf(const char *str, ...)
{
	int		ret;
	va_list	*ap;
	va_list	sp;

	va_start(sp, str);
	ap = &sp;
	ret = str_validation(str);
	if (ret == -1)
		return (ret);
	return (printer(str, ap));
}
