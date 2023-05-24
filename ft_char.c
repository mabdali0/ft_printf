/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:46:57 by mabdali           #+#    #+#             */
/*   Updated: 2023/02/22 10:37:03 by mabdali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_c(char c, int fd, t_sc *sc)
{
	ft_putchar_fd(c, fd);
	sc->len += 1;
}

void	ft_put_s(char *s, int fd, t_sc *sc)
{
	if (!s)
	{
		write(1, "(null)", 6);
		sc->len += 6;
	}
	else
	{
		ft_putstr_fd(s, fd);
		sc->len += ft_strlen(s);
	}
}

void	ft_put_percent(int fd, t_sc *sc)
{
	ft_putchar_fd('%', fd);
	sc->len += 1;
}
