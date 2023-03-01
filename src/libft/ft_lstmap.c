/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:19:29 by hunpark           #+#    #+#             */
/*   Updated: 2022/07/25 20:39:01 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*h;

	t = NULL;
	while (lst)
	{
		h = ft_lstnew(f(lst->content));
		if (!h)
		{
			ft_lstclear(&t, del);
			return (NULL);
		}
		ft_lstadd_back(&t, h);
		h = h->next;
		lst = lst->next;
	}
	return (t);
}
