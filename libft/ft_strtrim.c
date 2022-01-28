/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:36:15 by sungmipa          #+#    #+#             */
/*   Updated: 2021/11/11 21:36:18 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_lpad(char const *s1, char const *set)
{
	int	i;
	int	l_pad;

	i = 0;
	l_pad = 0;
	while (s1[l_pad])
	{
		while (set[i] && s1[l_pad] != set[i])
			i++;
		if (!set[i])
			break ;
		l_pad++;
		i = 0;
	}
	return (l_pad);
}

static int	calc_rpad(char const *s1, char const *set)
{
	int	i;
	int	r_pad;
	int	s1_len;

	i = 0;
	r_pad = 0;
	s1_len = ft_strlen(s1);
	while (s1[r_pad])
	{
		while (set[i] && s1[s1_len - 1 - r_pad] != set[i])
			i++;
		if (!set[i])
			break ;
		r_pad++;
		i = 0;
	}
	return (r_pad);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		l_pad;
	int		r_pad;
	char	*trimed_str;

	l_pad = calc_lpad(s1, set);
	r_pad = calc_rpad(s1, set);
	if (ft_strlen(s1) == (size_t)l_pad)
	{
		trimed_str = (char *)malloc(1);
		if (trimed_str == NULL)
			return (NULL);
		trimed_str[0] = '\0';
		return (trimed_str);
	}
	trimed_str = (char *)malloc(ft_strlen(s1) - (l_pad + r_pad) + 1);
	if (trimed_str == NULL)
		return (NULL);
	i = -1;
	while (++i < (int)(ft_strlen(s1) - (l_pad + r_pad)))
		trimed_str[i] = s1[l_pad + i];
	trimed_str[ft_strlen(s1) - (l_pad + r_pad)] = '\0';
	return (trimed_str);
}
