/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 00:25:01 by gregoiretaj       #+#    #+#             */
/*   Updated: 2019/03/05 15:16:25 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "callstack.h"

void	ft_callstack_addnew(t_callstack *stack,
	void (*fct)(t_callstack*, void*), void *args)
{
	ft_lstpushback(&(stack->new_stack), ft_lstitem((void*)fct, sizeof(void*)));
	ft_lstpushback(&(stack->new_stack), ft_lstitem(args, sizeof(void*)));
}

void	ft_callstack_addcurrent(t_callstack *stack,
	void (*fct)(t_callstack*, void*), void *args)
{
	ft_lstpushback(&(stack->current_stack),
		ft_lstitem((void*)fct, sizeof(void*)));
	ft_lstpushback(&(stack->current_stack), ft_lstitem(args, sizeof(void*)));
}

int		ft_callstack_flush(t_callstack *stack)
{
	void	(*fct)(t_callstack*, void*);
	void	*args;
	t_list	*it;
	t_list	*tmp;

	it = stack->current_stack;
	while (it != NULL && it->next != NULL)
	{
		tmp = it->next->next;
		fct = (void (*)(t_callstack*, void*))it->content;
		args = (void*)it->next->content;
		(*fct)(stack, args);
		free(it->next);
		free(it);
		it = tmp;
	}
	stack->current_stack = stack->new_stack;
	stack->new_stack = NULL;
	return (stack->current_stack != NULL);
}
