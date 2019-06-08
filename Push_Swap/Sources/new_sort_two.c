/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:07 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/15 17:31:08 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		recpa(t_s *sys, t_s *og, t_op_list **start, int it)
{
	if (sys->a->size < 1)
		return (0);
	pa(sys, NULL);
	if (sorted_till(sys) == og->a->size)
	{
		pf_list(start, &pa);
		return (it);
	}
	if (it == og->size)
	{
		pb(sys, NULL);
		return (0);
	}
	if (recsa(sys, og, start, it + 1) || recsb(sys, og, start, it + 1) ||
		recpa(sys, og, start, it + 1) || recra(sys, og, start, it + 1) ||
		recrra(sys, og, start, it + 1) || recrrb(sys, og, start, it + 1) ||
		recrb(sys, og, start, it + 1))
	{
		pf_list(start, &pa);
		return (1);
	}
	pb(sys, NULL);
	return (0);
}

int		recpb(t_s *sys, t_s *og, t_op_list **start, int it)
{
	if (sys->b->size < 1)
		return (0);
	pb(sys, NULL);
	if (sorted_till(sys) == og->a->size)
	{
		pf_list(start, &pb);
		return (1);
	}
	if (it == og->size)
	{
		pa(sys, NULL);
		return (0);
	}
	if (recpb(sys, og, start, it + 1) || recsa(sys, og, start, it + 1) ||
		recsb(sys, og, start, it + 1) || recra(sys, og, start, it + 1) ||
		recrra(sys, og, start, it + 1) || recrrb(sys, og, start, it + 1) ||
		recrb(sys, og, start, it + 1))
	{
		pf_list(start, &pb);
		return (1);
	}
	pa(sys, NULL);
	return (0);
}

int		recsb(t_s *sys, t_s *og, t_op_list **start, int it)
{
	if (sys->b->size < 2)
		return (0);
	sb(sys, NULL);
	if (sorted_till(sys) == og->a->size)
	{
		pf_list(start, &sb);
		return (1);
	}
	if (it == og->size)
	{
		sb(sys, NULL);
		return (0);
	}
	if (recsa(sys, og, start, it + 1) || recpb(sys, og, start, it + 1) ||
		recpa(sys, og, start, it + 1) || recra(sys, og, start, it + 1) ||
		recrra(sys, og, start, it + 1) || recrrb(sys, og, start, it + 1) ||
		recrb(sys, og, start, it + 1))
	{
		pf_list(start, &sb);
		return (1);
	}
	sb(sys, NULL);
	return (0);
}

int		recsa(t_s *sys, t_s *og, t_op_list **start, int it)
{
	if (sys->a->size < 2)
		return (0);
	sa(sys, NULL);
	if (sorted_till(sys) == og->a->size)
	{
		pf_list(start, &sa);
		return (1);
	}
	if (it == og->size)
	{
		sa(sys, NULL);
		return (0);
	}
	if (recsb(sys, og, start, it + 1) || recpb(sys, og, start, it + 1) ||
		recpa(sys, og, start, it + 1) || recra(sys, og, start, it + 1) ||
		recrra(sys, og, start, it + 1) || recrrb(sys, og, start, it + 1) ||
		recrb(sys, og, start, it + 1))
	{
		pf_list(start, &sa);
		return (1);
	}
	sa(sys, NULL);
	return (0);
}

int		recra(t_s *sys, t_s *og, t_op_list **start, int it)
{
	if (sys->a->size < 2)
		return (0);
	ra(sys, NULL);
	if (sorted_till(sys) == og->a->size)
	{
		pf_list(start, &ra);
		return (1);
	}
	if (it == og->size)
	{
		rra(sys, NULL);
		return (0);
	}
	if (recsb(sys, og, start, it + 1) || recpb(sys, og, start, it + 1) ||
		recpa(sys, og, start, it + 1) || recra(sys, og, start, it + 1) ||
		recrrb(sys, og, start, it + 1) || recrb(sys, og, start, it + 1) ||
		recra(sys, og, start, it + 1))
	{
		pf_list(start, &ra);
		return (1);
	}
	rra(sys, NULL);
	return (0);
}
