/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freechain.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:18:25 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/25 16:32:37 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREECHAIN_H
# define FREECHAIN_H
# include "libft.h"

typedef struct	s_freechain
{
	char	*id;
	t_list	*list;
}				t_freechain;

t_list			**ft_freechain_global(void);
t_freechain		*ft_freechain_get(char *chain_id);
void			ft_freechain_add(char *chain_id, int n, ...);
void			ft_freechain_free(char *chain_id);

void			ft_freechain_adddoubletab(char *freechain_id, void **tab);
void			ft_freechain_addmatrix(char *freechain_id, t_matrix *matrix);
void			ft_assert_free(int condition, char *freechain_id, char *err);

#endif
