/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynlist_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:33:27 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/04 16:33:27 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynlist.h"
#include <stdlib.h>

static t_dynit	*ft_getnode(t_dynit *prev, void *next)
{
	t_dynit	*node;

	if (!(node = (t_dynit*)malloc(sizeof(t_dynit))))
		return (NULL);
	node->current = next;
	node->next = NULL;
	node->prev = prev;
	if (prev != NULL)
		prev->next = node;
	return (node);
}

void			ft_dynlist_pushfront(t_dynlist *list, void *item)
{
	t_dynit	*node;

	node = ft_getnode(NULL, item);
	if (list->first != NULL)
	{
		list->first->prev = node;
		node->next = list->first;
	}
	else
		list->last = node;
	list->first = node;
	list->size += 1;
}

void			ft_dynlist_pushback(t_dynlist *list, void *item)
{
	t_dynit	*node;

	if (list->last == NULL)
		return (ft_dynlist_pushfront(list, item));
	node = ft_getnode(list->last, item);
	list->last = node;
	list->size += 1;
}
