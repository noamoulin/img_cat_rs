/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:35:48 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:31:06 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	is_ws(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

int	ft_atoi(const char *str)
{
	long	i;
	long	nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] && is_ws(str[i]))
		i++;
	if (str[i] && str[i] == '-')
	{
		sign = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (sign == 1)
		return (-nbr);
	return (nbr);
}
