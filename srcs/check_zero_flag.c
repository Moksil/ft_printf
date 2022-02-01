/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:01 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:01 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_spec	check_zero_flag(t_spec ret, char *mod_op_ptr, int i)
{
	char	s;

	s = *(get_valid_spec(mod_op_ptr));
	if (i == 1 && mod_op_ptr[i] == '0')
		ret.zero_flag = 1;
	if (ret.minus_flag == 0 && mod_op_ptr[i] == '0'
		&& (ret.precision == -1 || (s == '%' || s == 'c' || s == 's'))
		&& (mod_op_ptr[i - 1] == ' ' || mod_op_ptr[i - 1] == '+'
			|| mod_op_ptr[i - 1] == '#'))
		ret.zero_flag = 1;
	return (ret);
}
