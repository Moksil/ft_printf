/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:13:51 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:13:51 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_spec	check_precision(t_spec ret, char *mod_op_ptr, int i)
{
	char	specifier;

	specifier = *(get_valid_spec(mod_op_ptr));
	if (mod_op_ptr[i] == '.' && mod_op_ptr[i + 1] != '\0')
	{
		if (ft_isdigit(mod_op_ptr[i + 1]))
		{
			ret.precision = ft_atoi(&(mod_op_ptr[i + 1]));
			if (specifier != '%' && specifier != 'c' && specifier != 's')
				ret.zero_flag = 0;
		}
		else
		{
			ret.precision = 0;
			if (specifier != '%' && specifier != 'c' && specifier != 's')
				ret.zero_flag = 0;
		}
	}
	return (ret);
}
