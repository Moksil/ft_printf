/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hexa_len_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:33:58 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 01:34:00 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_hexa_len_long(unsigned long nbr)
{
	unsigned long	ret;

	ret = 1;
	if (nbr < 16)
		return (1);
	else
		ret += get_hexa_len_long(nbr / 16);
	return (ret);
}
