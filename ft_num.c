#include "ft_printf.h"

int	numlen(int n)
{
	int	len;

	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = (ft_strlen(str) - 1);
	i = 0;
	while (i < length)
	{
		tmp = str[i];
		str[i++] = str[length];
		str[length--] = tmp;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = 0;
	str = (char *)malloc((numlen(n) + (n < 0)) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[numlen(n) + 1] = '-';
	while (n > 0)
	{
		str[len++] = '0' + (n % 10);
		n = n / 10;
	}
	ft_strrev(str);
	return (str);
}

void	ft_num(t_args *args)
{
	char	*str;

	str = ft_itoa((int)va_arg(args->arg, int));
	ft_putstr(str);
	args->counter += ft_strlen(str);
	free(str);
}
