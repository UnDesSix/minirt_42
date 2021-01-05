#ifndef ELEMENTS_H
# define ELEMENTS_H

# define SPHERE 1
# define PLANE 2
# define SQUARE 3
# define CYLINDER 4
# define TRIANGLE 5

# define LIGHT 10

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

/*
typedef struct	s_ray
{
	t_vec	ori;
	t_vec	dir;
}				t_ray;
*/

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
	t_vec		foward;
	t_vec		right;
	t_vec		up;
}				t_obj;

typedef struct	s_mini_rt
{
	void		*mlx;
	void		*mlx_win;
	t_image		image;
	int			pos;

	int			res_nb;
	int			amb_nb;
	int			cam_nb;
	int			light_nb;
	int			obj_nb;

	int			curr_cam;
	int			curr_light;
	int			curr_obj;

	t_vec		foward;
	t_vec		right;
	t_vec		up;

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
}				t_mini_rt;

#endif
