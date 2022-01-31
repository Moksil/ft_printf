/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_op_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:23 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:27 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mod_op_handling(t_spec s)
{
	char	mod_op;
	int		arglen;

	mod_op = '%';
	s.precision = -1;
	arglen = 1;
	if (s.minus_flag == 0)
		fadding_space(s, arglen, 1);
	fadding_zero(s, arglen, 1);
	write(1, &mod_op, arglen);
	if (s.minus_flag == 1)
		fadding_space(s, arglen, 1);
	return (max_in_3_int(s.width, s.precision, arglen));
}
