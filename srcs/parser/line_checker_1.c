/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checker_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:44:43 by mlarboul          #+#    #+#             */
/*   Updated: 2020/12/26 22:12:03 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

fct		identify_id(char *s)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s_len == 1 && !strncmp(s, "R", 1))
		return (resolution_checker);
	if (s_len == 1 && !strncmp(s, "A", 1))
		return (ambient_checker);
	if (s_len == 1 && !strncmp(s, "c", 1))
		return (camera_checker);
	if (s_len == 1 && !strncmp(s, "l", 1))
		return (light_checker);
	if (s_len == 2 && !strncmp(s, "sp", 2))
		return (sphere_checker);
	if (s_len == 2 && !strncmp(s, "pl", 2))
		return (plane_checker);
	if (s_len == 2 && !strncmp(s, "sq", 2))
		return (square_checker);
	if (s_len == 2 && !strncmp(s, "cy", 2))
		return (cylinder_checker);
	if (s_len == 2 && !strncmp(s, "tr", 2))
		return (triangle_checker);
	return (0);
}

int	resolution_checker(char **tab, t_mini_rt *rt)
{
	int	value;

	if (!tab[1] || !ft_is_float(tab[1]))
		return (-1);
	else
	{
		value = atoi(tab[1]);
		if (value < 1)
			return (-1);
	}
	if (!tab[2] || !ft_is_float(tab[2]))
		return (-2);
	else
	{
		value = atoi(tab[2]);
		if (value < 1)
			return (-2);
	}
	if (tab[3])
		return (0);
	rt->res_nb++;
	return (1);
}

int	ambient_checker(char **tab, t_mini_rt *rt)
{
	float	value;

	if (!tab[1] || !ft_is_float(tab[1]))
		return (-1);
	else
	{
		value = atof(tab[1]);
		if (value < 0 || value > 1)
			return (-1);
	}
	if (!tab[2] || !ft_is_coord(tab[2], COLORS))
		return (-2);
	if (tab[3])
		return (0);
	rt->amb_nb++;
	return (1);
}

int	camera_checker(char **tab, t_mini_rt *rt)
{
	float	value;

	if (!tab[1] || !ft_is_coord(tab[1], POINTS))
		return (-1);
	if (!tab[2] || !ft_is_coord(tab[2], ORIENT))
		return (-2);
	if (!tab[3] || !ft_is_float(tab[3]))
		return (-3);
	else
	{
		value = ft_atof(tab[3]);
		if (value < 0 || value > 180)
			return (-3);
	}
	if (tab[4])
		return (0);
	rt->cam_nb++;
	return (1);
}

int	light_checker(char **tab, t_mini_rt *rt)
{
	float	value;

	if (!tab[1] || !ft_is_coord(tab[1], POINTS))
		return (-1);
	if (!tab[2] || !ft_is_float(tab[2]))
		return (-2);
	else
	{
		value = atof(tab[2]);
		if (value < 0 || value > 1)
			return (-2);
	}
	if (!tab[3] || !ft_is_coord(tab[3], COLORS))
		return (-3);
	if (tab[4])
		return (0);
	rt->light_nb++;
	return (1);
}
