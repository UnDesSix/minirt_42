/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:21:02 by mlarboul          #+#    #+#             */
/*   Updated: 2020/12/31 15:09:51 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	amb_light(t_mini_rt *rt)
{
	rt->tmp_color.r = min_max_colors((rt->tmp_color.r + rt->amb.ratio
												* rt->last_obj->color.r));
	rt->tmp_color.g = min_max_colors((rt->tmp_color.g + rt->amb.ratio
												* rt->last_obj->color.g));
	rt->tmp_color.b = min_max_colors((rt->tmp_color.b + rt->amb.ratio
												* rt->last_obj->color.b));
}

void	init_color(t_mini_rt *rt)
{
	rt->tmp_color.r = 0;
	rt->tmp_color.g = 0;
	rt->tmp_color.b = 0;
}

t_color	color_add(t_color c1, t_color c2)
{
	t_color	c;

	c.r = min_max_colors(c1.r + c2.r);
	c.g = min_max_colors(c1.g + c2.g);
	c.b = min_max_colors(c1.b + c2.b);
	return (c);
}

t_color	color_mult(t_color c1, float nb)
{
	t_color	c;

	c.r = min_max_colors(c1.r * nb);
	c.g = min_max_colors(c1.g * nb);
	c.b = min_max_colors(c1.b * nb);
	return (c);
}

float	min_max_colors(float color)
{
	if (color > 255)
		return (255);
	else if (color < 0)
		return (0);
	return (color);
}

void	apply_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light)
{
	if (rt->last_obj->type == SPHERE)
		sphere_light(rt, ori, dir, light);
	if (rt->last_obj->type == PLANE)
{
		
		plane_light(rt, ori, dir, light);
}
/*
	if (rt->last_obj->type == SQUARE)
		square_light(rt, ori, dir, light);
	if (rt->last_obj->type == CYLINDER)
		cylinder_light(rt, ori, dir, light);
*/
	if (rt->last_obj->type == TRIANGLE)
		triangle_light(rt, ori, dir, light);
}
