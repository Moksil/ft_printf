/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:13:59 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:13:59 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_spec	check_width(t_spec ret, char *mod_op_ptr, int i)
{
	char	*ptr;

	if (mod_op_ptr[i] != '0' && ft_isdigit(mod_op_ptr[i])
		&& (mod_op_ptr[i - 1] == '-' || mod_op_ptr[i - 1] == ' '
			|| mod_op_ptr[i - 1] == '+' || mod_op_ptr[i - 1] == '#'
			|| mod_op_ptr[i - 1] == '%' || mod_op_ptr[i - 1] == '0'))
	{
		ptr = &mod_op_ptr[i];
		while (ft_isdigit(*ptr))
			ptr--;
		if (*ptr == '.')
			return (ret);
		ret.width = ft_atoi(&mod_op_ptr[i]);
	}
	return (ret);
}
