#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "-.*0123456789"

typedef struct	s_flag
{
	int			min;
	int			zero;
	int			width;
	int			prec;
}				t_flag;

typedef enum	e_mod
{
	
}				t_mod;

typedef struct	s_list
{
	va_list		ap;
	t_flag		flag;
	int			fd;
	int			i;
	int			ret;
}				t_list;

int				ft_printf(const char *format, ...);

#endif
