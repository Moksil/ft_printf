/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:36:15 by sungmipa          #+#    #+#             */
/*   Updated: 2021/11/11 21:36:18 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (ft_strlen(s) <= start)
	{
		ret = (char *)malloc(1);
		if (ret == NULL)
			return (NULL);
		ret[0] = '\0';
	}
	else if (ft_strlen(s) - start < len)
	{
		ret = (char *)malloc(ft_strlen(s) - start + 1);
		if (ret == NULL)
			return (NULL);
		ft_strlcpy(ret, &s[start], ft_strlen(s) - start + 1);
	}
	else
	{
		ret = (char *)malloc(len + 1);
		if (ret == NULL)
			return (NULL);
		ft_strlcpy(ret, &s[start], len + 1);
	}
	return (ret);
}
