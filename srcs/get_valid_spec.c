/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:19 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:20 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

const char	*get_valid_spec(const char *mod_op_ptr)
{
	int			i;
	const char	*spec_ptr;

	i = 0;
	spec_ptr = mod_op_ptr;
	while (mod_op_ptr && *(++spec_ptr))
	{
		if (is_flag(*spec_ptr))
			continue ;
		if (ft_isdigit(*spec_ptr))
			continue ;
		if (is_specifier(*spec_ptr))
			break ;
		break ;
	}
	if (mod_op_ptr && is_specifier(*spec_ptr))
		return (spec_ptr);
	return (NULL);
}
