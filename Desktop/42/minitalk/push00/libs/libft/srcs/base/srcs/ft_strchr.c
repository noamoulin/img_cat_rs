/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:58:06 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:32:32 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	index;

	c %= 256;
	index = 0;
	while (str[index] != c && str[index])
		index++;
	if (str[index] == c)
		return ((char *)str + index);
	return (NULL);
}
