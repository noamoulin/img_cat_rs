/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:01:15 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:32:56 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*fdes;

	if (!f || !s)
		return (NULL);
	fdes = stralloc(ft_strlen(s));
	if (!fdes)
		return (NULL);
	index = 0;
	while (s[index])
	{
		fdes[index] = f(index, s[index]);
		index++;
	}
	return (fdes);
}
