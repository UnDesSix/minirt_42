/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:43:33 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/13 08:16:46 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

int		change_cam(int keycode, t_mini_rt *rt)
{
	if (keycode == RIGHT_ARROW)
		(rt->k)++;
	if (keycode == LEFT_ARROW)
		(rt->k)--;
	if (rt->k < 0)
		rt->k = rt->cam_nb - 1;
	if (rt->k > rt->cam_nb - 1)
		rt->k = 0;
	mlx_put_image_to_window(rt->mlx, rt->mlx_win, rt->image[rt->k].img, 0, 0);
	return (0);
}

void	rendering_all_cams(t_mini_rt *rt)
{
	while (rt->k < rt->cam_nb)
	{
		rt->image[rt->k].img = mlx_new_image(rt->mlx, rt->res.w, rt->res.h);
		rt->image[rt->k].buffer = mlx_get_data_addr(
			rt->image[rt->k].img, &rt->image[rt->k].bpp,
				&rt->image[rt->k].line_length, &rt->image[rt->k].endian);
		run_mini_rt(rt, rt->k);
		if (rt->k == 0)
			mlx_put_image_to_window(rt->mlx, rt->mlx_win,
									rt->image[rt->k].img, 0, 0);
		(rt->k)++;
	}
}

void	compute_rotation(t_mini_rt *rt, int i)
{
	t_vec	tmp;

	tmp = vec_normalize(vec_create(0, 1, 0));
	rt->cam[i].foward = vec_normalize(rt->cam[i].orient);
	if (rt->cam[i].foward.y == 1 || rt->cam[i].foward.y == -1)
		rt->cam[i].right = vec_create(1, 0, 0);
	else
		rt->cam[i].right = vec_cross(tmp, rt->cam[i].foward);
	rt->cam[i].up = vec_cross(rt->cam[i].foward, rt->cam[i].right);
	rt->cam[i].foward = vec_normalize(rt->cam[i].foward);
	rt->cam[i].right = vec_normalize(rt->cam[i].right);
	rt->cam[i].up = vec_normalize(rt->cam[i].up);
}

t_vec	compute_dir(t_mini_rt *rt, int x, int y, t_camera camera)
{
	t_vec	pixel;
	t_vec	tmp;

	pixel.x = x - (rt->res.w / 2);
	pixel.y = (rt->res.h / 2) - y;
	pixel.z = rt->res.w / (2 * tan((camera.fov * M_PI / 180 / 2)));
	tmp = pixel;
	pixel.x = tmp.x * camera.right.x + tmp.y *
						camera.up.x + tmp.z * camera.foward.x;
	pixel.y = tmp.x * camera.right.y + tmp.y *
						camera.up.y + tmp.z * camera.foward.y;
	pixel.z = tmp.x * camera.right.z + tmp.y *
						camera.up.z + tmp.z * camera.foward.z;
	return (pixel);
}
