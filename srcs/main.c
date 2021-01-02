/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:21:21 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/02 19:12:37 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"


void	get_obj_function(t_mini_rt *rt, t_obj *obj, t_vec ori, t_vec dir)
{
	if (obj->type == SPHERE)
		ft_sphere(rt, obj, ori, dir);
	else if (obj->type == PLANE)
		ft_plane(rt, obj, ori, dir);
	else if (obj->type == TRIANGLE)
		ft_triangle(rt, obj, ori, dir);
	else if (obj->type == SQUARE)
		ft_square(rt, obj, ori, dir);
	else if (obj->type == CYLINDER)
		ft_cylinder(rt, obj, ori, dir);
}

void	fill_image(t_mini_rt *rt)
{
	if (!rt->flag)
	{
		amb_light(rt);
		rt->image.buffer[rt->pos] = (char)rt->tmp_color.b;
		rt->image.buffer[rt->pos + 1] = (char)rt->tmp_color.g;
		rt->image.buffer[rt->pos + 2] = (char)rt->tmp_color.r;
	}
	else
	{
		rt->image.buffer[rt->pos] = (char)0;
		rt->image.buffer[rt->pos + 1] = (char)0;
		rt->image.buffer[rt->pos + 2] = (char)0;
	}
		rt->pos += 4;
}

/*
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
*/

void	run_mini_rt(t_mini_rt *rt)
{
	int			x;
	int			y;
	int			k;
	t_vec		dir;

	rt->pos = 0;
	y = 0;
	while (y < rt->res.h)
	{
		x = 0;
		while (x < rt->res.w)
		{
			dir = vec_normalize(compute_dir(rt, x, y, rt->cam[0]));
			rt->t = 3.402823E+38;
			rt->flag = 1;
			rt->last_obj = &(rt->obj[0]);
			init_color(rt);
			k = 0;
			while (k < rt->obj_nb)
				get_obj_function(rt, &rt->obj[k++], rt->cam[0].pov, dir);
			k = 0;
			while (k < rt->light_nb)
				apply_light(rt, rt->cam[0].pov, dir, rt->light[k++]);
			fill_image(rt);
			printf("\rRendering image [%3d%%]", ((x + (y * rt->res.w)) * 100) / (rt->res.w * rt->res.h));
			x++;
		}
		y++;
	}
		printf("\rRendering image [100%%] - \033[1;32mDone\033[0m\033[1m\n");
}

int		main(int argc, char **argv)
{
	t_mini_rt	rt;

	(void)argc;

	
	//initialize nb :
	rt.cam = NULL;
	rt.light = NULL;
	rt.obj = NULL;
	if (!parser(argv[1], &rt))
		return (0);
	compute_rotation(&rt);
	rt.mlx = mlx_init();
	rt.mlx_win = mlx_new_window(rt.mlx, rt.res.w, rt.res.h, "mini_RT Version 2.0");
	
	rt.image.img = mlx_new_image(rt.mlx, rt.res.w, rt.res.h);
	rt.image.buffer = mlx_get_data_addr(rt.image.img, &rt.image.bpp,
									&rt.image.line_length, &rt.image.endian);

	run_mini_rt(&rt);

	mlx_put_image_to_window(rt.mlx, rt.mlx_win, rt.image.img, 0, 0);

	mlx_loop(rt.mlx);
	if (rt.cam)
		free(rt.cam);
	if (rt.light)
		free(rt.light);
	if (rt.obj)
		free(rt.obj);
	return (0);
}


t_vec	compute_dir(t_mini_rt *rt, int x, int y, t_camera camera)
{
	t_vec	pixel;
	t_vec	tmp;
	float	scale;
	float	scene_ratio;

	scene_ratio = rt->res.w / rt->res.h;
	scale = tan((camera.fov * M_PI / 180 / 2.0));
	pixel.x = (2 * (x + 0.5) / rt->res.w - 1) * scene_ratio * scale;
	pixel.y = (1 - 2 * (y + 0.5) / rt->res.h) * scale;
	pixel.z = 1;
	tmp = pixel;
	pixel.x = tmp.x * rt->right.x + tmp.y * rt->up.x + tmp.z * rt->foward.x;
	pixel.y = tmp.x * rt->right.y + tmp.y * rt->up.y + tmp.z * rt->foward.y;
	pixel.z = tmp.x * rt->right.z + tmp.y * rt->up.z + tmp.z * rt->foward.z;
	return (pixel);
}

