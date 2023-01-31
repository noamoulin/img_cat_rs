/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:18:50 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:32:08 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t length)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			i;

	i = 0;
	b1 = (unsigned char *)(s1);
	b2 = (unsigned char *)(s2);
	while (i < length)
	{
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
		i++;
	}
	return (0);
}
