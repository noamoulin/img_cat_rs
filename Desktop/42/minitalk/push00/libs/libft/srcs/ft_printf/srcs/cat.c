/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:29:36 by nomoulin          #+#    #+#             */
/*   Updated: 2022/12/08 16:32:42 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	cat(char *buffer, char chr)
{
	while (*buffer)
		buffer++;
	*buffer = chr;
}

void	cat_str(char *buffer, char *str)
{
	char	current_chr;

	current_chr = *str;
	while (current_chr)
	{
		cat(buffer, current_chr);
		current_chr = *(++str);
	}
}
