/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fadding_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:11 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:14 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	fadding_zero(t_spec s, int arglen, int sign)
{
	int	i;
	int	sign_space;

	sign_space = 0;
	if (sign == -1 || s.plus_flag || s.space_flag)
		sign_space = 1;
	if (sign == -1)
		write(1, "-", 1);
	else if (s.plus_flag)
		write(1, "+", 1);
	else if (s.space_flag)
		write(1, " ", 1);
	i = 0;
	if (s.zero_flag)
		while (i++ < s.width - max_in_2_int(s.precision, arglen) - sign_space)
			write(1, "0", 1);
	i = 0;
	if (s.precision > arglen)
	{
		while (i++ < s.precision - arglen)
			write(1, "0", 1);
	}
}
