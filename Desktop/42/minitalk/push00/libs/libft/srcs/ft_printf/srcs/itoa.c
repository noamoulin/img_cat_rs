/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:11:21 by nomoulin          #+#    #+#             */
/*   Updated: 2022/12/08 16:14:04 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_LEN_DEC 12

static void	m_bzero(char *buffer)
{
	int	i;

	i = 0;
	while (i < MAX_LEN_DEC)
		buffer[i++] = 0;
}

static int	writed_hex_size(long nbr)
{
	int	size;

	size = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

static long long	m_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*m_itoa(long n)
{
	static char	output[MAX_LEN_DEC];
	long		nb;
	int			digit;
	int			index;

	m_bzero(output);
	nb = m_abs(n);
	index = writed_hex_size(nb) - (n > 0);
	while (nb)
	{
		digit = nb % 10;
		output[index--] = digit + '0';
		nb /= 10;
	}
	if (n < 0)
		output[0] = '-';
	else if (!n)
		output[0] = '0';
	return (output);
}
