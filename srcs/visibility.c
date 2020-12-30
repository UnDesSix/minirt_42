/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 09:39:22 by mlarboul          #+#    #+#             */
/*   Updated: 2020/12/30 23:06:14 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int		is_visible(t_mini_rt *rt, t_light light, t_vec point)
{
	int		r_value;
	int		k;
	t_vec	dir;
	t_vec	point2;
	float	l1;
	float	l2;

	k = 0;
	dir = vec_sub(point, light.point);
	r_value = 1;
	rt->vis_t1 = 3.402823E+38;
	while (r_value && k < rt->curr_obj)
	{
		if (k != rt->last_obj->id &&
				ft_sphere_light(rt, rt->last_obj, point, dir))
		{
			point2 = vec_add(point, vec_mult(dir, rt->vis_t1));
			l1 = vec_length(vec_sub(light.point, point));
			l2 = vec_length(vec_sub(point, point2));
			if (l2 < l1)
				return (0);
		}
		k++;
	}
	return (r_value);
}
