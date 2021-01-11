/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:21:21 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/11 07:47:39 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

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
