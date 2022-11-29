/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:49:46 by obelaizi          #+#    #+#             */
/*   Updated: 2022/11/29 15:52:22 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

void	ft_putnbr_int(int nb, int *count);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_put_exadicimal(unsigned int nbr, int *count, int check);
void	ft_putnbr_unsigned(unsigned int nb, int *count);
size_t	ft_strlen(const char *s);
void	ft_put_pointer(void *s, int *count);
char	*ft_strdup(const char *src);
int		ft_printf(const char *s, ...);

#endif