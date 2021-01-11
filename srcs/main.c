/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:21:21 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/11 22:51:43 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	init_rt_ptr(t_mini_rt *rt)
{
	rt->cam = NULL;
	rt->light = NULL;
	rt->obj = NULL;
	rt->image = NULL;
}

void	free_rt_ptr(t_mini_rt *rt)
{
	if (rt->cam)
		free(rt->cam);
	if (rt->light)
		free(rt->light);
	if (rt->obj)
		free(rt->obj);
	if (rt->image)
		free(rt->image);
}

int		main(int argc, char **argv)
{
	t_mini_rt	rt;

	init_ptr(&rt);
	if (!parser(argv[1], &rt))
		return (0);
	compute_rotation(&rt);
	rt.mlx = mlx_init();
	rt.mlx_win = mlx_new_window(rt.mlx, rt.res.w, rt.res.h, "MiniRT by mlarboul");

	rendering_all_cams(&rt);
	
	// DEAL CAMERAS AND IMAGES
	mlx_put_image_to_window(rt.mlx, rt.mlx_win, rt.image[1].img, 0, 0);

	// DEAL MLX FUNCTIONS (CLOSE, EXPOSE)
	mlx_loop(rt.mlx);
	
	return (0);
}
