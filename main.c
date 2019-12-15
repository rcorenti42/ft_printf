#include "libftprintf.h"

int		main(int ac, char **av)
{
	int	i;

	i = 0;
	ft_printf("test :\n%d\n", ac);
	while (++i < ac)
		ft_printf("%d\n%s\n", i, av[i]);
	return (0);
}
