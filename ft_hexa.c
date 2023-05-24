/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:32:24 by mabdali           #+#    #+#             */
/*   Updated: 2023/02/22 10:38:56 by mabdali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

void	ft_print_hexa(unsigned long nbr, char format)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar_fd(base[nbr], 1);
	if (nbr >= 16)
	{
		ft_print_hexa(nbr / 16, format);
		ft_print_hexa(nbr % 16, format);
	}
}

void	ft_put_x(unsigned int nbr, char format, t_sc *sc)
{
	ft_print_hexa(nbr, format);
	if (nbr == 0)
		sc->len += 1;
	else
		sc->len += ft_hex_len(nbr);
}

void	ft_put_p(unsigned long nbr, t_sc *sc)
{
	if (nbr == 0)
	{
		write (1, "(nil)", 5);
		sc->len += 5;
	}
	else
	{
		write (1, "0x", 2);
		ft_print_hexa(nbr, 'x');
		sc->len += ft_hex_len(nbr) + 2;
	}
}
