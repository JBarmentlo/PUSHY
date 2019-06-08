/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynlist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:20:48 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/04 16:20:48 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNLIST_H
# define DYNLIST_H
# include <string.h>

typedef struct	s_dynit
{
	void			*current;
	struct s_dynit	*next;
	struct s_dynit	*prev;
}				t_dynit;

typedef struct	s_dynlist
{
	t_dynit		*first;
	t_dynit		*last;
	t_dynit		*it;
	size_t		size;
}				t_dynlist;

t_dynlist		*ft_dynlist_create();
void			ft_dynlist_free(t_dynlist *list, void (*free_content)(void*));

void			ft_dynlist_pushback(t_dynlist *list, void *item);
void			ft_dynlist_pushfront(t_dynlist *list, void *item);
void			ft_dynlist_insertafter(t_dynlist *list, void *item,
	void *after);
void			ft_dynlist_insertbefore(t_dynlist *list, void *item,
	void *before);
void			ft_dynlist_insertat(t_dynlist *list, void *item, int index);

int				ft_dynlist_contains(t_dynlist *list, void *item);
int				ft_dynlist_indexof(t_dynlist *list, void *item);
void			*ft_dynlist_get(t_dynlist *list, int index);
void			*ft_dynlist_popitem(t_dynlist *list, void *item);
void			*ft_dynlist_popindex(t_dynlist *list, int index);

void			ft_dynlist_it_init(t_dynlist *list);
int				ft_dynlist_it_next(t_dynlist *list);
int				ft_dynlist_it_prev(t_dynlist *list);
void			*ft_dynlist_it_get(t_dynlist *list);

#endif
