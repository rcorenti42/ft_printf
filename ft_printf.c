#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_list	list;

	list.fd = 1;
	va_start(list.ap, format);
	while (format[list.i])
	{
		if (format[list.i] == '%' && format[list.i + 1] == '%')
		{
			list.ret += write(list.fd, "%", 1);
			list.i += 2;
		}
		else if (format[list.i] == '%' && format[list.i + 1] != '%')
			ft_convert(format, &list);
		else
			list.ret += write(list.fd, &format[list.i++], 1);
	}
	va_end(list.ap);
	return (list.ret);
}
