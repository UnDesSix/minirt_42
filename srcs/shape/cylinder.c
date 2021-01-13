/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:51:07 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/13 07:56:58 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void	cylinder_rotation(t_obj *cylinder)
{
	t_vec	tmp;

	tmp = vec_create(0, 0, -1);
	cylinder->foward = vec_normalize(cylinder->orient);
	if (cylinder->foward.z == 1 || (cylinder->foward.z == -1))
		cylinder->right = vec_normalize(vec_create(1, 0, 0));
	else
		cylinder->right = vec_cross(tmp, cylinder->foward);
	cylinder->up = vec_cross(cylinder->foward, cylinder->right);
	cylinder->foward = vec_normalize(cylinder->foward);
	cylinder->right = vec_normalize(cylinder->right);
}

void	ft_cylinder(t_mini_rt *rt, t_obj *cylinder, t_vec ori, t_vec dir)
{
	t_solve	s;
	double	delta;

	s.sub = vec_sub(ori, cylinder->point1);
	s.a = pow(vec_dot(dir, cylinder->right), 2)
			+ pow(vec_dot(dir, cylinder->up), 2);
	s.b = 2 * (vec_dot(dir, cylinder->right) * vec_dot(s.sub, cylinder->right)
				+ vec_dot(dir, cylinder->up) * vec_dot(s.sub, cylinder->up));
	s.c = pow(vec_dot(s.sub, cylinder->right), 2)
			+ pow(vec_dot(s.sub, cylinder->up), 2)
				- (pow((cylinder->diameter / 2.0), 2));
	delta = pow(s.b, 2) - 4 * s.a * s.c;
	if (delta < 0)
		return ;
	s.t1 = (-s.b - sqrt(delta)) / (2.0 * s.a);
	s.t2 = (-s.b + sqrt(delta)) / (2.0 * s.a);
	if (s.t1 >= 0 && s.t1 < rt->t)
		if (ft_cylinder2(rt, cylinder, s.t1, vec_add(ori, vec_mult(dir, s.t1))))
			return ;
	if (s.t2 >= 0 && s.t2 < rt->t)
		if (ft_cylinder2(rt, cylinder, s.t2, vec_add(ori, vec_mult(dir, s.t2))))
			return ;
}

int		ft_cylinder2(t_mini_rt *rt, t_obj *cylinder, float t, t_vec point)
{
	double	z;

	z = vec_dot(vec_sub(point, cylinder->point1), cylinder->foward);
	if (fabs(z) > cylinder->height / 2.0)
		return (0);
	rt->t = t;
	rt->last_obj = cylinder;
	rt->flag = 0;
	return (1);
}

int		cylinder2_sh(t_mini_rt *rt, t_obj *cylinder, float t, t_vec point)
{
	double	z;

	z = vec_dot(vec_sub(point, cylinder->point1), cylinder->foward);
	if (fabs(z) > cylinder->height / 2.0)
		return (0);
	rt->vis_t1 = t;
	return (1);
}

int		cylinder_shaders(t_mini_rt *rt, t_obj *cylinder, t_vec ori, t_vec dir)
{
	t_solve	s;
	double	delta;

	s.sub = vec_sub(ori, cylinder->point1);
	s.a = pow(vec_dot(dir, cylinder->right), 2)
			+ pow(vec_dot(dir, cylinder->up), 2);
	s.b = 2 * (vec_dot(dir, cylinder->right) * vec_dot(s.sub, cylinder->right)
				+ vec_dot(dir, cylinder->up) * vec_dot(s.sub, cylinder->up));
	s.c = pow(vec_dot(s.sub, cylinder->right), 2)
			+ pow(vec_dot(s.sub, cylinder->up), 2)
				- (pow((cylinder->diameter / 2.0), 2));
	delta = pow(s.b, 2) - 4 * s.a * s.c;
	if (delta < 0)
		return (0);
	s.t1 = (-s.b - sqrt(delta)) / (2.0 * s.a);
	s.t2 = (-s.b + sqrt(delta)) / (2.0 * s.a);
	if (s.t1 > 0)
		if (cylinder2_sh(rt, cylinder, s.t1, vec_add(ori, vec_mult(dir, s.t1))))
			return (1);
	if (s.t2 > 0)
		if (cylinder2_sh(rt, cylinder, s.t2, vec_add(ori, vec_mult(dir, s.t2))))
			return (1);
	return (0);
}
