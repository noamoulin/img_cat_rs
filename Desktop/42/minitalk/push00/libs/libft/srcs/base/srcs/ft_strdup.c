/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:38:31 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:32:33 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char	*str)
{
	size_t	i;
	size_t	size;
	char	*copy;

	size = ft_strlen(str);
	copy = stralloc(size);
	if (!copy)
		return (copy);
	i = 0;
	while (i < size)
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}
