/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:34:04 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 01:34:05 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_nbr_length(int n)
{
	int		ret;

	ret = 1;
	if (n == -2147483648)
		return (10);
	else if (n < 0)
		ret += get_nbr_length((-1) * n);
	else if (n < 10)
		return (1);
	else
		ret += get_nbr_length(n / 10);
	return (ret);
}
