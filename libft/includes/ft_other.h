/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:15:47 by gregoiretaj       #+#    #+#             */
/*   Updated: 2019/04/17 14:26:42 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTHER_H
# define FT_OTHER_H

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			ft_exit_error(char *err);
void			ft_assert(int condition, char *err);

#endif
