/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:39:18 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/24 20:15:10 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_case_nb_prec_zero(int opt_length)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (opt_length + 1))))
		return (NULL);
	while (i < opt_length)
		str[i++] = ' ';
	str[i] = '\0';
	return (str);
}

char	*ft_conv_neg_nb(t_option opt, long n, const char *base, int nb_len)
{
	char	*str;

	if (opt.prec > nb_len)
		str = ft_nb_neg_case_1(opt, n, base, nb_len);
	else if (opt.length > nb_len)
		str = ft_nb_neg_case_2(opt, n, base, nb_len);
	else
		str = ft_nb_neg_case_3(opt, n, base, nb_len);
	return (str);
}

char	*ft_conv_pos_nb(t_option opt, long n, const char *base, int nb_len)
{
	char	*str;

	if (opt.length >= nb_len && opt.length >= opt.prec)
		str = ft_malloc_nbr1(opt, n, base, nb_len);
	else if (opt.prec > nb_len)
		str = ft_malloc_nbr2(opt, n, base, nb_len);
	else
		str = ft_malloc_nbr0(n, base, nb_len);
	return (str);
}
