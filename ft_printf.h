/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:57:43 by rcorenti          #+#    #+#             */
/*   Updated: 2020/01/28 01:57:39 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define FLAGS "-.*0123456789"

typedef struct	s_flag
{
	int			min;
	int			zero;
	int			width;
	int			prec;
}				t_flag;

typedef struct	s_list
{
	va_list		ap;
	t_flag		flag;
	char		*out;
	int			fd;
	int			i;
	int			ret;
}				t_list;

int				ft_printf(const char *format, ...);
void			ft_flag(t_flag *flag);
void			ft_conv_width(t_list *list);
void			ft_conv_prec(const char *format, t_list *list);
void			ft_conv_spec(const char *format, t_list *list);
void			ft_conv_flag(const char *format, t_list *list);
void			ft_convert(const char *format, t_list *list);

#endif
