/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:54:37 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:32:16 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memrchr(const void *offset, int value, size_t length)
{
	unsigned char	*block;
	unsigned char	to_find;

	if (offset)
	{
		block = (unsigned char *)(offset);
		to_find = (unsigned char)(value);
		offset += length;
		while (length && *block != to_find)
		{
			block--;
			length--;
		}
		if (*block == to_find)
		{
			return ((void *)(block));
		}
	}
	return (NULL);
}
