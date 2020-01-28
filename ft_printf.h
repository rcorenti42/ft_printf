/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:57:43 by rcorenti          #+#    #+#             */
/*   Updated: 2020/01/28 22:14:51 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "libft/libft.h"

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
void			ft_flag_perc(t_list *list);
void			ft_conv_width(t_list *list);
void			ft_conv_prec(const char *format, t_list *list);
void			ft_conv_spec(const char *format, t_list *list);
void			ft_conv_flag(const char *format, t_list *list);
void			ft_convert(const char *format, t_list *list);
char			*ft_base(long long n, int base);
void			ft_check_int(t_list *list);
void			ft_check_unsigned_int(t_list *list);
void			ft_check_char(t_list *list, char c);
void			ft_check_ptr(t_list *list);
void			ft_check_hexa(t_list *list, char c);
void			ft_print_digits_neg(t_list *list);
void			ft_print_digits_prec(t_list *list);
void			ft_print_digits_width(t_list *list);
void			ft_print_digits(t_list *list);
void			ft_print_hexa(t_list *list, char c, int num);
void			ft_print_ptr_prec(t_list *list);
void			ft_print_ptr(t_list *list);
void			ft_print_null_s(t_list *list);
void			ft_print_null_c(t_list *list);
void			ft_print_s(t_list *list);
void			ft_print_c(t_list *list, char c);

#endif
