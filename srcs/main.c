/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:21:21 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/14 23:08:24 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		save_img(t_saver *rt, char *file, char *flag)
{
	if (!(ft_strncmp(flag, "--save", 7)))
	{
		if (rendering_one_img(rt, file) < 0)
			printf("Something went wrong while creating the BMP file.\n");
		else
		{
			printf("The BMP file has been saved into saved_images repo.\n");
			mlx_destroy_image(rt->mlx, rt->image[0].img);
		}
	}
	else
		printf("%s is not a valid flag. Please use --save.\n", flag);
	mlx_destroy_display(rt->mlx);
	free_rt_ptr(rt);
	free(rt->mlx);
	return (0);
}

void	init_rt_ptr(t_saver *rt)
{
	rt->cam = NULL;
	rt->light = NULL;
	rt->obj = NULL;
	rt->image = NULL;
	rt->k = 0;
}

void	free_rt_ptr(t_saver *rt)
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
	t_saver	rt;

	if (argc < 2 || argc > 3)
		return (0);
	init_rt_ptr(&rt);
	if (!parser(argv[1], &rt))
		return (0);
	rt.mlx = mlx_init();
	if (argc == 3)
		return (save_img(&rt, argv[1], argv[2]));
	res_max(&rt);
	rt.mlx_win = mlx_new_window(rt.mlx, rt.res.w,
							rt.res.h, "MiniRT by mlarboul");
	rendering_all_cams(&rt);
	rt.k = 0;
	mlx_hook(rt.mlx_win, 2, 1L << 0, key_manager, &rt);
	mlx_hook(rt.mlx_win, 15, 1L << 16, print_again, &rt);
	mlx_hook(rt.mlx_win, 33, 1L << 5, mouse_close_win, &rt);
	mlx_loop(rt.mlx);
	return (0);
}
