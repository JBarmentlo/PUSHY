/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:18:58 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/25 16:28:41 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H
# define RL_NEWLINE 1
# define RL_LASTEMPTYLINE 2
# define BUFF_SIZE 32
# include <unistd.h>

typedef struct	s_rl_buff
{
	int		fd;
	int		end;
	char	buffer[BUFF_SIZE + 1];
}				t_rl_buff;

int				ft_readline(const int fd, char **line, int flags);
char			*ft_readfile_str(int fd);
char			**ft_readfile_tab(int fd);

#endif
