/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_m_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:43:52 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/28 14:43:53 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_m_fd(int n, int fd)
{
	int		ret;

	ret = 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ret += ft_putnbr_m_fd((-1) * n, fd);
	}
	else if (n < 10)
	{
		ft_putchar_fd('0' + n, fd);
		return (1);
	}
	else
	{
		ret += ft_putnbr_m_fd(n / 10, fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
	return (ret);
}
