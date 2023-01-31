/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:12:24 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:33:02 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	index;
	char			*s;

	c %= 256;
	s = (char *)(str);
	index = ft_strlen(str);
	while (s[index] != c && index > 0)
		index--;
	if (str[index] == c)
		return (s + index);
	return (NULL);
}
