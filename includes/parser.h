/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:12:58 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/14 09:37:45 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdio.h>
# include "struct.h"

# define COLORS 1
# define POINTS 2
# define RATIO 3
# define ORIENT 4

typedef int	(*t_fct)(char **, t_saver *rt);

int			ft1_is_sep(char *charset, char c);
char		*ft1_strdup_spe(char *src, char *charset);
char		**ft1_tab_n_str_size(char *str, char *charset, int *count_bis);
char		**ft1_split(char *str, char *charset);

int			contains_two_commas(char *s, char **tab);
int			ft_is_range(char *s, int id);
int			ft_is_coord(char *s, int id);
int			ft_is_float(char *s);
double		ft_atof(char *s);
void		init_all_nb(t_saver *rt);
void		free_tab(char **tab);
int			malloc_elem(t_saver *rt);
void		fill_colors(t_color *elem, char *s);
void		fill_points(t_vec *elem, char *s);

int			split_line_1(char *line, t_saver *rt, int *i);
void		split_line_2(char *line, t_saver *rt);
int			parser_part_1(char *argv, t_saver *rt);
int			parser_part_2(char *argv, t_saver *rt);
int			parser(char *argv, t_saver *rt);

t_fct		identify_type(char *s);
int			resolution_checker(char **tab, t_saver *rt);
int			ambient_checker(char **tab, t_saver *rt);
int			camera_checker(char **tab, t_saver *rt);
int			light_checker(char **tab, t_saver *rt);
int			sphere_checker(char **tab, t_saver *rt);
int			plane_checker(char **tab, t_saver *rt);
int			square_checker(char **tab, t_saver *rt);
int			triangle_checker(char **tab, t_saver *rt);
int			cylinder_checker(char **tab, t_saver *rt);

t_fct		identify_type_2(char *s);
int			resolution_filler(char **tab, t_saver *rt);
int			ambient_filler(char **tab, t_saver *rt);
int			camera_filler(char **tab, t_saver *rt);
int			light_filler(char **tab, t_saver *rt);
int			sphere_filler(char **tab, t_saver *rt);
int			plane_filler(char **tab, t_saver *rt);
int			square_filler(char **tab, t_saver *rt);
int			triangle_filler(char **tab, t_saver *rt);
int			cylinder_filler(char **tab, t_saver *rt);

int			parsing_error(int line, int code_error);
int			open_or_read_error(char *file_name, int flag);
int			extension_is_wrong(char *str);
int			wrong_nb_of_elem(t_saver *rt);

#endif
