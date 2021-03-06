/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:21:30 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/14 09:39:01 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ft_triangle(t_saver *rt, t_obj *triangle, t_vec ori, t_vec dir)
{
	t_solve	s;

	s.v1 = vec_sub(triangle->point2, triangle->point1);
	s.v2 = vec_sub(triangle->point3, triangle->point1);
	s.pvec = vec_cross(dir, s.v2);
	s.delta = vec_dot(s.v1, s.pvec);
	if (s.delta < 0.00001 && s.delta > -0.00001)
		return ;
	s.c = 1.0 / s.delta;
	s.tvec = vec_sub(ori, triangle->point1);
	s.a = vec_dot(s.tvec, s.pvec) * s.c;
	if (s.a < 0.0 || s.a > 1.0)
		return ;
	s.tvec = vec_cross(s.tvec, s.v1);
	s.b = vec_dot(dir, s.tvec) * s.c;
	if (s.b < 0.0 || s.a + s.b > 1.0)
		return ;
	s.t1 = vec_dot(s.v2, s.tvec) * s.c;
	if (s.t1 > 0.00001f && s.t1 < rt->t)
	{
		rt->t = s.t1;
		rt->last_obj = triangle;
		rt->flag = 0;
	}
}

int		triangle_shaders(t_saver *rt, t_obj *triangle, t_vec ori, t_vec dir)
{
	t_solve	s;

	s.v1 = vec_sub(triangle->point2, triangle->point1);
	s.v2 = vec_sub(triangle->point3, triangle->point1);
	s.pvec = vec_cross(dir, s.v2);
	s.delta = vec_dot(s.v1, s.pvec);
	if (s.delta < 0.00001 && s.delta > -0.00001)
		return (0);
	s.c = 1.0 / s.delta;
	s.tvec = vec_sub(ori, triangle->point1);
	s.a = vec_dot(s.tvec, s.pvec) * s.c;
	if (s.a < 0.0 || s.a > 1.0)
		return (0);
	s.tvec = vec_cross(s.tvec, s.v1);
	s.b = vec_dot(dir, s.tvec) * s.c;
	if (s.b < 0.0 || s.a + s.b > 1.0)
		return (0);
	s.t1 = vec_dot(s.v2, s.tvec) * s.c;
	if (s.t1 > 0.00001f && s.t1 < rt->t)
	{
		rt->vis_t1 = s.t1;
		return (1);
	}
	return (0);
}
