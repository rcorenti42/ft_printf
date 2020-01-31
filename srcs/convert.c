/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:58:08 by rcorenti          #+#    #+#             */
/*   Updated: 2020/01/31 04:41:03 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_width(t_list *list)
{
	list->flag.width = va_arg(list->ap, int);
	if (list->flag.width < 0)
	{
		list->flag.width = -list->flag.width;
		list->flag.min = 1;
	}
}

void	ft_conv_prec(const char *format, t_list *list)
{
	if (format[list->i + 1] == '*')
	{
		list->flag.prec = va_arg(list->ap, int);
		list->i += 2;
	}
	else
	{
		list->i++;
		list->flag.prec = ft_atoi(format + list->i);
		while (ft_isdigit(format[list->i]))
			list->i++;
	}
}

void	ft_conv_spec(const char *format, t_list *list)
{
	if (format[list->i] == '%')
		ft_flag_perc(list);
	else if (format[list->i] == 'd' || format[list->i] == 'i')
		ft_check_int(list);
	else if (format[list->i] == 'u')
		ft_check_unsigned_int(list);
	else if (format[list->i] == 'c' || format[list->i] == 's')
		ft_check_char(list, format[list->i]);
	else if (format[list->i] == 'p')
		ft_check_ptr(list);
	else if (format[list->i] == 'x' || format[list->i] == 'X')
		ft_check_hexa(list, format[list->i]);
}

void	ft_conv_flag(const char *format, t_list *list)
{
	while (ft_strchr(FLAGS, format[list->i]))
	{
		format[list->i] == '-' ? list->flag.min = 1 : 0;
		format[list->i] == '0' ? list->flag.zero = 1 : 0;
		format[list->i] == '*' ? ft_conv_width(list) : 0;
		if (format[list->i] == '.')
			ft_conv_prec(format, list);
		else if (format[list->i] >= '1' && format[list->i] <= '9')
		{
			list->flag.width = ft_atoi(format + list->i);
			while (format[list->i] >= '0' && format[list->i] <= '9')
				list->i++;
		}
		else if (format[list->i] == '\0')
			break ;
		else
			list->i++;
	}
}

void	ft_convert(const char *format, t_list *list)
{
	int	j;
	int num;

	j = 0;
	list->i++;
	ft_flag(&list->flag);
	if (format[list->i] >= '0' && format[list->i] <= '9')
	{
		num = ft_atoi(format + list->i);
		while (format[list->i + j] >= '0' && format[list->i + j] <= '9')
			j++;
	}
	ft_conv_flag(format, list);
	ft_conv_spec(format, list);
}
