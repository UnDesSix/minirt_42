/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:55:19 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/11 19:04:21 by mlarboul         ###   ########.fr       */
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
	else
		return ;
}

void	fill_image(t_mini_rt *rt, int k)
{
	if (!rt->flag)
	{
		amb_light(rt);
		rt->image[k].buffer[rt->pos] = (char)rt->tmp_color.b;
		rt->image[k].buffer[rt->pos + 1] = (char)rt->tmp_color.g;
		rt->image[k].buffer[rt->pos + 2] = (char)rt->tmp_color.r;
	}
	else
	{
		rt->image[k].buffer[rt->pos] = (char)0;
		rt->image[k].buffer[rt->pos + 1] = (char)0;
		rt->image[k].buffer[rt->pos + 2] = (char)0;
	}
	rt->pos += 4;
}

void	mess_rendering_img(int x, int y, t_mini_rt *rt, int flag)
{
	float		pourc;
	static	int	image_nb = 1;
	
	if (flag == 1)
	{
		pourc = ((x + (y * rt->res.w)) * 100.0) / (rt->res.w * rt->res.h);
		printf("Rendering image %d [%6.2f%%] - ", image_nb, pourc);
		printf("\033[1;33mWait for it..\033[0m\r");
	}
	else
	{
		printf("Rendering image %d [100.00%%] - ", image_nb);
		printf("\033[1;32mDone!        \033[0m\n");
		image_nb++;
	}
}

void	init_rt_var(t_mini_rt *rt, int x, int y)
{
	rt->dir = vec_normalize(compute_dir(rt, x, y, rt->cam[0]));
	rt->t = 3.402823E+38;
	rt->flag = 1;
	rt->last_obj = &(rt->obj[0]);
	init_color(rt);
}

void	run_mini_rt(t_mini_rt *rt, int k2)
{
	int			x;
	int			y;
	int			k1;

	rt->pos = 0;
	y = -1;
	while (++y < rt->res.h)
	{
		x = -1;
		while (++x < rt->res.w)
		{
			init_rt_var(rt, x, y);
			k1 = 0;
			while (k1 < rt->obj_nb)
				get_obj_function(rt, &rt->obj[k1++], rt->cam[k2].pov, rt->dir);
			k1 = 0;
			while (k1 < rt->light_nb)
				apply_light(rt, rt->cam[k2].pov, rt->dir, rt->light[k1++]);
			fill_image(rt, k2);
			mess_rendering_img(x, y, rt, 1);
		}
	}
	mess_rendering_img(x, y, rt, 2);
}
