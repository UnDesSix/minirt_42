/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 10:56:48 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/05 18:02:54 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void	fill_colors(t_color *elem, char *s)
{
	char	**tab;

	(void)elem;
	tab = ft1_split(s, ",");
	elem->r = ft_atoi(tab[0]);
	elem->g = ft_atoi(tab[1]);
	elem->b = ft_atoi(tab[2]);
	free_tab(tab);
}

void	fill_points(t_vec *elem, char *s)
{
	char	**tab;

	(void)elem;
	tab = ft1_split(s, ",");
	elem->x = ft_atof(tab[0]);
	elem->y = ft_atof(tab[1]);
	elem->z = ft_atof(tab[2]);
	free_tab(tab);
}

