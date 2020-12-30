/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:44:29 by mlarboul          #+#    #+#             */
/*   Updated: 2020/12/20 10:02:48 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		ft1_is_sep(char *charset, char c)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft1_strdup_spe(char *src, char *charset)
{
	int		i;
	char	*dst;

	i = 0;
	while (!ft1_is_sep(charset, src[i]) && src[i])
		i++;
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (!ft1_is_sep(charset, src[i]) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft1_tab_n_str_size(char *str, char *charset, int *count_bis)
{
	int		i;
	int		count;
	char	**tab;

	i = 0;
	count = 0;
	while (str[i] && ft1_is_sep(charset, str[i]))
		i++;
	while (str[i])
	{
		count++;
		while (str[i] && !ft1_is_sep(charset, str[i]))
			i++;
		while (str[i] && ft1_is_sep(charset, str[i]))
			i++;
	}
	if (!(tab = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	*count_bis = count;
	tab[count] = NULL;
	return (tab);
}

char	**ft1_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		count;
	char	**tab;

	if (!str || !charset)
		return (NULL);
	if (!(tab = ft1_tab_n_str_size(str, charset, &count)))
		return (NULL);
	i = 0;
	j = 0;
	while (j < count)
	{
		while (ft1_is_sep(charset, str[i]))
			i++;
		if (str[i])
		{
			tab[j++] = ft1_strdup_spe(str + i, charset);
			while (!ft1_is_sep(charset, str[i]) && str[i])
				i++;
		}
	}
	return (tab);
}
