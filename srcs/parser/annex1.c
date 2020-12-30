/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:28:27 by mlarboul          #+#    #+#             */
/*   Updated: 2020/12/30 20:17:05 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

int		contains_two_commas(char *s, char **tab)
{
	int	r_value;
	int	count;

	r_value = 0;
	count = 0;
	while (*s)
	{
		if (*s == ',')
			count++;
		s++;
	}
	if (count == 2)
		r_value = 1;
	if (!r_value)
		free_tab(tab);
	return (r_value);
}

int		ft_is_range(char *s, int id)
{
	float tmp;

	if (id == COLORS)
		tmp = ft_atoi(s);
	else
		tmp = ft_atof(s);
	if (id == COLORS)
		if (tmp < 0 || tmp > 255)
			return (0);
	if (id == ORIENT)
		if (tmp < -1 || tmp > 1)
			return (0);
	if (id == RATIO)
		if (tmp < 0 || tmp > 1)
			return (0);
	return (1);
}

int		ft_is_coord(char *s, int id)
{
	char	**tab;
	int		r_value;
	int		i;

	i = -1;
	r_value = 1;
	tab = ft1_split(s, ",");
	if (!contains_two_commas(s, tab))
		return (0);
	while (tab[++i] && i < 3)
		if (!ft_is_float(tab[i]) || !ft_is_range(tab[i], id))
		{
			free_tab(tab);
			return (0);
		}
	if (i < 3 && tab[3])
		r_value = 0;
	free_tab(tab);
	return (r_value);
}

int		ft_is_float(char *s)
{
	if (s[0] == '.' && s[1] == '\0')
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	while (((*s) && ft_isdigit(*s)))
		s++;
	if (*s == '.')
		s++;
	while (((*s) && ft_isdigit(*s)))
		s++;
	if (!(*s))
		return (1);
	return (0);
}

double	ft_atof(char *s)
{
	double	res;
	int		e;
	int		sign;
	int		c;

	res = 0.0;
	e = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	while ((c = *s++) && ft_isdigit(c))
		res = res * 10.0 + c - '0';
	if (c == '.')
		while ((c = *s++) && ft_isdigit(c))
		{
			res = res * 10.0 + c - '0';
			e -= 1;
		}
	while (e++ < 0)
		res *= 0.1;
	return (res * sign);
}
