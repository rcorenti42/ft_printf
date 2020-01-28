/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 00:25:09 by rcorenti          #+#    #+#             */
/*   Updated: 2020/01/28 05:29:45 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_int(t_list *list)
{
	int	tmp;
	int	i;

	tmp = va_arg(list->ap, int);
	i = tmp;
	list->flag.min == 1 ? list->flag.zero = 0 : 0;
	list->flag.prec >= 0 ? list->flag.zero = 0 : 0;
	ft_print_digits(list);
}

void	ft_check_unsigned_int(t_list *list)
{
	unsigned int	tmp;

	tmp = va_arg(list->ap, unsigned int);
	ft_print_digits(list);
}

void	ft_check_char(t_list *list, char c)
{
	char	*str;
	int		i;

	list->flag.min ? list->flag.zero = 0 : 0;
	if (c == 's')
	{
		str = va_arg(list->ap, char *);
		if (str == NULL)
			return (ft_print_null_s(list));
		list->out = ft_strdup(str);
		ft_print_s(list);
	}
	else
	{
		i = va_arg(list->ap, int);
		ft_print_c(list, i);
	}
}

void	ft_check_ptr(t_list *list)
{
	unsigned long	tmp;

	tmp = va_arg(list->ap, unsigned long);
	if (list->flag.prec == 0)
		list->out = ft_strdup("\0");
	else
		list->out = ft_base(tmp, 16);
	ft_printf_ptr(list);
}

void	ft_check_hexa(t_list *list, char c)
{
	int	tmp;
	int	num;
	int	i;

	num = 0;
	i = 0;
	tmp = va_arg(list->ap, int);
	list->out = ft_base((long long)num, 16);
	if (c == 'x')
	{
		while (list->out[i])
		{
			if (list->out[i] >= 'A' && list->out[i] <= 'Z')
				list->out[i] += 32;
			i++;
		}
	}
	list->flag.min == 1 ? list ->flag.zero = 0 : 0;
	ft_print_hexa(list, c, num);
}
