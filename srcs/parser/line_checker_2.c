/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checker_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:26:44 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/14 09:22:36 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	sphere_checker(char **tab, t_saver *rt)
{
	float	value;

	if (!tab[1] || !ft_is_coord(tab[1], POINTS))
		return (-1);
	if (!tab[2] || !ft_is_float(tab[2]))
		return (-2);
	value = atof(tab[2]);
	if (value < 0)
		return (-2);
	if (!tab[3] || !ft_is_coord(tab[3], COLORS))
		return (-3);
	if (tab[4])
		return (0);
	rt->obj_nb++;
	return (1);
}

int	plane_checker(char **tab, t_saver *rt)
{
	if (!tab[1] || !ft_is_coord(tab[1], POINTS))
		return (-1);
	if (!tab[2] || !ft_is_coord(tab[2], ORIENT))
		return (-2);
	if (!tab[3] || !ft_is_coord(tab[3], COLORS))
		return (-3);
	if (tab[4])
		return (0);
	rt->obj_nb++;
	return (1);
}

int	square_checker(char **tab, t_saver *rt)
{
	float	value;

	if (!tab[1] || !ft_is_coord(tab[1], POINTS))
		return (-1);
	if (!tab[2] || !ft_is_coord(tab[2], ORIENT))
		return (-2);
	if (!tab[3] || !ft_is_float(tab[3]))
		return (-3);
	value = atof(tab[3]);
	if (value < 0)
		return (-3);
	if (!tab[4] || !ft_is_coord(tab[4], COLORS))
		return (-4);
	if (tab[5])
		return (0);
	rt->obj_nb++;
	return (1);
}

int	cylinder_checker(char **tab, t_saver *rt)
{
	float	value;

	if (!tab[1] || !ft_is_coord(tab[1], POINTS))
		return (-1);
	if (!tab[2] || !ft_is_coord(tab[2], ORIENT))
		return (-2);
	if (!tab[3] || !ft_is_float(tab[3]))
		return (-3);
	value = atof(tab[3]);
	if (value < 0)
		return (-3);
	if (!tab[4] || !ft_is_float(tab[4]))
		return (-4);
	value = atof(tab[4]);
	if (value < 0)
		return (-4);
	if (!tab[3] || !ft_is_coord(tab[5], COLORS))
		return (-5);
	if (tab[6])
		return (0);
	rt->obj_nb++;
	return (1);
}

int	triangle_checker(char **tab, t_saver *rt)
{
	if (!tab[1] || !ft_is_coord(tab[1], POINTS))
		return (-1);
	if (!tab[2] || !ft_is_coord(tab[2], POINTS))
		return (-2);
	if (!tab[3] || !ft_is_coord(tab[3], POINTS))
		return (-3);
	if (!tab[4] || !ft_is_coord(tab[4], COLORS))
		return (-4);
	if (tab[5])
		return (0);
	rt->obj_nb++;
	return (1);
}
