/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:45:53 by nomoulin          #+#    #+#             */
/*   Updated: 2022/12/08 16:26:04 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*stoa(char *str)
{
	static char	*null;

	if (!str)
	{
		null = "(null)";
		return (null);
	}
	if (!str[0])
		return (NULL);
	return (str);
}
