/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_filler_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:26:44 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/05 18:05:29 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

int	sphere_filler(char **tab, t_mini_rt *rt)
{
	int	 i;

	i = rt->curr_obj;
	rt->obj[i].type = 1;
	rt->obj[i].id = i;
	fill_points(&rt->obj[i].point1, tab[1]);
	rt->obj[i].diameter = ft_atof(tab[2]);
	fill_colors(&rt->obj[i].color, tab[3]);
	rt->curr_obj++;
	return (0);
}

int	plane_filler(char **tab, t_mini_rt *rt)
{
	int	 i;

	i = rt->curr_obj;
	rt->obj[i].type = 2;
	rt->obj[i].id = i;
	fill_points(&rt->obj[i].point1, tab[1]);
	fill_points(&rt->obj[i].orient, tab[2]);
	fill_colors(&rt->obj[i].color, tab[3]);
	rt->curr_obj++;
	return (0);
}

int	square_filler(char **tab, t_mini_rt *rt)
{
	int	 i;

	i = rt->curr_obj;
	rt->obj[i].type = 3;
	rt->obj[i].id = i;
	fill_points(&rt->obj[i].point1, tab[1]);
	fill_points(&rt->obj[i].orient, tab[2]);
	rt->obj[i].height = ft_atof(tab[3]);
	fill_colors(&rt->obj[i].color, tab[4]);
	rt->curr_obj++;
	return (0);
}

int	cylinder_filler(char **tab, t_mini_rt *rt)
{
	int	 i;

	i = rt->curr_obj;
	rt->obj[i].type = 4;
	rt->obj[i].id = i;
	fill_points(&rt->obj[i].point1, tab[1]);
	fill_points(&rt->obj[i].orient, tab[2]);
	fill_colors(&rt->obj[i].color, tab[3]);
	cylinder_rotation(&rt->obj[i]);
	rt->obj[i].diameter = ft_atof(tab[4]);
	rt->obj[i].height = ft_atof(tab[5]);
	rt->curr_obj++;
	return (0);
}

int	triangle_filler(char **tab, t_mini_rt *rt)
{
	int	 i;

	i = rt->curr_obj;
	rt->obj[i].type = 5;
	rt->obj[i].id = i;
	fill_points(&rt->obj[i].point1, tab[1]);
	fill_points(&rt->obj[i].point2, tab[2]);
	fill_points(&rt->obj[i].point3, tab[3]);
	fill_colors(&rt->obj[i].color, tab[4]);
	rt->curr_obj++;
	return (0);
}

