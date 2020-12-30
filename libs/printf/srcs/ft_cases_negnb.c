/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_negnb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:42:37 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/25 12:29:14 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_nb_neg_case_1(t_option opt, long n, const char *base, int nb_len)
{
	char	*str;
	int		i;
	int		final_len;

	i = 0;
	final_len = (opt.length - 1 > opt.prec) ? opt.length : opt.prec + 1;
	if (!(str = malloc(sizeof(char) * (final_len + 1))))
		return (NULL);
	if (opt.ladjust == FALSE)
		while (i < (final_len - (opt.prec + 1)))
			str[i++] = ' ';
	str[i++] = '-';
	if (opt.ladjust == FALSE)
		while (i < (final_len - nb_len))
			str[i++] = '0';
	else
		while (i < (opt.prec + 1 - nb_len))
			str[i++] = '0';
	base_to_str1(n, base, i + nb_len - 1, str);
	i += nb_len;
	if (opt.ladjust == TRUE)
		while (i < final_len)
			str[i++] = ' ';
	str[i] = '\0';
	return (str);
}

char	*ft_nb_neg_case_2(t_option opt, long n, const char *base, int nb_len)
{
	char	*str;
	int		i;

	i = 0;
	opt.padc = (opt.prec >= 0) ? '0' : opt.padc;
	if (!(str = malloc(sizeof(char) * (opt.length + 1))))
		return (NULL);
	if (opt.ladjust == FALSE)
		ft_nb_neg_case_2a(&i, str, opt, nb_len);
	if (opt.ladjust == TRUE)
		str[i++] = '-';
	base_to_str1(n, base, i + nb_len - 1, str);
	i += nb_len;
	if (opt.ladjust == TRUE)
		while (i < opt.length)
			str[i++] = ' ';
	str[i] = '\0';
	return (str);
}

void	ft_nb_neg_case_2a(int *i, char *str, t_option opt, int nb_len)
{
	if (opt.padc == '0' && opt.prec < 0)
	{
		str[(*i)++] = '-';
		while (*i < (opt.length - nb_len))
			str[(*i)++] = opt.padc;
	}
	else
	{
		while (*i < (opt.length - nb_len - 1))
			str[(*i)++] = ' ';
		str[(*i)++] = '-';
	}
}

char	*ft_nb_neg_case_3(t_option opt, long n, const char *base, int nb_len)
{
	char	*str;
	int		i;

	(void)opt;
	i = 0;
	if (!(str = malloc(sizeof(char) * (nb_len + 1 + 1))))
		return (NULL);
	str[i++] = '-';
	base_to_str1(n, base, i + nb_len - 1, str);
	i += nb_len;
	str[i] = '\0';
	return (str);
}
