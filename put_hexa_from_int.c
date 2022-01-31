/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexa_from_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:34:21 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 01:34:22 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hexa_from_int(unsigned int nbr, char flag)
{
	char	*base;

	if (flag == 'x')
		base = "0123456789abcdef";
	if (flag == 'X')
		base = "0123456789ABCDEF";
	if (nbr < 0)
		put_hexa_from_int(0xFFFFFFFF + nbr + 1, flag);
	if (nbr < 16)
		write(1, &base[nbr % 16], 1);
	else
	{
		put_hexa_from_int(nbr / 16, flag);
		write(1, &base[nbr % 16], 1);
	}
}
