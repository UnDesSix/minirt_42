/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_posnb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:03:38 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/24 16:46:56 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_malloc_nbr0(long n, const char *base, int nb_len)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(char) * (nb_len + 1))))
		return (NULL);
	i = nb_len - 1;
	base_to_str(n, base, i, str);
	return (str);
}

char	*ft_malloc_nbr1(t_option opt, long n, const char *base, int nb_len)
{
	char	*str;
	int		i;
	int		flag_pad;

	if (opt.ladjust)
		str = ft_ladjust_nbr1(opt, n, base, nb_len);
	else
	{
		if (!(str = malloc(sizeof(char) * (opt.length + 1))))
			return (NULL);
		flag_pad = opt.prec < 0 ? 1 : 0;
		opt.prec = opt.prec < 0 ? 0 : opt.prec;
		opt.prec = opt.prec < nb_len ? nb_len : opt.prec;
		i = 0;
		while (i < opt.length - opt.prec)
			str[i++] = flag_pad ? opt.padc : ' ';
		while (i < opt.length - nb_len)
			str[i++] = '0';
		base_to_str(n, base, nb_len + i - 1, str);
	}
	return (str);
}

char	*ft_ladjust_nbr1(t_option opt, long n, const char *base, int nb_len)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(char) * (opt.length + 1))))
		return (NULL);
	opt.prec = opt.prec < 0 ? 0 : opt.prec;
	opt.prec = opt.prec < nb_len ? nb_len : opt.prec;
	i = 0;
	while (i < opt.prec - nb_len)
		str[i++] = '0';
	base_to_str(n, base, nb_len + i - 1, str);
	i += nb_len;
	while (i < opt.length)
		str[i++] = ' ';
	str[i] = '\0';
	return (str);
}

char	*ft_malloc_nbr2(t_option opt, long n, const char *base, int nb_len)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(char) * (opt.prec + 1))))
		return (NULL);
	i = 0;
	while (i < opt.prec - nb_len)
		str[i++] = '0';
	base_to_str(n, base, nb_len + i - 1, str);
	return (str);
}
