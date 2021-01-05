/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: /12/26 19:51: by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/05 20:30:39 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	compute_rotation(t_mini_rt *rt)
{
	t_vec	tmp;

	tmp = vec_normalize(vec_create(0, 1, 0));
	rt->foward = vec_normalize(rt->cam->orient);
	if (rt->foward.y == 1 || rt->foward.y == -1)
		rt->right = vec_create(1,0,0);
	else
		rt->right = vec_cross(tmp, rt->foward);
	rt->up = vec_cross(rt->foward, rt->right);
	rt->foward = vec_normalize(rt->foward);
	rt->right = vec_normalize(rt->right);
	rt->up = vec_normalize(rt->up);
}
