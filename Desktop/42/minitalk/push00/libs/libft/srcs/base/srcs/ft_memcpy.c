/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:03:05 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:32:09 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t length)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	s = (unsigned char *)(src);
	d = (unsigned char *)(dest);
	while (i < length)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
