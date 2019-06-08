/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynlist_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:31:26 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/04 16:31:26 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynlist.h"
#include <stdlib.h>

t_dynlist	*ft_dynlist_create(void)
{
	t_dynlist	*result;

	if (!(result = (t_dynlist*)malloc(sizeof(t_dynlist))))
		return (NULL);
	result->first = NULL;
	result->last = NULL;
	result->it = NULL;
	result->size = 0;
	return (result);
}

void		ft_dynlist_free(t_dynlist *list, void (*free_content)(void*))
{
	t_dynit	*it;
	t_dynit	*tmp;

	it = list->first;
	while (it != NULL)
	{
		tmp = it->next;
		if (free_content != NULL)
			(*free_content)(it->current);
		free(it);
		it = tmp;
	}
	free(list);
}
