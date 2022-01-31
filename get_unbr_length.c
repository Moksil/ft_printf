/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unbr_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:34:11 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 01:34:12 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_unbr_length(unsigned int n)
{
	int		ret;

	ret = 1;
	if (n < 10)
		return (1);
	else
		ret += get_unbr_length(n / 10);
	return (ret);
}
