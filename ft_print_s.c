/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 03:33:35 by rcorenti          #+#    #+#             */
/*   Updated: 2020/01/28 05:18:40 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_null_s(t_list *list)
{
	int	len;

	len = (list->flag.prec < 0 ? 6 : list->flag.prec);
	while (list->flag.width-- > len)
		list->ret += (list->flag.zero == 1 ?
		write(list->fd, "0", 1) : write(list->fd, " ", 1));
	list->ret += write(list->fd, " ", 1);
	list->i++;
}

void	ft_print_null_c(t_list *list)
{
	while (list->flag.width-- > 1)
		list->ret += (list->flag.zero == 1 ?
		write(list->fd, "0", 1) : write(list->fd, " ", 1));
	list->ret += write(list->fd, "\0", 1);
	list->i++;
}

void	ft_print_s(t_list *list)
{
	char	*tmp;

	if (list->flag.prec >= 0 && list->flag.prec < ft_strlen(list->out))
	{
		tmp = (char *)malloc(sizeof(char) * (list->flag.prec + 1))
		if (!tmp)
			return (NULL);
		ft_bzero(tmp, list->flag.prec + 1);
		ft_strncpy(tmp, list->out, list->flag.prec);
		free(list->out);
		list->out = tmp;
	}
	if (list->flag.min)
	{
		list->ret += write(list->fd, list->out, ft_strlen(list->out));
		while (list->flag.width-- > ft_strlen(list->out))
			list->ret += (list->flag.zero == 1 ?
			write(list->fd, "0", 1) : write(list->fd, " ", 1));
		list->ret += write(list->fd, list->out, ft_strlen(list->out));
	}
	list->i++;
	free(list->out);
}

void	ft_print_c(t_list *list, char c)
{
	if (list->flag.min)
	{
		list->ret += write(list->fd, &c, 1);
		while (list->flag.width-- > 1)
			list->ret += (list->flag.zero == 1 ?
			write(list->fd, "0", 1) : write(list->fd, " ", 1));
	}
	else
	{
		while (list->flag.width-- > 1)
			list->ret += (list->flag.zero == 1 ?
			write(list->fd, "0", 1) : write(list->fd, " ", 1));
		list->ret += write(list->fd, &c, 1);
	}
	list->i++;
}
