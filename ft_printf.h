#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_args
{
	va_list	arg;
	int		counter;
}	t_args;

int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_char(t_args *args);
size_t	ft_strlen(const char *str);
void	ft_string(t_args *args);
void	ft_unsignednum(t_args *args);
void	ft_hex(t_args *args, char c);
void	ft_pointer(t_args *args);
void	ft_num(t_args *args);

#endif