/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:55:19 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/11 09:17:46 by mlarboul         ###   ########.fr       */
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

void	mess_rendering_img(int x, int y, t_mini_rt *rt, int flag)
{
	float	pourc;

	if (flag == 1)
	{
		pourc = ((x + (y * rt->res.w)) * 100.0) / (rt->res.w * rt->res.h);
		printf("Rendering image [%6.2f%%] - ", pourc);
		printf("\033[1;33mWait for it..\033[0m\r");
	}
	else
	{
		printf("Rendering image [100.00%%] - ");
		printf("\033[1;32mDone!        \033[0m\n");
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

void	run_mini_rt(t_mini_rt *rt)
{
	int			x;
	int			y;
	int			k;

	rt->pos = 0;
	y = -1;
	while (++y < rt->res.h)
	{
		x = -1;
		while (++x < rt->res.w)
		{
			init_rt_var(rt, x, y);
			k = 0;
			while (k < rt->obj_nb)
				get_obj_function(rt, &rt->obj[k++], rt->cam[0].pov, rt->dir);
			k = 0;
			while (k < rt->light_nb)
				apply_light(rt, rt->cam[0].pov, rt->dir, rt->light[k++]);
			fill_image(rt);
			mess_rendering_img(x, y, rt, 1);
		}
	}
	mess_rendering_img(x, y, rt, 2);

