/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:26:46 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 17:39:55 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	getstart(const char *s1, const char *set, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	return (i);
}

size_t	getend(const char *s1, const char *set, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (!ft_strchr(set, s1[len - i - 1]))
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	size_t		start;
	size_t		end;
	char		*trimmed_str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	start = getstart(s1, set, len);
	end = getend(s1, set, len);
	if (start >= end)
		return (ft_strdup(""));
	trimmed_str = stralloc(end - start);
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, s1 + start, end - start + 1);
	return (trimmed_str);
}
