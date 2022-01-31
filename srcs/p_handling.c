/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:28 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:30 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	p_handling(va_list *ap, t_spec s)
{
	void	*p_ptr;
	int		arglen;

	p_ptr = va_arg(*ap, void *);
	arglen = get_hexa_len_long((long)p_ptr);
	if (p_ptr == NULL && s.precision == 0)
		arglen = 0;
	if (s.minus_flag == 0)
		fadding_space(s, arglen, 1);
	write(1, "0x", 2);
	fadding_zero(s, arglen, 1);
	if (!(p_ptr == NULL && s.precision == 0))
		put_hexa_from_long((long)p_ptr, 'x');
	if (s.minus_flag == 1)
		fadding_space(s, arglen, 1);
	return (max_in_3_int(s.width, s.precision + 2, arglen + 2));
}
