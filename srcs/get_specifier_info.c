/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:15 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 18:14:17 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	get_specifier_info(const char *str, int n)
{
	int		i;
	char	*ptr;
	t_spec	ret;

	ret.specifier = 0;
	ptr = ft_strchr(str, '%');
	i = 1;
	while (ptr && i++ < n)
	{
		if (*(ptr + 1) == '%')
			ptr = ft_strchr(ptr + 2, '%');
		else
			ptr = ft_strchr(ptr + 1, '%');
	}
	i = 0;
	ret = spec_parsing(ptr);
	return (ret);
}
