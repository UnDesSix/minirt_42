/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:31:31 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/14 09:21:45 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	parsing_error(int line, int code_error)
{
	static int	first_call = 1;

	if (first_call)
	{
		printf("\033[1;37mParsing error(s) :\033[0m\n");
		first_call = 0;
	}
	printf("Something went wrong \033[1;31mline %d\033[0m", line);
	if (code_error == 0)
		printf(" : \033[1;31mtoo many\033[0m information.\n");
	else if (code_error == -404)
		printf(" with the \033[1;31mfirst\033[0m information.\n");
	else if (code_error == -1)
		printf(" with the \033[1;31msecond\033[0m information.\n");
	else if (code_error == -2)
		printf(" with the \033[1;31mthird\033[0m information.\n");
	else if (code_error == -3)
		printf(" with the \033[1;31mfourth\033[0m information.\n");
	else if (code_error == -4)
		printf(" with the \033[1;31mfifth\033[0m information.\n");
	else if (code_error == -5)
		printf(" with the \033[1;31msixth\033[0m information.\n");
	return (-1);
}

int	open_or_read_error(char *file_name, int flag)
{
	printf("Something went wrong while ");
	if (flag == 1)
		printf("\033[1;31mopening \033[0m%s.\n", file_name);
	if (flag == 2)
		printf("\033[1;31mreading \033[0m%s.\n", file_name);
	return (-1);
}

int	extension_is_wrong(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 3] != '.' || str[i - 2] != 'r' || str[i - 1] != 't')
	{
		printf("%s is not a \033[1;31m.rt file\033[0m.\n", str);
		return (1);
	}
	return (0);
}

int	wrong_nb_of_elem(t_saver *rt)
{
	if (rt->res_nb != 1 || rt->amb_nb != 1 || rt->cam_nb < 1)
		printf("\033[1;37mParsing error(s) :\033[0m\n");
	if (rt->res_nb > 1)
		printf("Too many resolution lines.\n");
	if (rt->amb_nb > 1)
		printf("Too many ambient light lines.\n");
	if (rt->cam_nb < 1)
		printf("You forgot the camera(s).\n");
	if (rt->res_nb < 1)
		printf("You forgot the resolution.\n");
	if (rt->amb_nb < 1)
		printf("You forgot the ambient light.\n");
	if (rt->res_nb == 1 && rt->amb_nb == 1 && rt->cam_nb > 0)
		return (0);
	return (1);
}
