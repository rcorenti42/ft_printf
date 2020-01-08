#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *, ...);
void	ft_printf_str(va_list *args);
void	ft_printf_char(va_list *args);
void	ft_printf_nbr(va_list *args);
void	ft_printf_ptr(va_list *args);
char	*ft_reverse(char *str);

#endif
