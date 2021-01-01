/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:21:37 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/01 20:49:56 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	ft_sphere(t_mini_rt *rt, t_obj *sphere, t_vec ori, t_vec dir)
{
	t_solve	s;
	double	delta;

	s.sub = vec_sub(ori, sphere->point1);
	s.a = pow(vec_length(dir), 2);
	s.b = 2 * vec_dot(dir, s.sub);
	s.c = pow(vec_length(s.sub), 2) - pow(sphere->diameter / 2, 2);
	delta = pow(s.b, 2) - 4 * s.a *s.c;
	if (delta < 0)
		return ;
	s.t1 = (-s.b - sqrt(delta)) / 2 * s.a;
	s.t2 = (-s.b + sqrt(delta)) / 2 * s.a;
//	rt->flag = 0;
	if (s.t1 >= 0 && s.t1 < rt->t)
	{
		rt->t = s.t1;
		rt->last_obj = sphere;
		rt->flag = 0;
	}
	else if (s.t2 >= 0 && s.t2 < rt->t)
	{
		rt->t = s.t2;
		rt->last_obj = sphere;
		rt->flag = 0;
	}
}

double	ft_sphere_light(t_mini_rt *rt, t_obj *sphere, t_vec ori, t_vec dir)
{
	t_solve	s;
	double	delta;

	s.sub = vec_sub(ori, sphere->point1);
	s.a = pow(vec_length(dir), 2);
	s.b = 2 * vec_dot(dir, s.sub);
	s.c = pow(vec_length(s.sub), 2) - pow(sphere->diameter / 2, 2);
	delta = pow(s.b, 2) - 4 * s.a *s.c;
	if (delta < 0)
		return (0);
	s.t1 = (-s.b - sqrt(delta)) / 2 * s.a;
	s.t2 = (-s.b + sqrt(delta)) / 2 * s.a;
	if (s.t1 >= 0)
	{
		rt->vis_t1 = s.t1;
		return (1);
	}
	else if (s.t2 >= 0)
	{
		rt->vis_t1 = s.t2;
		return (1);
	}
	return (0);
}
