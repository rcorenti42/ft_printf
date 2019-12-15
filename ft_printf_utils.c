#include "libftprintf.h"
#include "Libft/libft.h"

int	ft_conv_xX(va_list args, const char c)
{
}

int	ft_conv_s(va_list args, const char c)
{
	int			i;
	const char	*str;

	i = 0;
	str = va_arg(args, const char *);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_conv_p(va_list args, const char c)
{
}

int ft_conv_di(va_list args, const char c)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(va_arg(args, int));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}


int	ft_conv_o(va_list args, const char c)
{
}
