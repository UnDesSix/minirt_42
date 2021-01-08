/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 09:39:22 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/08 14:41:30 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int		apply_shaders(t_mini_rt *rt, t_obj *obj, t_vec ori, t_vec dir)
{
	if (obj->type == SPHERE)
		return (sphere_shaders(rt, obj, ori, dir));
	else if (obj->type == PLANE)
		return (plane_shaders(rt, obj, ori, dir));
	else if (obj->type == TRIANGLE)
		return (triangle_shaders(rt, obj, ori, dir));
	else if (obj->type == SQUARE)
		return (square_shaders(rt, obj, ori, dir));
	else if (obj->type == CYLINDER)
		return (cylinder_shaders(rt, obj, ori, dir));
	return (0);
}


int		is_visible(t_mini_rt *rt, t_light light, t_vec ori, t_vec normal)
{
	int		k;
	t_vec	dir;
	t_vec	point2;
	double	l1;
	double	l2;

	k = 0;
	ori = vec_add(ori, vec_mult(normal, 0.0001));
	dir = vec_normalize(vec_sub(light.point, ori));
	while (k < rt->curr_obj)
	{
		if (apply_shaders(rt, &rt->obj[k], ori, dir))
		{
			if (k == rt->last_obj->id && rt->last_obj->type == SPHERE)
				return (1);
			point2 = vec_add(ori, vec_mult(dir, rt->vis_t1));
			l1 = vec_length(vec_sub(light.point, ori));
			l2 = vec_length(vec_sub(point2, ori));
			if (l2 < l1)
				return (0);
		}
		k++;
	}
	return (1);
}
