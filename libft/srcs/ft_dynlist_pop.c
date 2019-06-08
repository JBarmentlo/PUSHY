/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynlist_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:24:22 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/04 17:24:22 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynlist.h"
#include <stdlib.h>

void		*ft_pop_node(t_dynlist *list, t_dynit *node)
{
	void	*content;

	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	if (node == list->first)
		list->first = node->next;
	if (node == list->last)
		list->last = node->prev;
	content = node->current;
	list->size -= 1;
	free(node);
	return (content);
}

void		*ft_dynlist_popitem(t_dynlist *list, void *item)
{
	t_dynit	*it;

	it = list->first;
	while (it->current != item && it != NULL)
		it = it->next;
	if (it == NULL)
		return (NULL);
	return (ft_pop_node(list, it));
}

void		*ft_dynlist_popindex(t_dynlist *list, int index)
{
	t_dynit	*it;

	it = list->first;
	while (it != NULL && index-- > 0)
		it = it->next;
	if (it == NULL)
		return (NULL);
	return (ft_pop_node(list, it));
}
