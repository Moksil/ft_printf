/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 23:47:15 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/07 17:46:33 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			cnt++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (i > 0 && s[i - 1] != c)
		cnt++;
	return (cnt);
}

static char	**free_ret(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		ret[i] = NULL;
		i++;
	}
	free(ret);
	ret = NULL;
	return (NULL);
}

static char	**split(char **ret, const char *s, char c)
{
	int			i;
	int			j;
	const char	*ptr;

	i = 0;
	j = 0;
	ptr = s;
	while (s[j])
	{
		if (j != 0 && (s[j] != c) && (s[j - 1] == c))
			ptr = &s[j];
		if (s[j] != c && ((s[j + 1] == '\0') || (s[j + 1] == c)))
		{
			ret[i] = (char *)malloc(&s[j] - ptr + 2);
			if (ret[i] == NULL)
				return (free_ret(ret));
			ft_memcpy(ret[i], ptr, &s[j] - ptr + 1);
			ret[i++][&s[j] - ptr + 1] = '\0';
		}
		j++;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		n_of_word;
	char	**ret;

	if (*s == 0)
	{
		ret = (char **)malloc(sizeof(char *));
		if (ret == NULL)
			return (NULL);
		ret[0] = NULL;
		return (ret);
	}
	n_of_word = count_word(s, c);
	ret = (char **)malloc(sizeof(char *) * (n_of_word + 1));
	if (ret == NULL)
		return (NULL);
	ret[n_of_word] = NULL;
	return (split(ret, s, c));
}	
