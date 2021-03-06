/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:54:27 by sungmipa          #+#    #+#             */
/*   Updated: 2021/11/11 17:54:47 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *)(haystack));
	while (haystack[i] && (i < len))
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (i + j < len))
		{
			j++;
			if (!needle[j])
				return ((char *)(&haystack[i]));
		}
		i++;
	}
	return (NULL);
}
