/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:34:31 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 01:34:32 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	put_nbr_u(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd('0' + n, 1);
	else
	{
		put_nbr_u(n / 10);
		ft_putchar_fd('0' + (n % 10), 1);
	}
}
