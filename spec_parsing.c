/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:37 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:37 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	spec_parsing(char *mod_op_ptr)
{
	int		i;
	t_spec	ret;

	ret = spec_init();
	i = 1;
	ret.specifier = mod_op_ptr[i];
	while (!is_specifier(ret.specifier))
	{
		ret = check_minus_flag(ret, mod_op_ptr, i);
		ret = check_zero_flag(ret, mod_op_ptr, i);
		ret = check_plus_flag(ret, mod_op_ptr, i);
		ret = check_space_flag(ret, mod_op_ptr, i);
		ret = check_sharp_flag(ret, mod_op_ptr, i);
		ret = check_width(ret, mod_op_ptr, i);
		ret = check_precision(ret, mod_op_ptr, i);
		ret.specifier = mod_op_ptr[++i];
	}
	ret.len = i + 1;
	return (ret);
}
