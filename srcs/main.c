/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:21:21 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/13 22:59:20 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"



void	init_rt_ptr(t_mini_rt *rt)
{
	rt->cam = NULL;
	rt->light = NULL;
	rt->obj = NULL;
	rt->image = NULL;
	rt->k = 0;
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

	if (argc < 2 || argc > 3)
		return (0);
	init_rt_ptr(&rt);
	if (!parser(argv[1], &rt))
		return (0);
	rt.mlx = mlx_init();
	res_max(&rt);
	rt.mlx_win = mlx_new_window(rt.mlx, rt.res.w,
							rt.res.h, "MiniRT by mlarboul");
	rendering_all_cams(&rt);
	create_bmp(&rt, argv[1]);
	rt.k = 0;
	mlx_hook(rt.mlx_win, 2, 1L << 0, key_manager, &rt);
	mlx_hook(rt.mlx_win, 15, 1L << 16, print_again, &rt);
	mlx_hook(rt.mlx_win, 33, 1L << 5, mouse_close_win, &rt);
	mlx_loop(rt.mlx);
	return (0);
}
