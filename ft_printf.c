/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:48:02 by obelaizi          #+#    #+#             */
/*   Updated: 2022/11/29 16:00:19 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_char(const char *s, int c)
{
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

static void	check(int *count, char c, va_list p)
{
	if (c == 'c')
		ft_putchar(va_arg(p, int), count);
	else if (c == 's')
		ft_putstr(va_arg(p, char *), count);
	else if (c == 'p')
		ft_put_pointer(va_arg(p, void *), count);
	else if ((c == 'i' || c == 'd'))
		ft_putnbr_int(va_arg(p, int), count);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(p, unsigned int), count);
	else if (c == 'x')
		ft_put_exadicimal(va_arg(p, int), count, 0);
	else if (c == 'X')
		ft_put_exadicimal(va_arg(p, int), count, 1);
	else if (c == '%')
		*count += write(1, "%", 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	p;
	int		count;

	count = 0;
	if (write(1, "", 0) < 0)
		return (-1);
	va_start(p, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			if (check_char("cspdiuxX%", *(s + 1)))
				check(&count, *(s + 1), p);
			else
				ft_putchar(*(s + 1), &count);
			s += 2;
			continue ;
		}
		if (*s != '%')
			ft_putchar(*(s), &count);
		s++;
	}
	return (va_end(p), count);
}
