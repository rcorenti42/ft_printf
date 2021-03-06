/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:57:54 by rcorenti          #+#    #+#             */
/*   Updated: 2020/02/12 03:35:55 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_list	list;

	list.i = 0;
	list.ret = 0;
	va_start(list.ap, format);
	while (format[list.i])
	{
		if (format[list.i] == '%' && format[list.i + 1] == '%')
		{
			list.ret += write(1, "%", 1);
			list.i += 2;
		}
		else if (format[list.i] == '%' && format[list.i + 1] != '%')
			ft_convert(format, &list);
		else
			list.ret += write(1, &format[list.i++], 1);
	}
	va_end(list.ap);
	return (list.ret);
}
