#include "ft_printf.h"

static t_args	*initialise(void)
{
	t_args	*args;

	args = (t_args *)malloc(sizeof(t_args));
	if (args == NULL)
		return (NULL);
	args->counter = 0;
	return (args);
}

void	flaghandler(const char c, t_args *args)
{
	if (c == 'c')
		ft_char(args);
	if (c == 's')
		ft_string(args);
	if (c == 'd' || c == 'i')
		ft_num(args);
	if (c == 'u')
		ft_unsignednum(args);
	if (c == 'x' || c == 'X')
		ft_hex(args, c);
	if (c == 'p')
		ft_pointer(args);
	else if (c == '%')
	{
		ft_putchar('%');
		args->counter += 1;
	}
}

int	ft_printf(const char *str, ...)
{
	t_args	*args;
	int		i;

	i = 0;
	args = initialise();
	va_start(args->arg, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			args->counter++;
		}
		else if (str[i] == '%')
			flaghandler(str[++i], args);
		i++;
	}
	va_end(args->arg);
	free(args);
	return (args->counter);
}
