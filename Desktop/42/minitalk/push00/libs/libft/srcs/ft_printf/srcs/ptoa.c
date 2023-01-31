/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:19:30 by nomoulin          #+#    #+#             */
/*   Updated: 2022/12/08 16:39:54 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define MAX_LEN 19

static void	m_bzero(char *buffer)
{
	int	i;

	i = 0;
	while (i < MAX_LEN)
	{
		buffer[i++] = 0;
	}
}

static char	hexof(int digit)
{
	char	*dict;

	dict = "0123456789abcdef";
	return (dict[digit]);
}

static int	writed_hex_size(unsigned long nbr)
{
	int	size;

	size = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		size++;
	}
	return (size);
}

char	*ptoa(void *ptr)
{
	unsigned long	ptr_val;
	static char		output[MAX_LEN];
	int				digit;
	int				index;

	m_bzero(output);
	if (!ptr)
		cat_str(output, "(nil)");
	else
	{
		ptr_val = (unsigned long)(ptr);
		index = writed_hex_size(ptr_val) + 1;
		cat_str(output, "0x");
		while (ptr_val)
		{
			digit = ptr_val % 16;
			output[index--] = hexof(digit);
			ptr_val /= 16;
		}
	}
	return (output);
}
