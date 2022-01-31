/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_dispenser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:13:34 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:13:35 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	call_dispenser(va_list* ap, t_spec s)
{
	int ret;
	if (s.specifier == '%')
		ret = mod_op_handling(s);
	else if (s.specifier == 'd' || s.specifier == 'D' || s.specifier == 'i')
		ret = d_handling(ap, s);
	else if (s.specifier == 'c' || s.specifier == 'C')
		ret = c_handling(ap, s);
	else if (s.specifier == 's')
		ret = s_handling(ap, s);
	else if (s.specifier == 'p')
		ret = p_handling(ap, s);
	else if (s.specifier == 'u' || s.specifier == 'U')
		ret = u_handling(ap, s);
	else if (s.specifier == 'x')
		ret = lower_x_handling(ap, s);
	else if (s.specifier == 'X')
		ret = upper_x_handling(ap, s);
	else
		ret = 0;
	return (ret);
}
