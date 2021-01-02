/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:51:07 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/02 22:06:34 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	ft_cylinder(t_mini_rt *rt, t_obj *cylinder, t_vec ori, t_vec dir)
{
	t_solve	s;
	double	delta;

	s.sub = vec_normalize(vec_sub(ori, cylinder->point1));
	s.a = pow((sqrt(pow(dir.x, 2) + pow(dir.y, 2))), 2);
	s.b = 2 * (dir.x * s.sub.x + dir.y * s.sub.y);
	s.c = (pow(dir.x, 2) + pow(dir.y, 2)) - 1;
	delta = pow(s.b, 2) - 4 * s.a *s.c;
	if (delta < 0)
		return ;
	s.t1 = (-s.b - sqrt(delta)) / 2 * s.a;
	s.t2 = (-s.b + sqrt(delta)) / 2 * s.a;
//	rt->flag = 0;
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
