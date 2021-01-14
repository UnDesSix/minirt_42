/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:28:37 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/14 09:38:50 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	split_line_2(char *line, t_saver *rt)
{
	char		**tab;
	t_fct			line_filler;

	tab = ft1_split(line, " \f\r\r\t\v");
	if (tab[0])
		if ((line_filler = identify_type_2(tab[0])))
			line_filler(tab, rt);
	free_tab(tab);
}

int		parser_part_2(char *file_name, t_saver *rt)
{
	char	*line;
	int		fd;
	int		error_code;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (open_or_read_error(file_name, 1));
	if (read(fd, NULL, 0) < 0)
		return (open_or_read_error(file_name, 2));
	error_code = 1;
	while (get_next_line(fd, &line))
	{
		if (line[0] != '#')
			split_line_2(line, rt);
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	return (error_code);
}

int		split_line_1(char *line, t_saver *rt, int *i)
{
	char		**tab;
	t_fct			line_checker;
	int			error_code;
	int			r_value;

	r_value = 1;
	tab = ft1_split(line, " \f\r\r\t\v");
	if (tab[0])
	{
		if ((line_checker = identify_type(tab[0])))
			if ((error_code = line_checker(tab, rt)) != 1)
				r_value = parsing_error(*i, error_code);
		if (!line_checker)
			r_value = parsing_error(*i, -404);
	}
	free_tab(tab);
	(*i)++;
	return (r_value);
}

int		parser_part_1(char *file_name, t_saver *rt)
{
	char		*line;
	int			fd;
	int			error_code;
	int			tmp;
	static int	i = 1;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (open_or_read_error(file_name, 1));
	if (read(fd, NULL, 0) < 0)
		return (open_or_read_error(file_name, 2));
	init_all_nb(rt);
	error_code = 1;
	while (get_next_line(fd, &line))
	{
		if (line[0] != '#')
			if ((tmp = split_line_1(line, rt, &i)) != 1)
				error_code = tmp;
		if (line[0] == '#')
			i++;
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	return (error_code);
}

int		parser(char *file_name, t_saver *rt)
{
	if (extension_is_wrong(file_name))
		return (0);
	if (parser_part_1(file_name, rt) != 1)
		return (0);
	if (wrong_nb_of_elem(rt))
		return (0);
	if (malloc_elem(rt) != 1)
		return (0);
	if (parser_part_2(file_name, rt) != 1)
		return (0);
	return (1);
}
