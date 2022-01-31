/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:13:55 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:13:56 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	check_space_flag(t_spec ret, char *mod_op_ptr, int i)
{
	if (i == 1 && mod_op_ptr[i] == ' ')
		ret.space_flag = 1;
	if (ret.plus_flag == 0 && mod_op_ptr[i] == ' '
		&& (mod_op_ptr[i - 1] == '-' || mod_op_ptr[i - 1] == '0'
			|| mod_op_ptr[i - 1] == '#' || ft_isdigit(mod_op_ptr[i - 1])))
		ret.space_flag = 1;
	return (ret);
}
