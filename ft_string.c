#include "ft_printf.h"

void	ft_string(t_args *args)
{
	char	*str;
	int		len;

	str = va_arg(args->arg, char *);
	len = ft_strlen(str);
	if (str == NULL)
	{
		ft_putstr("(null)");
		args->counter += 6;
	}
	else
	{
		write(1, str, len);
	}
}
