/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:51:57 by sungmipa          #+#    #+#             */
/*   Updated: 2021/11/20 00:52:03 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LONGLONG_MAX 9223372036854775807

static int	char_prop(char ch)
{
	if (ch == '-')
		return (-1);
	else if (ch == '+')
		return (1);
	else if (ch >= '0' && ch <= '9')
		return (2);
	else if (ch == ' ' || ch == '\t' || ch == '\n'
		|| ch == '\v' || ch == '\f' || ch == '\r')
		return (-2);
	else
		return (0);
}

static int	ft_abs(int nbr)
{
	if (nbr > 0)
		return (nbr);
	else
		return (-1 * nbr);
}

static int	check_out_of_range(int sign, unsigned long long ret)
{
	if (sign == 1 && ret > LONGLONG_MAX)
		return (-1);
	else if (sign == -1 && ret - 1 > LONGLONG_MAX)
		return (0);
	else
		return (sign * ret);
}

int	ft_atoi(const char *nptr)
{
	int					i;
	int					sign;
	unsigned long long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (char_prop(nptr[i]) == -2)
		i++;
	if (ft_abs(char_prop(nptr[i])) == 1)
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (char_prop(nptr[i]) != 2)
		return (0);
	while (char_prop(nptr[i]) == 2)
	{
		ret = (ret * 10) + (nptr[i] - '0');
		i++;
	}
	return (check_out_of_range(sign, ret));
}
