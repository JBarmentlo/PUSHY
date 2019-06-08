/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callstack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 00:27:07 by gtaja             #+#    #+#             */
/*   Updated: 2019/03/05 14:23:23 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALLSTACK_H
# define CALLSTACK_H
# include "libft.h"

typedef struct	s_callstack
{
	t_list	*current_stack;
	t_list	*new_stack;
}				t_callstack;

void			ft_callstack_addnew(t_callstack *stack,
	void (*fct)(t_callstack*, void*), void *args);
void			ft_callstack_addcurrent(t_callstack *stack,
	void (*fct)(t_callstack*, void*), void *args);
int				ft_callstack_flush(t_callstack *stack);

#endif
