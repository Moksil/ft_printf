/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:38 by sungmipa          #+#    #+#             */
/*   Updated: 2021/11/24 18:37:45 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*cur;

	ret = (t_list *)malloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	cur = ret;
	while (lst)
	{
		cur -> content = f(lst -> content);
		cur -> next = NULL;
		if (lst -> next)
		{
			cur -> next = (t_list *)malloc(sizeof(t_list));
			if (cur -> next == NULL)
			{
				ft_lstclear(&ret, del);
				return (NULL);
			}
		}
		cur = cur -> next;
		lst = lst -> next;
	}
	return (ret);
}
