/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:57:52 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:32:36 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	void	cat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
}

char	*ft_strjoin(const char	*s1, const char *s2)
{
	size_t	len;
	char	*output;

	if (!(s1 && s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	output = malloc(len);
	if (!output)
		return (NULL);
	ft_bzero(output, len);
	cat(output, (char *)s1);
	cat(output, (char *)s2);
	return (output);
}
