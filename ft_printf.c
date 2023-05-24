/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:04:14 by mabdali           #+#    #+#             */
/*   Updated: 2023/02/16 19:02:43 by mabdali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

const char	*ft_search_arg(va_list arg, const char *format, t_sc *sc)
{
	if (*format == 'c')
		ft_put_c((char)va_arg(arg, int), 1, sc);
	else if (*format == 's')
		ft_put_s(va_arg(arg, char *), 1, sc);
	else if (*format == 'p')
		ft_put_p(va_arg(arg, unsigned long), sc);
	else if (*format == 'd' || *format == 'i')
		ft_put_di(va_arg(arg, int), 1, sc);
	else if (*format == 'u')
		ft_put_u((unsigned int)va_arg(arg, unsigned int), 1, sc);
	else if (*format == 'x' || *format == 'X')
		ft_put_x(va_arg(arg, unsigned int), *format, sc);
	else if (*format == '%')
		ft_put_percent(1, sc);
	else
		return (NULL);
	format++;
	return (format);
}

char	*ft_percent_search(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return ((char *)s);
		s++;
	}
	if (!s)
		return ((char *)s);
	return (NULL);
}

const char	*ft_read_text(t_sc *sc, const char *format)
{
	char	*next;

	next = ft_percent_search(format);
	if (next)
		sc->width = next - format;
	else
		sc->width = ft_strlen(format);
	write(1, format, sc->width);
	sc->len += sc->width;
	while (*format && *format != '%')
		format++;
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	t_sc	sc;

	va_start(arg, format);
	sc.len = 0;
	sc.width = 0;
	while (*format)
	{
		if (*format == '%')
			format = ft_search_arg(arg, format + 1, &sc);
		else
			format = ft_read_text(&sc, format);
		if (!format)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (sc.len);
		}
	}
	va_end(arg);
	return (sc.len);
}
