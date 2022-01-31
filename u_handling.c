/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:43 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:46 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_handling(va_list *ap, t_spec s)
{
	unsigned int	d_val;
	int				arglen;

	d_val = va_arg(*ap, int);
	arglen = get_unbr_length(d_val);
	if (d_val == 0 && s.precision == 0)
		arglen = 0;
	if (s.minus_flag == 0)
		fadding_space(s, arglen, 1);
	fadding_zero(s, arglen, 1);
	if (!(d_val == 0 && s.precision == 0))
		put_nbr_u(d_val);
	if (s.minus_flag == 1)
		fadding_space(s, arglen, 1);
	return (max_in_3_int(s.width, s.precision, arglen));
}
