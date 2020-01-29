/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:20:49 by rcorenti          #+#    #+#             */
/*   Updated: 2020/01/28 21:38:02 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_base(long long n, int base)
{
	char		*res;
	long long	tmp;
	long long	len;

	len = 1;
	n < 0 ? ++len : 0;
	tmp = n < 0 ? -n : n;
	while (tmp >= base)
	{
		tmp /= base;
		len++;
	}
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	n < 0 ? *res = '-' : 0;
	n < 0 ? n = -n : 0;
	while (n >= base)
	{
		res[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
		n /= base;
	}
	res[--len] = n % base < 10 ? (n % base) + 48 : (n % base) + 55;
	return (res);
}
