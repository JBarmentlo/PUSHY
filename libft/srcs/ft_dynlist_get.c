/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynlist_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:12:26 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/04 17:12:26 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynlist.h"

void		*ft_dynlist_get(t_dynlist *list, int index)
{
	t_dynit	*it;

	it = list->first;
	while (it != NULL && index-- > 0)
		it = it->next;
	if (it == NULL)
		return (NULL);
	return (it->current);
}
