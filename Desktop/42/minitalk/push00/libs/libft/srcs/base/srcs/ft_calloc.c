/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:45:23 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:31:14 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <limits.h>

#define SIZE_T_MAX 18446744073709551615UL

void	*ft_calloc(size_t nb, size_t size)
{
	void	*ptr;

	if (!nb)
		return (malloc(0));
	if (size && SIZE_T_MAX / nb < size)
		return (NULL);
	size *= nb;
	ptr = malloc(size);
	if (ptr)
		ft_bzero(ptr, size);
	return (ptr);
}
