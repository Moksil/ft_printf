/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:35 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:36 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_spec	spec_init(void)
{
	t_spec	ret;

	ret.minus_flag = 0;
	ret.zero_flag = 0;
	ret.plus_flag = 0;
	ret.space_flag = 0;
	ret.sharp_flag = 0;
	ret.width = 0;
	ret.precision = -1;
	ret.len = 0;
	ret.specifier = 0;
	return (ret);
}
