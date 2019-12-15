#include "libftprintf.h"
#include "Libft/libft.h"

int	ft_putconv(va_list args, const char c)
{
	char	c1;

	if (c == 'x' || c == 'X')
		return (ft_conv_xX(args, c));
	if (c == 'o')
		return (ft_conv_o(args, c));
	if (c == 's')
		return (ft_conv_s(args, c));
	if (c == 'p')
		return (ft_conv_p(args, c));
	if (c == 'd' || c == 'i')
		return (ft_conv_di(args, c));
	if (c == 'c')
	{
		c1 = (char)va_arg(args, int);
		write(1, &c1, 1);
		return (1);
	}
	write(1, "%", 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	int		k;
	va_list	args;
	
	i = 0;
	j = 0;
	k = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			k += ft_putconv(args, format[i]);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			j++;
		}
	}
	return (j + k);
}
