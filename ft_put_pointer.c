/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:44:26 by obelaizi          #+#    #+#             */
/*   Updated: 2022/11/10 01:39:29 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	helper(unsigned long nbr, char *base, int *count)
{
	if (nbr < 16)
		(*count) += write(1, &(base[nbr]), 1);
	else
	{
		helper(nbr / 16, base, count);
		helper(nbr % 16, base, count);
	}
}

void	exadicimal(unsigned long nbr, int *count, int check)
{
	unsigned long	n;
	char			*base;

	n = nbr;
	if (check)
		base = ft_strdup("0123456789ABCDEF");
	else
		base = ft_strdup("0123456789abcdef");
	if (nbr < 0)
	{
		(*count) += write(1, "-", 1);
		n = -nbr;
	}
	else
		n = nbr;
	helper(n, base, count);
	free(base);
}

void	ft_put_pointer(char *s, int *count)
{
	unsigned long	hold;

	hold = (unsigned long)s;
	(*count) += write(1, "0x", 2);
	exadicimal(hold, count, 0);
}
