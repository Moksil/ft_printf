/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:36:13 by sungmipa          #+#    #+#             */
/*   Updated: 2021/11/24 18:36:35 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*cur;

	cur = *lst;
	if (cur == NULL)
		*lst = new_node;
	else
	{
		while (cur -> next)
			cur = cur -> next;
		cur -> next = new_node;
	}
}
