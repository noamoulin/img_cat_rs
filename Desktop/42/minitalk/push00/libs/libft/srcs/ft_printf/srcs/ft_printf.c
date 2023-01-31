/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:56:21 by nomoulin          #+#    #+#             */
/*   Updated: 2022/12/08 17:56:43 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*argtoa(char format, va_list args)
{
	if (format == '%')
		return (ctoa('%'));
	if (format == 'c')
		return (ctoa((char)va_arg(args, int)));
	if (format == 's')
		return (stoa(va_arg(args, char *)));
	if (format == 'p')
		return (ptoa(va_arg(args, void *)));
	if (format == 'd' || format == 'i')
		return (m_itoa(va_arg(args, int)));
	if (format == 'u')
		return (m_itoa((va_arg(args, unsigned int))));
	if (format == 'x')
		return (lhextoa(va_arg(args, unsigned int)));
	if (format == 'X')
		return (uhextoa((long)va_arg(args, unsigned int)));
	return (NULL);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		index;
	int		len;

	len = 0;
	index = 0;
	va_start(args, str);
	while (str[index])
	{
		if (str[index] == '%')
			len += append_str(argtoa(str[++index], args));
		else
			len += append_chr(str[index], 0);
		index++;
	}
	va_end(args);
	append_chr('a', len % BUFFER_SIZE);
	return (len);
}
