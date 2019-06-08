/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:36:14 by gtaja             #+#    #+#             */
/*   Updated: 2019/01/29 14:08:06 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdarg.h>
# define GLOBAL_FLAGS "A0-+ #"
# define ALL_CONVERSION "diouxXbfcsp%"

# define PF_BLACK   "\x1b[30m"
# define PF_RED     "\x1b[31m"
# define PF_GREEN   "\x1b[32m"
# define PF_YELLOW  "\x1b[33m"
# define PF_BLUE    "\x1b[34m"
# define PF_MAGENTA "\x1b[35m"
# define PF_CYAN    "\x1b[36m"
# define PF_RESET   "\x1b[0m"
# define PF_BLACK_UNDERLINE   "\x1b[40m"
# define PF_RED_UNDERLINE     "\x1b[41m"
# define PF_GREEN_UNDERLINE   "\x1b[42m"
# define PF_YELLOW_UNDERLINE  "\x1b[43m"
# define PF_BLUE_UNDERLINE    "\x1b[44m"
# define PF_MAGENTA_UNDERLINE "\x1b[45m"
# define PF_CYAN_UNDERLINE    "\x1b[46m"

/*
** Penser a modifier ft_get_flag_dest dans ft_flags.c
** en meme temps que GLOBAL_FLAGS
*/

typedef unsigned long long	t_biguint;
typedef signed long long	t_bigint;

typedef struct				s_conv
{
	char	*conv;
	char	len_modifier[3];
	int		size;
	int		prec;
	int		prec_set;
	int		add_zero;
	int		left_justify;
	int		show_sign;
	int		sign_space;
	int		is_array;
	void	*array;
	int		hashtag;
}							t_conv;

typedef struct				s_handler
{
	char	*conv;
	char	*(*fct)(t_conv *, va_list);
}							t_handler;

/*
** HANDLERS
*/
t_handler					*ft_get_handlers(void);
char						*ft_handler_integer(t_conv *conv, va_list ap);
char						*ft_handler_char(t_conv *conv, va_list ap);
char						*ft_handler_string(t_conv *conv, va_list ap);
char						*ft_handler_pointer(t_conv *conv, va_list ap);
char						*ft_handler_float(t_conv *conv, va_list ap);
char						*ft_handler_percent(t_conv *conv, va_list ap);
int							ft_dispatch(int fd, t_conv *conv, va_list ap);
int							ft_exec_handler_array(int fd, t_conv *conv,
	va_list ap);

/*
** CONVERSION ET FLAGS
*/
t_conv						ft_getconv(char *start);
char						*ft_dispatch_color(int fd, char *format,
	int *count);

/*
** TOOLS
*/
char						*ft_itoa_base(t_biguint nb,
	unsigned int base_len, int maj);

/*
** PRINTF
*/
int							ft_internal_fprintf(int fd, const char *format,
	va_list ap);
int							ft_fprintf(int fd, const char *format, ...);
int							ft_printf(const char *format, ...);

#endif
