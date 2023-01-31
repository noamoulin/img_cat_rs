/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:41:22 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:32:29 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	get_sstr_number(char *str, char c)
{
	unsigned int	was_on_sep;
	size_t			number;

	number = 0;
	was_on_sep = 1;
	while (*str)
	{
		if (was_on_sep && *str != c)
		{
			number++;
			was_on_sep = 0;
		}
		else if (*str == c)
		{
			was_on_sep = 1;
		}
		str++;
	}
	return (number);
}

static char	*grab_until(char *str, char end)
{
	size_t	seqlen;

	seqlen = 0;
	while (str[seqlen] && str[seqlen] != end)
		seqlen++;
	if (seqlen)
	{
		return (ft_substr(str, 0, seqlen));
	}
	return (NULL);
}

static char	**kalloc(char *str, char c)
{
	size_t	hmw;
	char	**kontainer;

	hmw = get_sstr_number(str, c);
	kontainer = malloc(sizeof(char *) * (hmw + 1));
	if (kontainer)
	{
		kontainer[hmw] = NULL;
		return (kontainer);
	}
	return (NULL);
}

static char	**free_kontainer(char **kontainer)
{
	while (*kontainer)
	{
		free(kontainer);
		kontainer++;
	}
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	size_t			kindex;
	char			*str;
	char			**kontainer;
	char			*tmp_str;

	if (!s)
		return (NULL);
	str = (char *)(s);
	kontainer = kalloc(str, c);
	if (!kontainer)
		return (NULL);
	kindex = 0;
	while (*str)
	{
		if ((*(str - (str > s)) == c || str == s) && *str != c)
		{
			tmp_str = grab_until(str, c);
			if (!tmp_str)
				return (free_kontainer(kontainer));
			kontainer[kindex] = tmp_str;
			kindex++;
		}
		str++;
	}
	return (kontainer);
}
