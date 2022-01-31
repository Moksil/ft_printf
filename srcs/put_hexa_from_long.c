/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexa_from_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:34:23 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 01:34:24 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	put_hexa_from_long(unsigned long nbr, char flag)
{
	char	*base;

	if (flag == 'x')
		base = "0123456789abcdef";
	if (flag == 'X')
		base = "0123456789ABCDEF";
	if (nbr < 16)
		write(1, &base[nbr % 16], 1);
	else
	{
		put_hexa_from_long(nbr / 16, flag);
		write(1, &base[nbr % 16], 1);
	}
}
