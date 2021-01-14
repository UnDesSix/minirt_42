/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:42:29 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/14 22:05:39 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdio.h>
# include <mlx.h>

# include "../../libs/libft/libft.h"
# include "get_next_line.h"
# include "struct.h"
# include "parser.h"

char		*get_bmp_name(char *file);
void		init_header(t_saver *rt, t_bmp_head *bmp);
void		write_header(int fd, t_bmp_head bmp, char *buffer_img);
int			create_bmp(t_saver *rt, char *file);

int			mouse_close_win(t_saver *rt);
int			esc_close_win(t_saver *rt);
int			print_again(t_saver *rt);
int			change_cam(int keycode, t_saver *rt);
int			key_manager(int keycode, t_saver *rt);
int			res_max(t_saver *rt);

int			argc_error_msg(int argc);
int			save_img(t_saver *rt, char *file, char *flag);
void		init_rt_ptr(t_saver *rt);
void		free_rt_ptr(t_saver *rt);

void		get_obj_function(t_saver *rt, t_obj *obj, t_vec ori, t_vec dir);
void		fill_image(t_saver *rt, int k);
t_vec		compute_dir(t_saver *rt, int x, int y, t_camera camera);
void		run_saver(t_saver *rt, int k);
void		compute_rotation(t_saver *rti, int i);
void		mess_rendering_img(int x, int y, t_saver *rt, int flag);
void		init_rt_var(t_saver *rt, int x, int y, int k2);
void		rendering_all_cams(t_saver *rt);
int			rendering_one_img(t_saver *rt, char *line);

void		ft_sphere(t_saver *rt, t_obj *sphere, t_vec ori, t_vec dir);
void		ft_plane(t_saver *rt, t_obj *plane, t_vec ori, t_vec dir);
void		ft_triangle(t_saver *rt, t_obj *triangle, t_vec ori, t_vec dir);
void		ft_square(t_saver *rt, t_obj *square, t_vec ori, t_vec dir);
int			is_in_square(t_obj *square, t_vec point);
void		cylinder_rotation(t_obj *rt);
void		ft_cylinder(t_saver *rt, t_obj *cylinder, t_vec ori, t_vec dir);
int			ft_cylinder2(t_saver *rt, t_obj *cylinder, float t, t_vec point);

void		apply_light(t_saver *rt, t_vec ori, t_vec dir, t_light light);
void		sphere_light(t_saver *rt, t_vec ori, t_vec dir, t_light light);
void		plane_light(t_saver *rt, t_vec ori, t_vec dir, t_light light);
void		triangle_light(t_saver *rt, t_vec ori, t_vec dir, t_light light);
void		square_light(t_saver *rt, t_vec ori, t_vec dir, t_light light);
void		cylinder_light(t_saver *rt, t_vec ori, t_vec dir, t_light light);
int			apply_shaders(t_saver *rt, t_obj *obj, t_vec ori, t_vec dir);
int			is_visible(t_saver *rt, t_light light, t_vec point, t_vec normal);
int			sphere_shaders(t_saver *rt, t_obj *sp, t_vec ori, t_vec dir);
int			plane_shaders(t_saver *rt, t_obj *pl, t_vec ori, t_vec dir);
int			triangle_shaders(t_saver *rt, t_obj *tr, t_vec ori, t_vec dir);
int			square_shaders(t_saver *rt, t_obj *sq, t_vec ori, t_vec dir);
int			cylinder_shaders(t_saver *rt, t_obj *cy, t_vec ori, t_vec dir);
int			cylinder2_sh(t_saver *rt, t_obj *cy, float t, t_vec point);

void		amb_light(t_saver *rt);
void		init_tmp_color(t_saver *rt);
void		init_color(t_saver *rt);
t_color		color_add(t_color c1, t_color c2);
t_color		color_average(t_color c1, t_color c2);
t_color		color_mult(t_color c1, double nb);
double		min_max_colors(double color);

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
