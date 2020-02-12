/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 03:33:35 by rcorenti          #+#    #+#             */
/*   Updated: 2020/02/12 03:40:40 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_null_s(t_list *list)
{
	int	len;

	len = (list->flag.prec < 0 ? 6 : list->flag.prec);
	if (len > 6)
		len = 6;
	if (list->flag.min)
		list->ret += write(1, "(null)", len);
	while (list->flag.width-- > len)
		list->ret += (list->flag.zero == 1 ?
		write(1, "0", 1) : write(1, " ", 1));
	if (!(list->flag.min))
		list->ret += write(1, "(null)", len);
	list->i++;
}

static void	ft_tmp_s(t_list *list, char **tmp)
{
	if (*tmp)
	{
		ft_bzero(*tmp, list->flag.prec + 1);
		ft_strncpy(*tmp, list->out, list->flag.prec);
		free(list->out);
		list->out = *tmp;
	}
}

void		ft_print_s(t_list *list)
{
	char	*tmp;

	if (list->flag.prec >= 0 && list->flag.prec < (int)ft_strlen(list->out))
	{
		tmp = (char *)malloc(sizeof(char) * (list->flag.prec + 1));
		ft_tmp_s(list, &tmp);
	}
	if (list->flag.min)
	{
		list->ret += write(1, list->out, ft_strlen(list->out));
		while (list->flag.width-- > (int)ft_strlen(list->out))
			list->ret += (list->flag.zero == 1 ?
			write(1, "0", 1) : write(1, " ", 1));
	}
	else
	{
		while (list->flag.width-- > (int)ft_strlen(list->out))
			list->ret += (list->flag.zero == 1 ?
			write(1, "0", 1) : write(1, " ", 1));
		list->ret += write(1, list->out, ft_strlen(list->out));
	}
	list->i++;
	free(list->out);
}

void		ft_print_c(t_list *list, char c)
{
	if (list->flag.min)
	{
		list->ret += write(1, &c, 1);
		while (list->flag.width-- > 1)
			list->ret += (list->flag.zero == 1 ?
			write(1, "0", 1) : write(1, " ", 1));
	}
	else
	{
		while (list->flag.width-- > 1)
			list->ret += (list->flag.zero == 1 ?
			write(1, "0", 1) : write(1, " ", 1));
		list->ret += write(1, &c, 1);
	}
	list->i++;
}
