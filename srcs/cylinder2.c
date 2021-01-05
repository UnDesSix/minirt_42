/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:37:32 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/05 17:31:36 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	ft_cylinder(t_mini_rt *rt, t_obj *cylinder, t_vec ori, t_vec dir)
{
	t_solve	s;
	double	delta;

	s.sub = vec_sub(ori, cylinder->point1);

	s.a = pow(dir.x, 2) + pow(dir.z, 2);
	s.b = 2 * (dir.x * s.sub.x + dir.z * s.sub.z);
	s.c = pow(s.sub.x, 2) + pow(s.sub.z, 2) - pow(cylinder->diameter / 2, 2);

	delta = pow(s.b, 2) - 4 * s.a *s.c;

	if (delta < 0)
		return ;
	s.t1 = (-s.b - sqrt(delta)) / (2.0 * s.a);
	s.t2 = (-s.b + sqrt(delta)) / (2.0 * s.a);
	if (s.t1 >= 0 && s.t1 < rt->t)
	{
		rt->t = s.t1;
		printf("rt : %f\n", rt->t);
		rt->last_obj = cylinder;
		rt->flag = 0;
	}
	else if (s.t2 >= 0 && s.t2 < rt->t)
	{
		rt->t = s.t2;
		printf("rt : %f\n", rt->t);
		rt->last_obj = cylinder;
		rt->flag = 0;
	}
}

