#include "libftprintf.h"
#include "../Libft/libft.h"

static char	*ft_printf_hexa(int n)
{
	int		i;
	int		k;
	char	*lst;
	char	*str;

	i = n;
	k = 0;
	lst = (char *)malloc(sizeof(char) * 17);
	lst = "0123456789abcdef\0";
	str = (char *)malloc(sizeof(char) * (ft_strlen(ft_itoa(n))));
	while (i >= 16)
	{
		str[k] = lst[i % 16];
		i /= 16;
		k++;
	}
	str[k] = lst[i];
	k++;
	str[k] = '\0';
	free(lst);
	return (ft_reverse(str));
}

static void	ft_printf_x(va_list *args)
{
	int		i;
	char	*str;

	str = ft_printf_hexa(va_arg(*args, int));
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
}

static void	ft_printf_X(va_list *args)
{
	int		i;
	char	*str;

	str = ft_printf_hexa(va_arg(*args, int));
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
	free(str);
}

static int	ft_index(char *tab, char element)
{
	int	i;

	i = 0;
	while(tab[i])
	{
		if(tab[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_printf(const char *format, ...)
{
	void	(*tabFunction[8]) (va_list *) = {ft_printf_str, ft_printf_char, ft_printf_nbr, ft_printf_nbr, ft_printf_nbr, ft_printf_ptr, ft_printf_x, ft_printf_X};
	char	tab[10] = {'s', 'c', 'd', 'i', 'u', 'p', 'x', 'X', '%', 0};
	va_list	args;
	int	i;
	int	tmp;
	
	va_start(args, format);
	i = 0;
	tmp = 0;
	while (format[i])
	{
		if (i != 0 && format[i - 1] == '%' && format[i] != '%')
		{
			tmp = ft_index(tab, format[i]);
			if (tmp != -1)
				(*tabFunction[tmp]) (&args);
			else
				write(1, &format[i], 1);
		}
		else if (format[i] != '%')
			write(1, &format[i], 1);
		else if (format[i + 1] == '%')
		{
			write(1, "%", 1);
			i++;
		}
		i++;
	}
	va_end(args);
}
