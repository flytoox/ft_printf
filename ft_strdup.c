/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:32:55 by obelaizi          #+#    #+#             */
/*   Updated: 2022/11/07 18:11:48 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *src)
{
	size_t		i;
	int			j;
	char		*cp;

	j = 0;
	i = ft_strlen(src);
	cp = malloc((i + 1) * sizeof(char));
	if (!cp)
		return (0);
	while (i)
	{
		cp[j] = src[j];
		j++;
		i--;
	}
	cp[j] = 0;
	return (cp);
}
