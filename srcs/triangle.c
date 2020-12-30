/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:21:30 by mlarboul          #+#    #+#             */
/*   Updated: 2020/12/26 14:10:33 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/mini_rt.h"

void	ft_triangle(t_mini_rt *rt, t_obj *triangle, t_vec ori, t_vec dir)
{
	t_solve	s;
	t_vec	v1;
	t_vec	v2;
	t_vec	tvec;
	t_vec	pvec;

	v1 = vec_sub(triangle->point2, triangle->point1);
	v2 = vec_sub(triangle->point3, triangle->point1);
	pvec = vec_cross(dir, v2);
	s.delta = vec_dot(v1, pvec);
	if (fabs(s.delta) < 0.00001)
		return ;
	s.c = 1.0 / s.delta;
	tvec = vec_sub(ori, triangle->point1);
	s.a = vec_dot(tvec, pvec) * s.c;
	if (s.a < 0 || s.a > 1)
		return ;
	tvec = vec_cross(tvec, v1);
	s.b = vec_dot(dir, tvec) * s.c;
	if (s.b < 0 || s.a + s.b > 1)
		return ;
	s.t1 = vec_dot(v2, tvec) * s.c;
	if (s.t1 < 0)
		return ;
	if (s.t1 < rt->t)
	{
		rt->t = s.t1;
		rt->last_obj = triangle;
		rt->flag = 0;
	}
}
