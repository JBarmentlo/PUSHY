/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:07 by jbarment          #+#    #+#             */
/*   Updated: 2019/06/08 18:17:30 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdlib.h>

void	pf_list(t_op_list **start, void (*ff)(t_s*, t_end_list**))
{
	t_op_list	*node;

	node = (t_op_list*)malloco(sizeof(t_op_list));
	node->f = (*ff);
	node->next = *start;
	*start = node;
}

void	apply_list(t_op_list **start, t_s *sys, t_end_list **end_list_start)
{
	t_op_list	*it;
	t_op_list	*tmp;

	it = *start;
	while (it)
	{
		it->f(sys, end_list_start);
		tmp = it->next;
		free(it);
		it = tmp;
	}
}

void	sort_three_splice(t_s *sys, t_end_list **start)
{
	if (sys->a->array[1] < sys->a->array[2])
	{
		sa(sys, start);
		pa(sys, start);
		sa(sys, start);
		pb(sys, start);
	}
	if (sys->a->array[1] > sys->a->array[2])
	{
		sa(sys, start);
		pa(sys, start);
		sa(sys, start);
		pb(sys, start);
		sa(sys, start);
	}
}

void	sort_three(t_s *sys, t_end_list **start)
{
	if (sys->a->array[0] < sys->a->array[1] &&
			sys->a->array[1] < sys->a->array[2])
		return ;
	if (sys->a->array[0] < sys->a->array[1] &&
			sys->a->array[0] < sys->a->array[2])
	{
		pa(sys, start);
		sa(sys, start);
		pb(sys, start);
	}
	else if (sys->a->array[0] < sys->a->array[1] ||
				sys->a->array[0] < sys->a->array[2])
	{
		if (sys->a->array[1] < sys->a->array[0])
			sa(sys, start);
		else if (sys->a->array[2] < sys->a->array[0])
		{
			pa(sys, start);
			sa(sys, start);
			pb(sys, start);
			sa(sys, start);
		}
	}
	else
		sort_three_splice(sys, start);
}
