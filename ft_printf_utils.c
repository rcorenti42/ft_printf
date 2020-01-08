#include "libftprintf.h"
#include "../Libft/libft.h"

void	ft_printf_str(va_list *args)
{
	char	*str;
	
	str = va_arg(*args, char *);
	write(1, str, ft_strlen(str));
}

void	ft_printf_char(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	write(1, &c, 1);
}

void	ft_printf_nbr(va_list *args)
{
	int	i;
	char	*str;

	i = va_arg(*args, int);
	str = (char *)ft_itoa(i);
	write(1, str, ft_strlen(str));
}

void	ft_printf_ptr(va_list *args)
{
}

char	*ft_reverse(char *str)
{
	int		i;
	int		j;
	int		k;
	char	tmp;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	k = i / 2;
	i--;
	while (k > 0)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i--;
		j++;
		k--;
	}
	return (str);
}
