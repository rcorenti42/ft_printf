/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:57:43 by rcorenti          #+#    #+#             */
/*   Updated: 2020/02/14 01:25:22 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "../libft/includes/libft.h"

# define FLAGS "-.*0123456789"

typedef struct	s_flag
{
	int			min;
	int			zero;
	int			width;
	int			prec;
	int			neg;
}				t_flag;

typedef struct	s_list
{
	va_list		ap;
	t_flag		flag;
	char		*out;
	int			i;
	int			ret;
}				t_list;

int				ft_printf(const char *format, ...);
void			ft_convert(const char *format, t_list *list);
char			*ft_base(long long n, int base);
void			ft_check_int(t_list *list);
void			ft_check_unsigned_int(t_list *list);
void			ft_check_char(t_list *list, char c);
void			ft_check_ptr(t_list *list);
void			ft_check_hexa(t_list *list, char c);
void			ft_print_digits(t_list *list);
void			ft_print_hexa(t_list *list);
void			ft_print_ptr(t_list *list);
void			ft_print_null_s(t_list *list);
void			ft_print_s(t_list *list);
void			ft_print_c(t_list *list, char c);

#endif
