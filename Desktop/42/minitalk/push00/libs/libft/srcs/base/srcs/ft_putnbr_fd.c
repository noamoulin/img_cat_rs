/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:18:42 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:32:22 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static long	my_abs(long nb)
{
	if (nb > 0)
		return (nb);
	return (-nb);
}

static unsigned char	writed_size(long nb)
{
	size_t	size;

	if (nb < 0)
	{
		size = 2;
		nb = -nb;
	}
	else
		size = 1;
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

void	my_itoa(int nb, char *buffer)
{
	unsigned char	i;
	long			anb;
	char			tmp_chr;

	i = writed_size((long)(nb));
	anb = my_abs(nb);
	while (i)
	{
		tmp_chr = anb % 10;
		anb -= tmp_chr;
		anb /= 10;
		buffer[i - 1] = tmp_chr + '0';
		i--;
	}
	if (nb < 0)
		buffer[0] = '-';
}

void	ft_putnbr_fd(int nb, int fd)
{
	char	buffer[20];

	ft_bzero(buffer, 20);
	my_itoa(nb, buffer);
	write(fd, buffer, ft_strlen(buffer));
}
