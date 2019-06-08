/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_end_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:09 by jbarment          #+#    #+#             */
/*   Updated: 2019/06/08 18:02:15 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ps.h"
#include "libft.h"
#include <stdlib.h>

t_op		str_to_t_op_two(char *str)
{
	if (*str == 'r')
	{
		if (str[1] != 'r')
		{
			if (str[1] == 'a' && (str[2] == '\n' || str[2] == '\0'))
				return (&ra);
			if (str[1] == 'b' && (str[2] == '\n' || str[2] == '\0'))
				return (&rb);
			if (str[1] == 'r' && (str[2] == '\n' || str[2] == '\0'))
				return (&rb);
		}
		else if (str[1] == 'r')
		{
			if (str[2] == 'a' && (str[3] == '\n' || str[3] == '\0'))
				return (&rra);
			if (str[2] == 'b' && (str[3] == '\n' || str[3] == '\0'))
				return (&rrb);
			if (str[1] == 'r' && (str[2] == '\n' || str[2] == '\0'))
				return (&rrr);
		}
	}
	return (NULL);
}

t_op		str_to_t_op(char *str)
{
	if (str == NULL || *str == '\0' || str[1] == '\0')
		return (NULL);
	if (*str == 's')
	{
		if (str[1] == 'a' && (str[2] == '\n' || str[2] == '\0'))
			return (&sa);
		if (str[1] == 'b' && (str[2] == '\n' || str[2] == '\0'))
			return (&sb);
		if (str[1] == 's' && (str[2] == '\n' || str[2] == '\0'))
			return (&ss);
	}
	if (*str == 'p')
	{
		if (str[1] == 'a' && (str[2] == '\n' || str[2] == '\0'))
			return (&pb);
		if (str[1] == 'b' && (str[2] == '\n' || str[2] == '\0'))
			return (&pa);
	}
	return (str_to_t_op_two(str));
}

t_end_list	*new_end_list(t_op ptr)
{
	t_end_list	*new;

	new = malloco(sizeof(t_end_list));
	new->op = ptr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		free_end_list(t_end_list **start)
{
	t_end_list *it;

	if (!start)
		return ;
	it = *start;
	while (it)
	{
		*start = it;
		it = it->next;
		free(*start);
	}
}

void		push_back(t_end_list **any, t_end_list *elem)
{
	t_end_list	*it;

	if (*any == NULL)
	{
		*any = elem;
		return ;
	}
	it = *any;
	while (it && it->next)
		it = it->next;
	it->next = elem;
	elem->prev = it;
}
