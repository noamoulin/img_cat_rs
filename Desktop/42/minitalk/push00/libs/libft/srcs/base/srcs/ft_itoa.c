/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:15:56 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:31:49 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static unsigned int	my_abs(int nb)
{
	if (nb > 0)
		return (nb);
	return (-nb);
}

static unsigned char	writed_size(int nb)
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

char	*ft_itoa(int nb)
{
	unsigned char	i;
	unsigned int	anb;
	char			*nstr;
	char			tmp_chr;

	if (nb == 0)
		return (ft_strdup("0"));
	else if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	i = writed_size(nb);
	nstr = stralloc(i);
	if (!nstr)
		return (NULL);
	anb = my_abs(nb);
	while (i)
	{
		tmp_chr = anb % 10;
		anb -= tmp_chr;
		anb /= 10;
		nstr[i - 1] = tmp_chr + '0';
		i--;
	}
	if (nb < 0)
		nstr[0] = '-';
	return (nstr);
}
