/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fadding_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:05 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:09 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void fadding_space(t_spec s, int arglen, int sign)
{
	int	i;
	int	sign_space;
	int sharp_flag_space;

	sharp_flag_space = 0;
	if (s.specifier == 'p'
		||(s.sharp_flag && (s.specifier == 'x' || s.specifier == 'X')))
		sharp_flag_space = 2;
	sign_space = 0;
	if (sign == -1 || s.plus_flag || s.space_flag)
		sign_space = 1;
	i = 0;
	if (max_in_3_int(s.width, s.precision, arglen) == s.width && !s.zero_flag)
	{ 
		while(i++ < s.width - max_in_2_int(s.precision, arglen) - sign_space
			- sharp_flag_space)
			write(1, " ", 1);
	}
}
