/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 05:20:09 by rcorenti          #+#    #+#             */
/*   Updated: 2020/02/12 03:39:08 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_ptr_prec(t_list *list)
{
	char	*str;
	char	*tmp;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(list->out);
	if (list->flag.prec > len)
	{
		tmp = (char *)malloc(sizeof(char) * (list->flag.prec - len + 1));
		if (tmp)
		{
			ft_bzero(tmp, list->flag.prec - len + 1);
			while (++i < list->flag.prec - len)
				tmp[i] = '0';
			str = ft_strjoin(tmp, list->out);
			free(list->out);
			free(tmp);
			list->out = str;
		}
	}
	tmp = ft_strjoin("0x", list->out);
	free(list->out);
	list->out = tmp;
}

void		ft_print_ptr(t_list *list)
{
	int	i;

	i = 0;
	ft_print_ptr_prec(list);
	while (list->out[i])
	{
		if (list->out[i] >= 'A' && list->out[i] <= 'Z')
			list->out[i] += 32;
		i++;
	}
	if (list->flag.min)
	{
		list->ret += write(1, list->out, i);
		while (list->flag.width-- > i)
			list->ret += write(1, " ", 1);
	}
	else
	{
		while (list->flag.width-- > i)
			list->ret += write(1, " ", 1);
		list->ret += write(1, list->out, i);
	}
	list->i++;
	free(list->out);
}
