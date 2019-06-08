/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynlist_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:47:25 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/04 16:47:25 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynlist.h"
#include <stdlib.h>

static t_dynit	*ft_getnode(t_dynit *prev, void *current, t_dynit *next)
{
	t_dynit	*node;

	if (!(node = (t_dynit*)malloc(sizeof(t_dynit))))
		return (NULL);
	node->current = current;
	node->next = next;
	node->prev = prev;
	if (prev != NULL)
		prev->next = node;
	if (next != NULL)
		next->prev = node;
	return (node);
}

static t_dynit	*ft_getit(t_dynlist *list, void *item)
{
	t_dynit	*it;

	if (item == NULL)
		return (NULL);
	it = list->first;
	while (it->current != item && it != NULL)
		it = it->next;
	return (it);
}

void			ft_dynlist_insertafter(t_dynlist *list, void *item, void *after)
{
	t_dynit	*it;
	t_dynit	*node;

	it = ft_getit(list, after);
	if (it == NULL)
		return ;
	node = ft_getnode(it, item, it->next);
	if (node->prev == list->last)
		list->last = node;
	list->size += 1;
}

void			ft_dynlist_insertbefore(t_dynlist *list, void *item,
	void *before)
{
	t_dynit	*it;
	t_dynit	*node;

	it = ft_getit(list, before);
	if (it == NULL)
		return ;
	node = ft_getnode(it->prev, item, it);
	if (node->next == list->first)
		list->first = node;
	list->size += 1;
}

void			ft_dynlist_insertat(t_dynlist *list, void *item, int index)
{
	t_dynit	*node;
	t_dynit	*it;

	if (index == 0)
		return (ft_dynlist_pushfront(list, item));
	if (index == (int)list->size)
		return (ft_dynlist_pushback(list, item));
	it = list->first;
	while (it != NULL && index-- > 0)
		it = it->next;
	if (it == NULL)
		return ;
	node = ft_getnode(it->prev, item, it);
	list->size += 1;
}
