/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:23:58 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/25 12:27:38 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_addr_0(t_option opt, long n, const char *base, int nb_len)
{
	char		*str;
	int			i;

	if (!(str = malloc(sizeof(char) * (opt.length + 1))))
		return (NULL);
	i = 0;
	if (opt.ladjust == FALSE)
		while (i < opt.length - nb_len)
			str[i++] = ' ';
	str[i++] = '0';
	str[i++] = 'x';
	nb_len -= 2;
	base_to_str1(n, base, nb_len + i - 1, str);
	i += nb_len;
	if (opt.ladjust == TRUE)
		while (i < opt.length)
			str[i++] = ' ';
	str[i] = '\0';
	return (str);
}

char	*ft_str_addr_1(long n, const char *base, int nb_len)
{
	char		*str;

	if (!(str = malloc(sizeof(char) * (nb_len + 1))))
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	base_to_str(n, base, nb_len - 1, str);
	return (str);
}

char	*ft_str_addr_2(t_option opt)
{
	char		*str;
	int			i;
	int			final_length;

	final_length = (opt.length > opt.prec + 2) ? opt.length : opt.prec + 2;
	if (!(str = malloc(sizeof(char) * (final_length + 1))))
		return (NULL);
	i = 0;
	if (opt.ladjust == FALSE)
		while (i < final_length - 2)
			str[i++] = ' ';
	str[i++] = '0';
	str[i++] = 'x';
	if (opt.ladjust == TRUE)
		while (i < final_length)
			str[i++] = ' ';
	str[i] = '\0';
	return (str);
}
