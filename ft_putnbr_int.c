/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:14:59 by obelaizi          #+#    #+#             */
/*   Updated: 2022/11/09 22:44:14 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_int(int nb, int *count)
{
	char	c;

	if (nb == -2147483648)
		*count += write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		*count += write(1, "-", 1);
		ft_putnbr_int(-nb, count);
	}
	else if (nb >= 0 && nb <= 9)
	{
		c = nb + 48;
		*count += write(1, &c, 1);
	}
	else
	{
		ft_putnbr_int(nb / 10, count);
		ft_putnbr_int(nb % 10, count);
	}
}
