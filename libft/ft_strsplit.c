/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:37:40 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/25 21:20:52 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		separate(char b, char c)
{
	if (b == c || b == '\0')
		return (1);
	return (0);
}

static int		ft_wordlen(const char *s, int j, char c)
{
	int		i;

	i = 0;
	while (!separate(s[j], c))
	{
		i++;
		j++;
	}
	return (i);
}

static int		count_word(const char *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if ((separate(s[i], c) == 0) && (separate(s[i + 1], c) == 1))
			word++;
		i++;
	}
	return (word);
}

static char		**ft_split(char const *s, char **tab, char c)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (separate(s[i], c))
			i++;
		else
		{
			if (!(tab[k] = ft_strnew(ft_wordlen(s, i, c) + 1)))
				return (NULL);
			j = 0;
			while (!separate(s[i], c))
				tab[k][j++] = s[i++];
			tab[k++][j] = '\0';
		}
	}
	tab[k] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	tab = NULL;
	if (s)
	{
		if (!(tab = ft_tabnew((size_t)count_word(s, c))))
			return (NULL);
	}
	else
		return (NULL);
	return (ft_split(s, tab, c));
}
