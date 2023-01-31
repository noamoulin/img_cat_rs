/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:26:37 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:43:19 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*stralloc(size_t len)
{
	char	*str;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}
