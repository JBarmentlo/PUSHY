/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoiretaja <gregoiretaja@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:18:37 by gregoiretaja      #+#    #+#             */
/*   Updated: 2018/11/13 13:18:37 by gregoiretaja     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H
# define MATRIX_NBR_LEN 3

typedef struct	s_matrix
{
	int				**data;
	unsigned int	width;
	unsigned int	height;
}				t_matrix;

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_rect
{
	int				x;
	int				y;
	unsigned int	width;
	unsigned int	height;
}				t_rect;

t_matrix		*ft_matrix_create(int width, int height);
void			ft_matrix_free(t_matrix **matrix);
void			ft_matrix_show(t_matrix *matrix);
void			ft_matrix_localtravel(t_matrix *matrix, t_rect rect,
	void (*fct)(t_matrix *matrix, t_vector pos));
void			ft_matrix_travel(t_matrix *matrix,
	void (*fct)(t_matrix *matrix, t_vector pos));
void			ft_matrix_localmap(t_matrix *m1, t_matrix *m2, t_vector pos,
	int (*fct)(int, int));
void			ft_matrix_map(t_matrix *m1, t_matrix *m2, int (*fct)(int, int));
t_matrix		*ft_matrix_reduce(t_matrix **matrix);

t_rect			ft_getrect(int x, int y, int width, int height);
t_vector		ft_getvector(int x, int y);

#endif
