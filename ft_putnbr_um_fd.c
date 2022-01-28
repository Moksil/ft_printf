/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_um_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:43:56 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/28 14:43:58 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_um_fd(unsigned int n, int fd)
{
	int		ret;

	ret = 1;
	if (n < 10)
	{
		ft_putchar_fd('0' + n, fd);
		return (1);
	}
	else
	{
		ret += ft_putnbr_um_fd(n / 10, fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
	return (ret);
}
