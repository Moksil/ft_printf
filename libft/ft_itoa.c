/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:36:15 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/02 14:49:57 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_digit(int n)
{
	int	digit;

	digit = 1;
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit - 1);
}

static char	*handle_negnbr(int n)
{
	int		digit;
	char	*ret;

	if (n == -2147483648)
	{
		ret = ft_strdup("-2147483648");
		return (ret);
	}
	digit = calc_digit(-n);
	ret = (char *)malloc(digit + 1 + 1);
	if (ret == NULL)
		return (NULL);
	ret[digit + 1] = '\0';
	ret[0] = '-';
	n *= -1;
	while (n > 0)
	{
		ret[digit] = '0' + (n % 10);
		n /= 10;
		digit--;
	}
	return (ret);
}

static char	*handle_zero(void)
{
	char	*ret;

	ret = ft_strdup("0");
	return (ret);
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*ret;

	if (n == 0)
		return (handle_zero());
	else if (n < 0)
		return (handle_negnbr(n));
	digit = calc_digit(n);
	ret = (char *)malloc(digit + 1);
	if (ret == NULL)
		return (NULL);
	ret[digit] = '\0';
	while (n > 0)
	{
		ret[digit - 1] = '0' + (n % 10);
		n /= 10;
		digit--;
	}
	return (ret);
}
