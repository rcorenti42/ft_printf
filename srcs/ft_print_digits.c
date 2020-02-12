/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:45:43 by rcorenti          #+#    #+#             */
/*   Updated: 2020/02/12 03:38:00 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_digits_neg(t_list *list)
{
	char	*tmp;

	if (list->out[0] == '-')
	{
		tmp = ft_strdup(list->out + 1);
		free(list->out);
		list->out = tmp;
		list->flag.neg = 1;
	}
}

static void	ft_print_digits_prec(t_list *list)
{
	int		i;
	int		len;
	char	*tmp;
	char	*new;

	ft_print_digits_neg(list);
	len = ft_strlen(list->out);
	if (list->flag.prec == 0 && list->out[0] == '0')
		list->out[0] = '\0';
	else if (list->flag.prec > len)
	{
		i = list->flag.prec - len;
		tmp = (char *)malloc(sizeof(char) * (i + 1));
		if (tmp)
		{
			ft_bzero(tmp, (i + 1));
			while (i-- > 0)
				tmp[i] = '0';
			new = ft_strjoin(tmp, list->out);
			free(tmp);
			free(list->out);
			list->out = new;
		}
	}
}

static void	ft_print_digits_width(t_list *list)
{
	int	len;
	int	i;

	i = -1;
	len = ((int)ft_strlen(list->out) > list->flag.prec ? ft_strlen(list->out) :
	list->flag.prec);
	list->flag.neg ? list->flag.width-- : 0;
	if (list->flag.prec >= 0)
	{
		while (list->flag.width - ++i > len)
			list->ret += write(1, " ", 1);
	}
	else
		while (list->flag.width - ++i > len)
			list->ret += (list->flag.zero == 1 ? write(1, "0", 1) :
			write(1, " ", 1));
}

static void	ft_print_sign(t_list *list)
{
	if (list->flag.neg == 1)
		list->ret += write(1, "-", 1);
}

void		ft_print_digits(t_list *list)
{
	ft_print_digits_prec(list);
	if (list->flag.zero)
	{
		ft_print_sign(list);
		ft_print_digits_width(list);
		list->ret += write(1, list->out, ft_strlen(list->out));
	}
	else if (list->flag.min)
	{
		ft_print_sign(list);
		list->ret += write(1, list->out, ft_strlen(list->out));
		ft_print_digits_width(list);
	}
	else
	{
		ft_print_digits_width(list);
		ft_print_sign(list);
		list->ret += write(1, list->out, ft_strlen(list->out));
	}
	list->i++;
	free(list->out);
}
