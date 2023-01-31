/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:24:49 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:32:07 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *block, int value, size_t length)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)(block);
	i = 0;
	while (i < length)
	{
		if (ptr[i] == (unsigned char)value)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
