/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:52:17 by mlarboul          #+#    #+#             */
/*   Updated: 2020/12/30 20:37:16 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

// TMP Function
void	print_all_nb(t_mini_rt *rt)
{
	int i;

	// Resolution
	printf("Resolution :\n");
	printf("%d x %d \n", rt->res.h, rt->res.w);
	
	// Ambiant
	printf("\nAmbiant    :\n");
	printf("Ratio : %2.2f\n",  rt->amb.ratio);
	printf("Colors %d, %d, %d \n", rt->amb.color.r, rt->amb.color.g, rt->amb.color.b);
	
	// Camera
	printf("\nCamera(s)    :\n");
	for (i = 0 ; i < rt->cam_nb; i++)
	{
		printf("  Camera %d    :\n", i);
		printf("     POV    : %2.2f, %2.2f, %2.2f \n", rt->cam[i].pov.x, rt->cam[i].pov.y, rt->cam[i].pov.z);
		printf("     Orient : %2.2f, %2.2f, %2.2f \n", rt->cam[i].orient.x, rt->cam[i].orient.y, rt->cam[i].orient.z);
		printf("     FOV    : %2.2f\n", rt->cam[i].fov);
	}
	
	// Light
	printf("\nLight(s)    :\n");
	for (i = 0 ; i < rt->light_nb; i++)
	{
		printf("  Light %d    :\n", i);
		printf("     Points : %2.2f, %2.2f, %2.2f \n", rt->light[i].point.x, rt->light[i].point.y, rt->light[i].point.z);
		printf("     Ratio  : %2.2f\n", rt->light[i].ratio);
		printf("     Colors : %d, %d, %d \n", rt->light[i].color.r, rt->light[i].color.g, rt->light[i].color.b);
	}
	
	// Obj
	printf("\nObject(s)    :\n");
	for (i = 0 ; i < rt->obj_nb; i++)
	{
		if (rt->obj[i].type == SPHERE)
		{
			printf("  Object : %d (Sphere) :\n", i);
			printf("     ID      : %d\n",  rt->obj[i].id);
			printf("     Points  : %2.2f, %2.2f, %2.2f \n", rt->obj[i].point1.x, rt->obj[i].point1.y, rt->obj[i].point1.z);
			printf("     Diameter: %2.2f\n", rt->obj[i].diameter);
			printf("     Colors  : %d, %d, %d \n", rt->obj[i].color.r, rt->obj[i].color.g, rt->obj[i].color.b);
		}
		else if (rt->obj[i].type == PLANE)
		{
			printf("  Object : %d (Plane) :\n", i);
			printf("     ID      : %d\n",  rt->obj[i].id);
			printf("     Points  : %2.2f, %2.2f, %2.2f \n", rt->obj[i].point1.x, rt->obj[i].point1.y, rt->obj[i].point1.z);
			printf("     Orient  : %2.2f, %2.2f, %2.2f \n", rt->obj[i].orient.x, rt->obj[i].orient.y, rt->obj[i].orient.z);
			printf("     Colors  : %d, %d, %d \n", rt->obj[i].color.r, rt->obj[i].color.g, rt->obj[i].color.b);
		}
		else if (rt->obj[i].type == SQUARE)
		{
			printf("  Object : %d (Square) :\n", i);
			printf("     ID      : %d\n",  rt->obj[i].id);
			printf("     Points  : %2.2f, %2.2f, %2.2f \n", rt->obj[i].point1.x, rt->obj[i].point1.y, rt->obj[i].point1.z);
			printf("     Orient  : %2.2f, %2.2f, %2.2f \n", rt->obj[i].orient.x, rt->obj[i].orient.y, rt->obj[i].orient.z);
			printf("     Height  : %2.2f\n", rt->obj[i].height);
			printf("     Colors  : %d, %d, %d \n", rt->obj[i].color.r, rt->obj[i].color.g, rt->obj[i].color.b);
		}
		else if (rt->obj[i].type == CYLINDER)
		{
			printf("  Object : %d (Cylinder) :\n", i);
			printf("     ID      : %d\n",  rt->obj[i].id);
			printf("     Points  : %2.2f, %2.2f, %2.2f \n", rt->obj[i].point1.x, rt->obj[i].point1.y, rt->obj[i].point1.z);
			printf("     Orient  : %2.2f, %2.2f, %2.2f \n", rt->obj[i].orient.x, rt->obj[i].orient.y, rt->obj[i].orient.z);
			printf("     Diameter: %2.2f\n", rt->obj[i].diameter);
			printf("     Height  : %2.2f\n", rt->obj[i].height);
			printf("     Colors  : %d, %d, %d \n", rt->obj[i].color.r, rt->obj[i].color.g, rt->obj[i].color.b);
		}
		else if (rt->obj[i].type == TRIANGLE)
		{
			printf("  Object : %d (Triangle) :\n", i);
			printf("     ID      : %d\n",  rt->obj[i].id);
			printf("     Points1 : %2.2f, %2.2f, %2.2f \n", rt->obj[i].point1.x, rt->obj[i].point1.y, rt->obj[i].point1.z);
			printf("     Points2 : %2.2f, %2.2f, %2.2f \n", rt->obj[i].point2.x, rt->obj[i].point2.y, rt->obj[i].point2.z);
			printf("     Points3 : %2.2f, %2.2f, %2.2f \n", rt->obj[i].point3.x, rt->obj[i].point3.y, rt->obj[i].point3.z);
			printf("     Colors  : %d, %d, %d \n", rt->obj[i].color.r, rt->obj[i].color.g, rt->obj[i].color.b);
		}
	}
}

void	init_all_nb(t_mini_rt *rt)
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

int		malloc_elem(t_mini_rt *rt)
{
	if (!(rt->cam = malloc(sizeof(t_camera) * rt->cam_nb)))
		return (-1);
	if (!(rt->light = malloc(sizeof(t_light) * rt->light_nb)))
		return (-2);
	if (!(rt->obj = malloc(sizeof(t_obj) * rt->obj_nb)))
		return (-3);
	return (1);
}
