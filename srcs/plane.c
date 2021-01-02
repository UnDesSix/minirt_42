/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:21:30 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/02 12:33:07 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/mini_rt.h"

void	ft_plane(t_mini_rt *rt, t_obj *obj, t_vec ori, t_vec dir)
{
	t_solve	s;

	s.a = vec_dot(obj->orient, vec_sub(ori, obj->point1));
	s.b = vec_dot(obj->orient, dir);
	if (!s.b)
		return ;
	s.t1 = -s.a / s.b;
//	if (s.t1 >= 0)
	if (s.t1 >= 0 && s.t1 < rt->t)
	{
		rt->t = s.t1;
		rt->last_obj = obj;
		rt->flag = 0;
	}
}

int		plane_shaders(t_mini_rt *rt, t_obj *plane, t_vec ori, t_vec dir)
{
	t_solve	s;

	s.a = vec_dot(plane->orient, vec_sub(ori, plane->point1));
	s.b = vec_dot(plane->orient, dir);
	if (!s.b)
		return (0);
	s.t1 = -s.a / s.b;
	if (s.t1 >= 0)
	{
		rt->vis_t1 = s.t1;
		return (1);
	}
	return (0);
}
