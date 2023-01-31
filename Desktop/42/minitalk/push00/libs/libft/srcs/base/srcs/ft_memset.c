/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:50:29 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:32:17 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *offset, int value, size_t length)
{
	unsigned char	*o;

	o = (unsigned char *)(offset);
	while (length)
	{
		o[length - 1] = value;
		length--;
	}
	return (offset);
}
