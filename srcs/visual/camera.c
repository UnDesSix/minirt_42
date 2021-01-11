/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:43:33 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/11 18:58:50 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	rendering_all_cams(t_mini_rt *rt)
{
	int	k;

	k = 0;
	while (k < rt->cam_nb)
	{
		rt->image[k].img = mlx_new_image(rt->mlx, rt->res.w, rt->res.h);
		rt->image[k].buffer = mlx_get_data_addr(rt->image[k].img,
			&rt->image[k].bpp, &rt->image[k].line_length, &rt->image[k].endian);
		run_mini_rt(rt, k);
		k++;
	}
}

void	compute_rotation(t_mini_rt *rt)
{
	t_vec	tmp;

	tmp = vec_normalize(vec_create(0, 1, 0));
	rt->foward = vec_normalize(rt->cam->orient);
	if (rt->foward.y == 1 || rt->foward.y == -1)
		rt->right = vec_create(1, 0, 0);
	else
		rt->right = vec_cross(tmp, rt->foward);
	rt->up = vec_cross(rt->foward, rt->right);
	rt->foward = vec_normalize(rt->foward);
	rt->right = vec_normalize(rt->right);
	rt->up = vec_normalize(rt->up);
}

t_vec	compute_dir(t_mini_rt *rt, int x, int y, t_camera camera)
{
	t_vec	pixel;
	t_vec	tmp;

	pixel.x = x - (rt->res.w / 2);
	pixel.y = (rt->res.h / 2) - y;
	pixel.z = rt->res.w / (2 * tan((camera.fov * M_PI / 180 / 2)));
	tmp = pixel;
	pixel.x = tmp.x * rt->right.x + tmp.y * rt->up.x + tmp.z * rt->foward.x;
	pixel.y = tmp.x * rt->right.y + tmp.y * rt->up.y + tmp.z * rt->foward.y;
	pixel.z = tmp.x * rt->right.z + tmp.y * rt->up.z + tmp.z * rt->foward.z;
	return (pixel);
}
