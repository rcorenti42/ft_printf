/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:58:01 by rcorenti          #+#    #+#             */
/*   Updated: 2020/01/28 00:08:41 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag(t_flag *flag)
{
	flag->min = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->prec = -1;
}

void	ft_flag_perc(t_list *list)
{
	if (list->flag.min)
	{
		list->ret += write(list->fd, "%", 1);
		while (list->flag.width-- > 1)
			list->ret += write(list->fd, " ", 1);
	}
	else
	{
		while (list->flag.width-- > 1)
			list->ret += (list->flag.zero ? write(list->fd, "0", 1) :
			write(list->fd, " ", 1));
		list->ret += write(list->fd, "%", 1);
	}
	list->i++;
}
