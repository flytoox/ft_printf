/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:36:23 by obelaizi          #+#    #+#             */
/*   Updated: 2022/11/10 01:39:52 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int nb, int *count)
{
	char	c;

	if (nb >= 0 && nb <= 9)
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
