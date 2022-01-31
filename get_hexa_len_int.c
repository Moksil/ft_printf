/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hexa_len_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:33:45 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/31 01:33:52 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_hexa_len_int(unsigned int nbr)
{
	int		ret;

	ret = 1;
	if (nbr < 0)
		ret += get_hexa_len_int(0xFFFFFFFF + nbr + 1) - 1;
	if (nbr < 16)
		return (1);
	else
		ret += get_hexa_len_int(nbr / 16);
	return(ret);
}
