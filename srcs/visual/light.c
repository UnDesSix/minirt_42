/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:21:02 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/08 22:53:49 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	amb_light(t_mini_rt *rt)
{
	rt->tmp_color.r = min_max_colors((rt->tmp_color.r + sqrt((rt->amb.ratio
	* rt->amb.color.r) * (rt->last_obj->color.r))));
	rt->tmp_color.g = min_max_colors((rt->tmp_color.g + sqrt((rt->amb.ratio
	* rt->amb.color.g) * (rt->last_obj->color.g))));
	rt->tmp_color.b = min_max_colors((rt->tmp_color.b + sqrt((rt->amb.ratio
	* rt->amb.color.b) * (rt->last_obj->color.b))));
}

void	apply_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light)
{
	if (rt->last_obj->type == SPHERE)
		sphere_light(rt, ori, dir, light);
	if (rt->last_obj->type == PLANE)
		plane_light(rt, ori, dir, light);
	if (rt->last_obj->type == SQUARE)
		square_light(rt, ori, dir, light);
	if (rt->last_obj->type == TRIANGLE)
		triangle_light(rt, ori, dir, light);
	if (rt->last_obj->type == CYLINDER)
		cylinder_light(rt, ori, dir, light);
}
