/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 05:22:06 by rcorenti          #+#    #+#             */
/*   Updated: 2020/01/28 22:23:24 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hexa_prec(t_list *list, char c)
{
	int		len;
	int		i;
	char	*tmp;
	char	*new;

	len = ft_strlen(list->out);
	if(list->flag.prec == 0 && list->out[0] =='0')
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

static void	ft_print_hexa_pref(t_list *list, char c, int num)
{
	list->ret += (c == 'x') ? write(list->fd, "0x", 2) : 0;
	list->ret += (c == 'X') ? write(list->fd, "0X", 2) : 0;
}
static void	ft_print_hexa_width(t_list *list, char c)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(list->out);
	if (list->flag.prec >= 0)
	{
		while (list->flag.width > list->flag.prec + ++i &&
		list->flag.width > len + i)
			list->ret += write(list->fd, " ", 1);
		while (list->flag.width > len + i++)
			list->ret += write(list->fd, "0", 1);
	}
	else
	{
		while (list->flag.width > len + ++i)
			list->ret += (list->flag.zero ? write(list->fd, "0", 1) :
			write(list->fd, " ", 1));
	}
}

void		ft_print_hexa(t_list *list, char c, int num)
{
	ft_print_hexa_prec(list, c);
	if (list->flag.zero)
	{
		ft_print_hexa_pref(list, c, num);
		ft_print_hexa_width(list, c);
		list->ret += write(list->fd, list->out, ft_strlen(list->out));
	}
	else if (list->flag.min)
	{
		ft_print_hexa_pref(list, c, num);
		list->ret += write(list->fd, list->out, ft_strlen(list->out));
		ft_print_hexa_width(list, c);
	}
	else
	{
		ft_print_hexa_width(list, c);
		ft_print_hexa_pref(list, c, num);
		list->ret += write(list->fd, list->out, ft_strlen(list->out));
	}
	list->i++;
	free(list->out);
}
