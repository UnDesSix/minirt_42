/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:01:04 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/24 16:38:30 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_case_0(t_option opt)
{
	char *str;
	char *str1;

	if (!(str = malloc(sizeof(char) * 7)))
		return (NULL);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	if ((size_t)opt.length > ft_strlen(str)
			|| (opt.length > opt.prec && opt.prec >= 0))
		str1 = ft_str_case_1(opt, str);
	else if (opt.prec != -1 || (size_t)opt.prec < ft_strlen(str))
		str1 = ft_str_case_2(opt, str);
	else
		str1 = ft_strdup(str);
	free(str);
	return (str1);
}

char	*ft_str_case_1(t_option opt, char *s)
{
	char	*str;
	int		i;

	i = -1;
	if (!(str = malloc(sizeof(char) * (opt.length + 1))))
		return (NULL);
	opt.prec == -1 ? opt.prec = 2147483647 : 0;
	if (opt.ladjust)
	{
		while (++i < opt.prec && s[i])
			str[i] = s[i];
		while (i < opt.length)
			str[i++] = ' ';
	}
	else
	{
		if (ft_strlen(s) < (size_t)opt.prec)
			opt.prec = ft_strlen(s);
		while (++i < opt.length - opt.prec)
			str[i] = opt.padc;
		while (i < opt.length && *s)
			str[i++] = *(s++);
	}
	str[i] = '\0';
	return (str);
}

char	*ft_str_case_2(t_option opt, char *s)
{
	char	*str;
	int		i;
	int		length;

	i = -1;
	length = opt.prec;
	opt.prec < opt.length ? length = opt.length : 0;
	if (!(str = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (++i < opt.prec)
		str[i] = *(s++);
	while (i < length)
		str[i++] = ' ';
	str[i] = '\0';
	return (str);
}
