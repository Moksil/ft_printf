/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:31:36 by sungmipa          #+#    #+#             */
/*   Updated: 2021/11/08 23:31:42 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*sptr = s;

	i = 0;
	while (i < n)
	{
		if (sptr[i] == (unsigned char)c)
			return ((void *)(&sptr[i]));
		i++;
	}
	return (NULL);
}
