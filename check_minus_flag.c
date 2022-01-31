/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minus_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:13:45 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:13:47 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	check_minus_flag(t_spec ret, char *mod_op_ptr, int i)
{
	if (i == 1 && mod_op_ptr[i] == '-')
		ret.minus_flag = 1;
	if (mod_op_ptr[i] == '-'
		&& (mod_op_ptr[i - 1] == '0' || mod_op_ptr[i - 1] == ' '
			|| mod_op_ptr[i - 1] == '+' || mod_op_ptr[i - 1] == '#' 
			|| ft_isdigit(mod_op_ptr[i - 1])))
	{
		if (ret.zero_flag == 1)
			ret.zero_flag = 0;
		ret.minus_flag = 1;
	}
	return (ret);
}
