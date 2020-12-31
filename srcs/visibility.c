/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 09:39:22 by mlarboul          #+#    #+#             */
/*   Updated: 2020/12/31 13:26:44 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int		is_visible(t_mini_rt *rt, t_light light, t_vec ori)
{
	int		k;
	t_vec	dir;
	t_vec	point2;
	float	l1;
	float	l2;

	k = 0;
	dir = vec_sub(light.point, ori);
	while (k < rt->curr_obj)
	{
		if (k != rt->last_obj->id && rt->obj[k].type == SPHERE &&
				ft_sphere_light(rt, &rt->obj[k], ori, dir))
		{
			point2 = vec_add(ori, vec_mult(dir, fabs(rt->vis_t1)));
			l1 = vec_length(vec_sub(ori, light.point));
			l2 = vec_length(vec_sub(ori, point2));
			if (l2 > l1)
			{
				return (0);
			}
		}
		k++;
	}
	return (1);
}
