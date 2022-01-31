/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:40 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:42 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_validation(const char *str)
{
	const char		*mod_op_ptr;
	const char		*spec_ptr;

	mod_op_ptr = ft_strchr(str, '%');
	while (mod_op_ptr)
	{
		spec_ptr = get_valid_spec(mod_op_ptr);
		if (spec_ptr == NULL)
			return (-1);
		if (*spec_ptr == '%')
			spec_ptr++;
		mod_op_ptr = ft_strchr(spec_ptr, '%');
	}
	return (0);
}
