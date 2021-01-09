/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:28:37 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/09 22:17:22 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void	split_line_2(char *line, t_mini_rt *rt)
{
	char		**tab;
	fct			line_filler;

	tab = ft1_split(line, " \f\r\r\t\v");
	if (tab[0])
	{
		if ((line_filler = identify_type_2(tab[0])))
			line_filler(tab, rt);
	}
	free_tab(tab);
}

int		parser_part_2(char *file_name, t_mini_rt *rt)
{
	char	*line;
	int		fd;
	int		error_code;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (-600);
	error_code = -500;
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

int		split_line_1(char *line, t_mini_rt *rt)
{
	static int	i = 1;
	char		**tab;
	fct			line_checker;
	int			error_code;

	error_code = 1;
	tab = ft1_split(line, " \f\r\r\t\v");
	if (tab[0])
	{
		if ((line_checker = identify_type(tab[0])))
		{
			if ((error_code = line_checker(tab, rt)) != 1)
				ft_printf("Error code : %3d - Line %d\n", error_code, i);
		}
		else
		{
			error_code = -404;
			ft_printf("Error code : 404 - Line %d\n", i);
		}
	}
	free_tab(tab);
	i++;
	return (error_code);
}

int		parser_part_1(char *file_name, t_mini_rt *rt)
{
	char	*line;
	int		fd;
	int		error_code;
	int		tmp;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (-600);
	// Handle opening AND READING the parameter
	init_all_nb(rt);
	error_code = 1;
//	error_code = -500;
	while (get_next_line(fd, &line))
	{
		
		if (line[0] != '#')
			if ((tmp = split_line_1(line, rt)) != 1)
				error_code = tmp;
		free(line);
	}
//	if (line)
		free(line);
	close(fd);
	// Check nb for each elem.
//	printf("Error code : %d\n", error_code);
	return (error_code);
}


int		parser(char *file_name, t_mini_rt *rt)
{
	if (parser_part_1(file_name, rt) != 1)
	{
		ft_printf("Parsor error\n");
		return (0);
	}
	if (malloc_elem(rt) != 1)
	{
		ft_printf("Malloc error\n");
		return (0);
	}
	parser_part_2(file_name, rt);
	print_all_nb(rt);
	return (1);
}
