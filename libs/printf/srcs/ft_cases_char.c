/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:53:15 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/24 23:17:41 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_case_null_byte(char c, t_option opt)
{
	int		i;

	i = 0;
	if (opt.ladjust == FALSE)
		while (i < opt.length - 1)
		{
			write(1, " ", 1);
			i++;
		}
	write(1, &c, 1);
	i++;
	if (opt.ladjust == TRUE)
		while (i < opt.length)
		{
			write(1, " ", 1);
			i++;
		}
	return (i);
}

int		ft_char_case_0(char c)
{
	write(1, &c, 1);
	return (1);
}
