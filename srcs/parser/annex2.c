/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:52:17 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/14 09:21:22 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	init_all_nb(t_saver *rt)
{
	rt->res_nb = 0;
	rt->amb_nb = 0;
	rt->cam_nb = 0;
	rt->light_nb = 0;
	rt->obj_nb = 0;
	rt->curr_cam = 0;
	rt->curr_light = 0;
	rt->curr_obj = 0;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		malloc_elem(t_saver *rt)
{
	if (!(rt->cam = malloc(sizeof(t_camera) * rt->cam_nb)))
	{
		printf("Memory allocation failed while ");
		printf("\033[1;31mcamera allocation\033[0m.\n");
		return (-1);
	}
	if (!(rt->image = malloc(sizeof(t_image) * rt->cam_nb)))
	{
		printf("Memory allocation failed while ");
		printf("\033[1;31mimage allocation\033[0m.\n");
		return (-1);
	}
	if (!(rt->light = malloc(sizeof(t_light) * rt->light_nb)))
	{
		printf("Memory allocation failed while ");
		printf("\033[1;31mlight allocation\033[0m.\n");
		return (-1);
	}
	if (!(rt->obj = malloc(sizeof(t_obj) * rt->obj_nb)))
	{
		printf("Memory allocation failed while ");
		printf("\033[1;31mobject allocation\033[0m.\n");
		return (-1);
	}
	return (1);
}
