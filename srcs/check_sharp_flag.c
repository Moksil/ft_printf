/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sharp_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:13:53 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:13:54 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_spec	check_sharp_flag(t_spec ret, char *mod_op_ptr, int i)
{
	if (i == 1 && mod_op_ptr[i] == '#')
		ret.sharp_flag = 2;
	if (mod_op_ptr[i] == '#'
		&& (mod_op_ptr[i - 1] == '-' || mod_op_ptr[i - 1] == '0'
			|| mod_op_ptr[i - 1] == '+' || mod_op_ptr[i - 1] == ' '
			|| ft_isdigit(mod_op_ptr[i - 1])))
		ret.sharp_flag = 2;
	return (ret);
}
