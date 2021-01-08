/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:56:52 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/08 19:21:50 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void	init_color(t_mini_rt *rt)
{
	rt->tmp_color.r = 0;
	rt->tmp_color.g = 0;
	rt->tmp_color.b = 0;
}

t_color	color_average(t_color c1, t_color c2)
{
	t_color	c;

	c.r = min_max_colors(sqrt(c1.r * c2.r));
	c.g = min_max_colors(sqrt(c1.g * c2.g));
	c.b = min_max_colors(sqrt(c1.b * c2.b));
	return (c);
}

t_color	color_add(t_color c1, t_color c2)
{
	t_color	c;

	c.r = min_max_colors(c1.r + c2.r);
	c.g = min_max_colors(c1.g + c2.g);
	c.b = min_max_colors(c1.b + c2.b);
	return (c);
}

t_color	color_mult(t_color c1, double nb)
{
	t_color	c;

	c.r = min_max_colors(c1.r * nb);
	c.g = min_max_colors(c1.g * nb);
	c.b = min_max_colors(c1.b * nb);
	return (c);
}

double	min_max_colors(double color)
{
	if (color > 255)
		return (255);
	else if (color < 0)
		return (0);
	return (color);
}
