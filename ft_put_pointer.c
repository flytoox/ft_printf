/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:44:26 by obelaizi          #+#    #+#             */
/*   Updated: 2022/11/29 15:52:34 by obelaizi         ###   ########.fr       */
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

void	exadicimal(unsigned long nbr, int *count)
{
	char			*base;

	base = ft_strdup("0123456789abcdef");
	helper(nbr, base, count);
	free(base);
}

void	ft_put_pointer(void *s, int *count)
{
	unsigned long	hold;

	hold = (unsigned long)s;
	(*count) += write(1, "0x", 2);
	exadicimal(hold, count);
}
