/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:20:13 by mabdali           #+#    #+#             */
/*   Updated: 2023/02/16 19:04:37 by mabdali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_len(int nbr)
{
	int	i;

	i = 0;
	if (!nbr)
		return (1);
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_uint_len(unsigned int nbr)
{
	int	i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	ft_put_di(int nbr, int fd, t_sc *sc)
{
	ft_putnbr_fd(nbr, fd);
	sc->len += ft_int_len(nbr);
}

void	ft_putunsigned_fd(unsigned int nbr, int fd)
{
	if (nbr > 9)
	{
		ft_putunsigned_fd(nbr / 10, fd);
		ft_putunsigned_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + 48, fd);
}

void	ft_put_u(unsigned int nbr, int fd, t_sc *sc)
{
	ft_putunsigned_fd(nbr, fd);
	sc->len += ft_uint_len(nbr);
}
