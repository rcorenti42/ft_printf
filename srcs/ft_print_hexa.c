/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 05:22:06 by rcorenti          #+#    #+#             */
/*   Updated: 2020/02/12 03:38:43 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hexa_prec(t_list *list)
{
	int		len;
	int		i;
	char	*tmp;
	char	*new;

	len = ft_strlen(list->out);
	if (list->flag.prec == 0 && list->out[0] == '0')
		list->out[0] = '\0';
	else if (list->flag.prec > len)
	{
		i = list->flag.prec - len;
		tmp = (char *)malloc(sizeof(char) * (i + 1));
		if (tmp)
		{
			ft_bzero(tmp, i + 1);
			while (--i >= 0)
				tmp[i] = '0';
			new = ft_strjoin(tmp, list->out);
			free(tmp);
			free(list->out);
			list->out = new;
		}
	}
}

static void	ft_print_hexa_width(t_list *list)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(list->out);
	if (list->flag.prec >= 0)
	{
		while (list->flag.width > list->flag.prec + ++i &&
		list->flag.width > len + i)
			list->ret += write(1, " ", 1);
	}
	else
	{
		while (list->flag.width > len + ++i)
			list->ret += (list->flag.zero ? write(1, "0", 1) :
			write(1, " ", 1));
	}
}

void		ft_print_hexa(t_list *list)
{
	ft_print_hexa_prec(list);
	if (list->flag.min)
	{
		list->ret += write(1, list->out, ft_strlen(list->out));
		ft_print_hexa_width(list);
	}
	else
	{
		ft_print_hexa_width(list);
		list->ret += write(1, list->out, ft_strlen(list->out));
	}
	list->i++;
	free(list->out);
}
