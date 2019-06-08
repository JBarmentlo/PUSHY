/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynlist_contains.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:20:40 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/04 17:20:40 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynlist.h"

int		ft_dynlist_indexof(t_dynlist *list, void *item)
{
	t_dynit	*it;
	int		index;

	index = 0;
	it = list->first;
	while (it->current != item && it != NULL)
	{
		index++;
		it = it->next;
	}
	if (it == NULL)
		return (-1);
	return (index);
}

int		ft_dynlist_contains(t_dynlist *list, void *item)
{
	return (ft_dynlist_indexof(list, item) >= 0);
}
