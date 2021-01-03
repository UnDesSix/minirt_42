/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:50:11 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/03 18:37:27 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int		is_in_square(t_obj *square, t_vec point)
{
	if (fabs(point.x - square->point1.x) > (square->height / 2)
			|| (fabs(point.y - square->point1.y) > (square->height / 2))
				|| (fabs(point.z - square->point1.z) > (square->height / 2)))
		return (0);
	return (1);
}


void	ft_square(t_mini_rt *rt, t_obj *square, t_vec ori, t_vec dir)
{
	t_solve	s;
	t_vec	point;

	s.a = vec_dot(vec_normalize(square->orient), vec_sub(ori, square->point1));
	s.b = vec_dot(vec_normalize(square->orient), dir);
	if (!s.b)
		return ;
	s.t1 = -s.a / s.b;
	if (s.t1 >= 0 && s.t1 < rt->t)
	{
		point = vec_add(ori, vec_mult(dir, s.t1));
		if (!is_in_square(square, point))
			return ;
		rt->t = s.t1;
		rt->last_obj = square;
		rt->flag = 0;
	}
}

int		square_shaders(t_mini_rt *rt, t_obj *square, t_vec ori, t_vec dir)
{
	t_solve	s;
	t_vec	point;

	s.a = vec_dot(vec_normalize(square->orient), vec_sub(ori, square->point1));
	s.b = vec_dot(vec_normalize(square->orient), dir);
	if (!s.b)
		return (0);
	s.t1 = -s.a / s.b;
	if (s.t1 >= 0)
	{
		point = vec_add(ori, vec_mult(dir, s.t1));
		if (!is_in_square(square, point))
			return (0);
		rt->vis_t1 = s.t1;
		return (1);
	}
	return (0);
}
