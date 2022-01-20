#include "ft_printf.h"

int	main(void)
{
	int	n;

	n = 16;
	ft_printf("hello %s\nn = %i\n", "world", n);
	return (0);
}
