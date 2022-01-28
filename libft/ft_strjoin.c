/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:36:15 by sungmipa          #+#    #+#             */
/*   Updated: 2021/11/16 15:43:49 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*joined_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = (char *)malloc(s1_len + s2_len + 1);
	if (joined_str == NULL)
		return (NULL);
	joined_str[s1_len + s2_len] = '\0';
	i = -1;
	while (++i < s1_len)
		joined_str[i] = s1[i];
	i = -1;
	while (++i <= s2_len)
		joined_str[s1_len + i] = s2[i];
	return (joined_str);
}
