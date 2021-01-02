/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:42:29 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/02 19:20:30 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdio.h>
# include <mlx.h>

# include "../../libs/printf/srcs/ft_printf.h"
# include "get_next_line.h"
# include "elements.h"
# include "parser.h"
/*
// Main functions
*/
void		get_obj_function(t_mini_rt *rt, t_obj *obj, t_vec ori, t_vec dir);
void		fill_image(t_mini_rt *tr);
t_vec		compute_dir(t_mini_rt *rt, int x, int y, t_camera camera);
void		run_mini_rt(t_mini_rt *rt);
void		compute_rotation(t_mini_rt *rt);
/*
// Object functions
*/
void		ft_sphere(t_mini_rt *rt, t_obj *sphere, t_vec ori, t_vec dir);
void		ft_plane(t_mini_rt *rt, t_obj *plane, t_vec ori, t_vec dir);
void		ft_triangle(t_mini_rt *rt, t_obj *triangle, t_vec ori, t_vec dir);
void		ft_square(t_mini_rt *rt, t_obj *square, t_vec ori, t_vec dir);
int			is_in_square(t_obj *square, t_vec point);
void		ft_cylinder(t_mini_rt *rt, t_obj *cylinder, t_vec ori, t_vec dir);

/*
// Light functions
*/
void		apply_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light);
void		sphere_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light);
void		plane_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light);
void		triangle_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light);
void		square_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light);
void		cylinder_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light);

int			apply_shaders(t_mini_rt *rt, t_obj *obj, t_vec ori, t_vec dir);
int			is_visible(t_mini_rt *rt, t_light light, t_vec point);
int			sphere_shaders(t_mini_rt *rt, t_obj *sphere, t_vec ori, t_vec dir);
int			plane_shaders(t_mini_rt *rt, t_obj *plane, t_vec ori, t_vec dir);
int			triangle_shaders(t_mini_rt *rt, t_obj *triangle, t_vec ori, t_vec dir);
int			square_shaders(t_mini_rt *rt, t_obj *square, t_vec ori, t_vec dir);
/*
// Color functions
*/
void		amb_light(t_mini_rt *rt);
void		init_tmp_color(t_mini_rt *rt);
void		init_color(t_mini_rt *rt);
t_color		color_add(t_color c1, t_color c2);
t_color		color_mult(t_color c1, double nb);
double		min_max_colors(double color);

/*
// Vectors formulas
*/
t_vec		vec_add(t_vec v1, t_vec v2);
t_vec		vec_sub(t_vec v1, t_vec v2);
t_vec		vec_mult(t_vec v1, double nb);
t_vec		vec_div(t_vec v1, double nb);
double		vec_dot(t_vec v1, t_vec v2);
t_vec		vec_cross(t_vec v1, t_vec v2);
t_vec		vec_normalize(t_vec v);
double		vec_length(t_vec v);
t_vec		vec_create(double x, double y, double z);

#endif
