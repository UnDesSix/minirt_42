/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:17:11 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/03 20:46:22 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	sphere_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light)
{
	t_vec	point;
	t_vec	v_normal;
	t_vec	v_light;
	double	visib;

	point = vec_add(ori, vec_mult(dir, rt->t));
	v_normal = vec_normalize(vec_sub(point, rt->last_obj->point1));
	visib = is_visible(rt, light, point);
	if (vec_dot(dir, v_normal) > 0)
//	{
		v_normal = vec_normalize(vec_mult(v_normal, -1));
//		v_light = vec_normalize(vec_sub(vec_mult(light.point, -1), point));
//	}
//	else
		v_light = vec_normalize(vec_sub(light.point, point));
	rt->tmp_color = color_add(rt->tmp_color, color_mult(rt->last_obj->color,
				(light.ratio * vec_dot(v_normal, v_light) * visib /
					pow(vec_length(vec_sub(light.point, point)) / 100, 2))));
//					1)));
}

void	plane_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light)
{
	t_vec	point;
	t_vec	v_normal;
	t_vec	v_light;
	double	visib;

	point = vec_add(ori, vec_mult(dir, rt->t));
	visib = is_visible(rt, light, point);
	v_normal = vec_normalize(rt->last_obj->orient);
	if (vec_dot(dir, v_normal) > 0)
		v_normal = vec_mult(v_normal, -1);
	v_light = vec_normalize(vec_sub(vec_mult(light.point, 1), point));
	rt->tmp_color = color_add(rt->tmp_color, color_mult(rt->last_obj->color,
				(light.ratio * vec_dot(v_normal, v_light) * visib /
					pow(vec_length(vec_sub(light.point, point)) / 100, 2))));
//					1)));
}

void	square_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light)
{
	t_vec	point;
	t_vec	v_normal;
	t_vec	v_light;
	double	visib;

	point = vec_add(ori, vec_mult(dir, rt->t));
	visib = is_visible(rt, light, point);
	v_normal = vec_normalize(rt->last_obj->orient);
	if (vec_dot(dir, v_normal) > 0)
		v_normal = vec_mult(v_normal, -1);
	v_light = vec_normalize(vec_sub(vec_mult(light.point, 1), point));
	rt->tmp_color = color_add(rt->tmp_color, color_mult(rt->last_obj->color,
				(light.ratio * vec_dot(v_normal, v_light) * visib /
					pow(vec_length(vec_sub(light.point, point)) / 100, 2))));
}

void	triangle_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light)
{
	t_vec	point;
	t_vec	v_normal;
	t_vec	v_light;
	t_vec	v1;
	t_vec	v2;
	double	visib;

	point = vec_add(ori, vec_mult(dir, rt->t));
	visib = is_visible(rt, light, point);
	v1 = vec_sub(rt->last_obj->point3, rt->last_obj->point1);
	v2 = vec_sub(rt->last_obj->point2, rt->last_obj->point1);

	v_normal = vec_normalize(vec_cross(v1, v2));
	if (vec_dot(dir, v_normal) > 0)
		v_normal = vec_mult(v_normal, -1);
	v_light = vec_normalize(vec_sub(vec_mult(light.point, 1), point));
	rt->tmp_color = color_add(rt->tmp_color, color_mult(rt->last_obj->color,
				(light.ratio * vec_dot(v_normal, v_light) * visib /
					pow(vec_length(vec_sub(light.point, point)) / 100, 2))));
//					1)));
}

/*
void	cylinder_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light)
{
	t_vec	point;
	t_vec	v_normal;
	t_vec	v_light;
	double	visib;

	point = vec_add(ori, vec_mult(dir, rt->t));
	v_normal = vec_normalize(
				vec_create((rt->last_obj->point1.x /
				sqrt(pow(rt->last_obj->point1.x, 2) + pow(rt->last_obj->point1.y,2))),
				(rt->last_obj->point1.y /
				sqrt(pow(rt->last_obj->point1.x, 2) + pow(rt->last_obj->point1.y,2))), 0));
	visib = is_visible(rt, light, point);
	if (vec_dot(dir, v_normal) > 0)
//	{
		v_normal = vec_normalize(vec_mult(v_normal, -1));
//		v_light = vec_normalize(vec_sub(vec_mult(light.point, -1), point));
//	}
//	else
		v_light = vec_normalize(vec_sub(light.point, point));
	rt->tmp_color = color_add(rt->tmp_color, color_mult(rt->last_obj->color,
				(light.ratio * vec_dot(v_normal, v_light) * visib /
					pow(vec_length(vec_sub(light.point, point)) / 100, 2))));
//					1)));
}*/
