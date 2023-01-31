/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lhextoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:15:27 by nomoulin          #+#    #+#             */
/*   Updated: 2022/12/08 16:26:01 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_LEN_HEX 17

static void	m_bzero(char *buffer)
{
	int	i;

	i = 0;
	while (i < MAX_LEN_HEX)
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

static int	writed_hex_size(unsigned int nbr)
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

char	*lhextoa(unsigned int n)
{
	unsigned int	nb;
	static char		output[MAX_LEN_HEX];
	int				digit;
	int				index;

	m_bzero(output);
	nb = n;
	index = writed_hex_size(nb) - 1;
	output[index + 1] = '\0';
	while (nb)
	{
		digit = nb % 16;
		output[index--] = hexof(digit);
		nb /= 16;
	}
	if (!n)
		output[0] = '0';
	return (output);
}
