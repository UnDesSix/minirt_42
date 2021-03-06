/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_filler_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:44:43 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/14 10:20:03 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_fct	identify_type_2(char *s)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s_len == 1 && !strncmp(s, "R", 1))
		return (resolution_filler);
	else if (s_len == 1 && !strncmp(s, "A", 1))
		return (ambient_filler);
	else if (s_len == 1 && !strncmp(s, "c", 1))
		return (camera_filler);
	else if (s_len == 1 && !strncmp(s, "l", 1))
		return (light_filler);
	else if (s_len == 2 && !strncmp(s, "sp", 2))
		return (sphere_filler);
	else if (s_len == 2 && !strncmp(s, "pl", 2))
		return (plane_filler);
	else if (s_len == 2 && !strncmp(s, "sq", 2))
		return (square_filler);
	else if (s_len == 2 && !strncmp(s, "cy", 2))
		return (cylinder_filler);
	else if (s_len == 2 && !strncmp(s, "tr", 2))
		return (triangle_filler);
	return (0);
}

int		resolution_filler(char **tab, t_saver *rt)
{
	rt->res.w = ft_atoi(tab[1]);
	rt->res.h = ft_atoi(tab[2]);
	return (0);
}

int		ambient_filler(char **tab, t_saver *rt)
{
	rt->amb.ratio = ft_atof(tab[1]);
	fill_colors(&rt->amb.color, tab[2]);
	return (0);
}

int		camera_filler(char **tab, t_saver *rt)
{
	fill_points(&rt->cam[rt->curr_cam].pov, tab[1]);
	fill_points(&rt->cam[rt->curr_cam].orient, tab[2]);
	rt->cam[rt->curr_cam].fov = ft_atof(tab[3]);
	compute_rotation(rt, rt->curr_cam);
	rt->curr_cam++;
	return (0);
}

int		light_filler(char **tab, t_saver *rt)
{
	fill_points(&rt->light[rt->curr_light].point, tab[1]);
	rt->light[rt->curr_light].ratio = ft_atof(tab[2]);
	fill_colors(&rt->light[rt->curr_light].color, tab[3]);
	rt->curr_light++;
	return (0);
}
