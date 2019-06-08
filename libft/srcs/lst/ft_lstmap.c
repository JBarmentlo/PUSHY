/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:17:27 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/09 11:17:27 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*temp;
	t_list	*start;

	result = NULL;
	temp = (*f)(lst);
	if (!(result = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	start = result;
	lst = lst->next;
	while (lst != NULL)
	{
		temp = (*f)(lst);
		if (!(result->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		result = result->next;
		lst = lst->next;
	}
	return (start);
}
