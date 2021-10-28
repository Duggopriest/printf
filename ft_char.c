#include "ft_printf.h"

void	ft_char(t_args *args)
{
	ft_putchar(va_arg(args->arg, int));
	args->counter++;
}
