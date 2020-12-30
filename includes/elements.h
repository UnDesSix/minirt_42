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
	float	x;
	float	y;
	float	z;
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
	float	a;
	float	b;
	float	c;
	float	delta;
	float	t1;
	float	t2;
	float	d1;
	float	d2;
	t_vec	sub;
	t_vec	cross;
}				t_solve;

typedef struct	s_ambient
{
	float	ratio;
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
	float	fov;
}				t_camera;

typedef struct	s_light
{
	t_vec	point;
	float	ratio;
	t_color	color;
}				t_light;

typedef struct	s_obj
{
	int		id;
	t_vec	point1;
	t_vec	point2;
	t_vec	point3;
	t_color	color;
	float	diameter;
	t_vec	orient;
	float	height;
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

	float		t;
	t_color		tmp_color;
	float		intensity;
	int			flag;
}				t_mini_rt;

#endif
