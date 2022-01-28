/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:31:36 by sungmipa          #+#    #+#             */
/*   Updated: 2021/11/08 23:31:42 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dptr;
	const unsigned char	*sptr;

	if (!dest && !src)
		return (NULL);
	dptr = dest;
	sptr = src;
	i = -1;
	if (dest < src)
	{
		while (++i < n)
			dptr[i] = sptr[i];
	}
	else if (src < dest)
	{
		while (++i < n)
			dptr[n - 1 - i] = sptr[n - 1 - i];
	}
	return (dest);
}
