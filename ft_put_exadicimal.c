/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_exadicimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:29:40 by obelaizi          #+#    #+#             */
/*   Updated: 2022/11/29 15:50:16 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	helper(unsigned int nbr, char *base, int *count)
{
	if (nbr < 16)
		(*count) += write(1, &(base[nbr]), 1);
	else
	{
		helper(nbr / 16, base, count);
		helper(nbr % 16, base, count);
	}
}

void	ft_put_exadicimal(unsigned int nbr, int *count, int check)
{
	char			*base;

	if (check)
		base = ft_strdup("0123456789ABCDEF");
	else
		base = ft_strdup("0123456789abcdef");
	helper(nbr, base, count);
	free(base);
}
