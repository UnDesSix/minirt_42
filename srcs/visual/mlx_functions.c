/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 06:59:00 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/14 09:25:06 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int		res_max(t_saver *rt)
{
	int	width_max;
	int	height_max;

	mlx_get_screen_size(rt->mlx, &width_max, &height_max);
	if (rt->res.w > width_max)
		rt->res.w = width_max;
	if (rt->res.h > height_max)
		rt->res.h = height_max;
	return (0);
}

int		key_manager(int keycode, t_saver *rt)
{
	if (keycode == ESC)
		esc_close_win(rt);
	else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		change_cam(keycode, rt);
	return (0);
}

int		mouse_close_win(t_saver *rt)
{
	int k;

	k = -1;
	mlx_destroy_window(rt->mlx, rt->mlx_win);
	while (++k < rt->cam_nb)
		mlx_destroy_image(rt->mlx, rt->image[k].img);
	mlx_destroy_display(rt->mlx);
	free_rt_ptr(rt);
	free(rt->mlx);
	exit(0);
	return (0);
}

int		esc_close_win(t_saver *rt)
{
	int k;

	k = -1;
	mlx_destroy_window(rt->mlx, rt->mlx_win);
	while (++k < rt->cam_nb)
		mlx_destroy_image(rt->mlx, rt->image[k].img);
	mlx_destroy_display(rt->mlx);
	free_rt_ptr(rt);
	free(rt->mlx);
	exit(0);
	return (0);
}

int		print_again(t_saver *rt)
{
	mlx_put_image_to_window(rt->mlx, rt->mlx_win, rt->image[rt->k].img, 0, 0);
	return (0);
}
