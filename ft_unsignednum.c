#include "ft_printf.h"

static int	unsignednumlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_unsigneditoa(unsigned int n)
{
	int		len;
	char	*str;

	len = unsignednumlen(n);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (len > 0)
	{
		str[len - 1] = '0' + (n % 10);
		n = n / 10;
		len--;
	}
	return (str);
}

void	ft_unsignednum(t_args *args)
{
	char	*str;

	str = ft_unsigneditoa((unsigned int)va_arg(args->arg, unsigned int));
	ft_putstr(str);
	args->counter += ft_strlen(str);
	free(str);
}
