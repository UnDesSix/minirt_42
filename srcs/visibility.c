/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 09:39:22 by mlarboul          #+#    #+#             */
/*   Updated: 2020/12/31 15:18:18 by mlarboul         ###   ########.fr       */
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
	dir = vec_normalize(vec_sub(light.point, ori));
	while (k < rt->curr_obj)
	{
		if (k != rt->last_obj->id && rt->obj[k].type == SPHERE &&
				ft_sphere_light(rt, &rt->obj[k], ori, dir))
		{
			point2 = vec_add(ori, vec_mult(dir, rt->vis_t1));
			l1 = vec_length(vec_sub(light.point, ori));
			l2 = vec_length(vec_sub(point2, ori));
			if (l2 < l1)
				return (0);
		}
		k++;
	}
	return (1);
}
			/*
				printf("l1 : %f\n", l1);
				printf("l2 : %f\n", l2);
				printf("t1 : %f\n", rt->vis_t1);
				printf("ori    : %f, %f, %f\n", ori.x, ori.y, ori.z);
				printf("light  : %f, %f, %f\n", light.point.x, light.point.y, light.point.z);
				printf("point2 : %f, %f, %f\n\n", point2.x, point2.y, point2.z);
			*/
