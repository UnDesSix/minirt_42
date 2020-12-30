/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:42:29 by mlarboul          #+#    #+#             */
/*   Updated: 2020/12/30 19:21:59 by mlarboul         ###   ########.fr       */
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
void		ft_plane(t_mini_rt *rt, t_obj *obj, t_vec ori, t_vec dir);
void		ft_triangle(t_mini_rt *rt, t_obj *obj, t_vec ori, t_vec dir);

/*
// Light functions
*/
void		apply_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light);
void		sphere_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light);
void		plane_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light);
void		triangle_light(t_mini_rt *rt, t_vec ori, t_vec dir, t_light light);

/*
// Color functions
*/
void		amb_light(t_mini_rt *rt);
void		init_tmp_color(t_mini_rt *rt);
void		init_color(t_mini_rt *rt);
t_color		color_add(t_color c1, t_color c2);
t_color		color_mult(t_color c1, float nb);
float		min_max_colors(float color);

/*
// Vectors formulas
*/
t_vec		vec_add(t_vec v1, t_vec v2);
t_vec		vec_sub(t_vec v1, t_vec v2);
t_vec		vec_mult(t_vec v1, float nb);
t_vec		vec_div(t_vec v1, float nb);
float		vec_dot(t_vec v1, t_vec v2);
t_vec		vec_cross(t_vec v1, t_vec v2);
t_vec		vec_normalize(t_vec v);
float		vec_length(t_vec v);
t_vec		vec_create(float x, float y, float z);

#endif
