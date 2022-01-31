/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_x_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:21 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:22 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	lower_x_handling(va_list *ap, t_spec s)
{
	int		int_val;
	int		arglen;

	int_val = va_arg(*ap, int);
	arglen = get_hexa_len_int(int_val);
	if (int_val == 0)
		s.sharp_flag = 0;
	if (int_val == 0 && s.precision == 0)
		arglen = 0;
	if (s.minus_flag == 0)
		fadding_space(s, arglen, 1);
	fadding_zero(s, arglen, 1);
	if (s.sharp_flag)
		write(1, "0x", 2);
	if (!(s.precision == 0 && int_val == 0))
		put_hexa_from_int(int_val, 'x');
	if (s.minus_flag == 1)
		fadding_space(s, arglen, 1);
	return (max_in_3_int(s.width, s.precision, arglen) + s.sharp_flag);
}
