/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:34:34 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/14 09:34:36 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESC 65307

# define SPHERE 1
# define PLANE 2
# define SQUARE 3
# define CYLINDER 4
# define TRIANGLE 5

# define HEADER_SIZE 54

typedef struct	s_img_head
{
	int	size_img_head;
	int	width;
	int	height;
	int	plans_nb;
	int	bpp;
	int	compression;
	int	size_img;
	int	height_res;
	int	width_res;
	int	color_pal;
	int	important_color;
}				t_img_head;

typedef struct	s_bmp_head
{
	char		signature[2];
	int			size;
	int			rsv_byte;
	int			offset_img;
	t_img_head	img_head;
}				t_bmp_head;

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef	struct	s_res
{
	int	w;
	int	h;
}				t_res;

typedef struct	s_solve
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;
	double	d1;
	double	d2;
	t_vec	sub;
	t_vec	cross;
	t_vec	v1;
	t_vec	v2;
	t_vec	tvec;
	t_vec	pvec;
}				t_solve;

typedef struct	s_ambient
{
	double	ratio;
	t_color	color;
}				t_ambient;

typedef struct	s_image
{
	void	*img;
	char	*buffer;
	int		bpp;
	int		line_length;
	int		endian;
}				t_image;

typedef struct	s_camera
{
	t_vec	pov;
	t_vec	orient;
	double	fov;
	t_vec	foward;
	t_vec	right;
	t_vec	up;
}				t_camera;

typedef struct	s_light
{
	t_vec	point;
	double	ratio;
	t_color	color;
}				t_light;

typedef struct	s_obj
{
	int		type;
	int		id;
	t_vec	point1;
	t_vec	point2;
	t_vec	point3;
	t_color	color;
	double	diameter;
	t_vec	orient;
	double	height;
	t_vec	foward;
	t_vec	right;
	t_vec	up;
}				t_obj;

typedef struct	s_saver
{
	void		*mlx;
	void		*mlx_win;
	t_image		*image;
	int			pos;
	int			k;
	int			res_nb;
	int			amb_nb;
	int			cam_nb;
	int			light_nb;
	int			obj_nb;
	int			curr_cam;
	int			curr_light;
	int			curr_obj;
	t_vec		dir;
	t_res		res;
	t_ambient	amb;
	t_camera	*cam;
	t_light		*light;
	t_obj		*obj;
	t_obj		*last_obj;
	double		t;
	double		vis_t1;
	t_color		tmp_color;
	double		intensity;
	int			flag;
}				t_saver;

#endif
