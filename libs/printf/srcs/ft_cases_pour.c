/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_pour.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:04:37 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/25 12:30:26 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pour_case_0(void)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}

char	*ft_pour_case_1(t_option opt)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(char) * (opt.length + 1))))
		return (NULL);
	i = 0;
	if (opt.ladjust == FALSE)
		while (i < opt.length - 1)
			str[i++] = opt.padc;
	str[i++] = '%';
	if (opt.ladjust == TRUE)
		while (i < opt.length)
			str[i++] = ' ';
	str[i] = '\0';
	return (str);
}
