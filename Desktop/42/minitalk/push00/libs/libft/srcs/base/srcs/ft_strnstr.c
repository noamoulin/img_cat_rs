/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:41:49 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:33:00 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *str, const char *sstr, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*start;

	if ((!str || !sstr) && !len)
		return (NULL);
	i = 0;
	start = (char *)str;
	n_len = ft_strlen(sstr);
	if (n_len == 0 || str == sstr)
		return (start);
	while (start[i] != '\0' && i < len)
	{
		j = 0;
		while (start[i + j] != '\0' && sstr[j] != '\0'
			&& start[i + j] == sstr[j] && i + j < len)
			j++;
		if (j == n_len)
			return (start + i);
		i++;
	}
	return (NULL);
}
