/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:12:42 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/19 11:28:43 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *str, size_t start, size_t len)
{
	char	*substr;
	size_t	rlen;

	if (!str)
		return (NULL);
	if (ft_strlen(str) < start)
		return (ft_strdup(""));
	rlen = ft_strlen(str + start);
	if (rlen < len)
		len = rlen;
	substr = stralloc(len);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, str + start, len + 1);
	return (substr);
}
