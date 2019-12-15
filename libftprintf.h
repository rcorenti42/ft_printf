#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int		ft_printf(const char *, ...);
int		ft_putconv(va_list args, const char c);
int	ft_conv_xX(va_list args, const char c);
int	ft_conv_s(va_list args, const char c);
int ft_conv_p(va_list args, const char c);
int ft_conv_di(va_list args, const char c);
int	ft_conv_o(va_list args, const char c);

#endif
