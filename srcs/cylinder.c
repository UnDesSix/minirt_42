/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:51:07 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/04 21:05:44 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	ft_cylinder(t_mini_rt *rt, t_obj *cylinder, t_vec ori, t_vec dir)
{
	t_solve	s;
	double	delta;
	t_vec	new_ray;

//	cylinder->orient = vec_normalize(cylinder->orient);
//	new_ray = vec_cross(dir, cylinder->orient);
	s.sub = vec_sub(ori, cylinder->point1);
//	s.a = vec_dot(new_ray, new_ray);
//	s.b = 2 * vec_dot(new_ray, vec_cross(s.sub, cylinder->orient));
//	s.c =vec_dot(vec_cross(s.sub, cylinder->orient), vec_cross(s.sub, cylinder->orient)) - (pow(cylinder->diameter / 2, 2));

	
	s.a = (pow(dir.x, 2) + pow(dir.z, 2));
	s.b = 2 * (dir.x * s.sub.x + dir.z * s.sub.z);
	s.c = (pow(s.sub.x, 2) + pow(s.sub.z, 2)) - 1;

	delta = pow(s.b, 2) - 4 * s.a *s.c;
	if (delta < 0)
		return ;
	s.t1 = (-s.b - sqrt(delta)) / 2 * s.a;
	s.t2 = (-s.b + sqrt(delta)) / 2 * s.a;
	if (s.t1 >= 0 && s.t1 < rt->t)
	{
		rt->t = s.t1;
		rt->last_obj = cylinder;
		rt->flag = 0;
	}
	else if (s.t2 >= 0 && s.t2 < rt->t)
	{
		rt->t = s.t2;
		rt->last_obj = cylinder;
		rt->flag = 0;
	}
}

/*
int		cylinder_shaders(t_mini_rt *rt, t_obj *sphere, t_vec ori, t_vec dir)
{
}
*/
