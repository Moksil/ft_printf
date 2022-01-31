/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_handling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:13:26 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:13:31 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_handling(va_list *ap, t_spec s)
{
	char	ch_val;
	int		arglen;

	ch_val = va_arg(*ap, int);
	arglen = 1;
	if (s.minus_flag == 0)
		fadding_space(s, arglen, 1);
	fadding_zero(s, arglen, 1);
	ft_putchar_fd(ch_val, 1);
	if (s.minus_flag == 1)
		fadding_space(s, arglen, 1);
	return (max_in_3_int(s.width, s.precision, arglen));
}
