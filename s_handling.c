/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:32 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:34 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_handling(va_list *ap, t_spec s)
{
	char	*s_ptr;
	int		arglen;

	s_ptr = va_arg(*ap, char *);
	if (s_ptr == NULL)
		s_ptr = "(null)";
	arglen = ft_strlen(s_ptr);
	if (s.precision != -1 && arglen > s.precision)
		arglen = s.precision;
	if (arglen < s.precision)
		s.precision = arglen;
	if (s.minus_flag == 0)
		fadding_space(s, arglen, 1);
	fadding_zero(s, arglen, 1);
	write(1, s_ptr, arglen);
	if (s.minus_flag == 1)
		fadding_space(s, arglen, 1);
	return (max_in_2_int(s.width, arglen));
}
