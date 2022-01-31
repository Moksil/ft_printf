/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:03 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:03 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	d_handling(va_list *ap, t_spec s)
{
	int	d_val;
	int	arglen;
	int	sign;
	int	sign_space;

	d_val = va_arg(*ap, int);
	sign = 1;
	if (d_val < 0)
		sign = -1;
	sign_space = 0;
	if (sign == -1 || s.plus_flag || s.space_flag)
		sign_space = 1;
	arglen = get_nbr_length(sign * d_val);
	if (d_val == 0 && s.precision == 0)
		arglen = 0;
	if (s.minus_flag == 0)
		fadding_space(s, arglen, sign);
	fadding_zero(s, arglen, sign);
	if (!(d_val == 0 && s.precision == 0))
		put_nbr(sign * d_val);
	if (s.minus_flag == 1)
		fadding_space(s, arglen, sign);
	return (max_in_3_int(s.width, s.precision + sign_space
			, arglen + sign_space));
}
