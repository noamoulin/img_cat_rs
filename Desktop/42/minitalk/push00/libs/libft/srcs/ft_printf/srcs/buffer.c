/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:37:48 by nomoulin          #+#    #+#             */
/*   Updated: 2022/12/08 17:54:03 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	m_bzero(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
		buffer[i++] = 0;
}

int	append_chr(char chr, int len)
{
	static char	buffer[BUFFER_SIZE];
	static int	current_index = 0;

	if (len)
	{
		write(STDOUT_FILENO, buffer, len);
		current_index = 0;
		m_bzero(buffer);
	}
	else if (current_index < BUFFER_SIZE)
		buffer[current_index++] = chr;
	else
	{
		write(STDOUT_FILENO, buffer, BUFFER_SIZE);
		current_index = 0;
		m_bzero(buffer);
		buffer[0] = chr;
		current_index = 1;
	}
	return (1);
}

int	append_str(char *str)
{
	char	current_chr;
	int		len;

	if (!str)
		return (0);
	if (!(*str))
	{
		append_chr(0, 0);
		return (1);
	}
	len = 0;
	current_chr = *str;
	while (current_chr)
	{
		append_chr(current_chr, 0);
		len++;
		current_chr = *(++str);
	}
	return (len);
}
