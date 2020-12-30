/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annex1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:15:06 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/25 11:03:21 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_displ_funct	ft_getfuntion(const char conv)
{
	if (conv == 's')
		return (ft_conv_s);
	if (conv == 'p')
		return (ft_conv_p);
	if (conv == 'd' || conv == 'i')
		return (ft_conv_d_i);
	if (conv == 'u')
		return (ft_conv_u);
	if (conv == 'x')
		return (ft_conv_x1);
	if (conv == 'X')
		return (ft_conv_x2);
	return (ft_conv_pour);
}

t_bool			ft_isflag(char c)
{
	if (c == '-' || c == '.' || c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}

t_bool			ft_isconv(char c)
{
	const char	conv_tab[] = "cspdiuxX%";
	int			i;

	i = 0;
	while (conv_tab[i])
	{
		if (conv_tab[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_option		ft_init_opt(void)
{
	t_option	option;

	option.length = 0;
	option.prec = -1;
	option.ladjust = FALSE;
	option.padc = ' ';
	return (option);
}
