/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:20:36 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/25 11:20:10 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_pour(va_list *ap, t_option opt)
{
	char	*str;

	(void)*ap;
	if (opt.length <= 1)
		str = ft_pour_case_0();
	else
		str = ft_pour_case_1(opt);
	return (str);
}

int		ft_conv_c(va_list *ap, t_option opt)
{
	char	c;

	c = va_arg(*ap, int);
	if (opt.length > 1)
		return (ft_char_case_null_byte(c, opt));
	return (ft_char_case_0(c));
}

char	*ft_conv_s(va_list *ap, t_option opt)
{
	char	*str;
	char	*s;

	s = va_arg(*ap, char *);
	if (!s)
		str = ft_str_case_0(opt);
	else if ((size_t)opt.length > ft_strlen(s)
				|| (opt.length > opt.prec && opt.prec >= 0))
		str = ft_str_case_1(opt, s);
	else if (opt.prec != -1 || (size_t)opt.prec < ft_strlen(s))
		str = ft_str_case_2(opt, s);
	else
		str = ft_strdup(s);
	return (str);
}

char	*ft_conv_d_i(va_list *ap, t_option opt)
{
	const char	dec[] = "0123456789";
	char		*str;
	int			nb_len;
	long		n;

	n = (long)va_arg(*ap, int);
	nb_len = ft_nb_length(10, n);
	if (!n && !opt.prec)
		str = ft_case_nb_prec_zero(opt.length);
	else if (n < 0)
		str = ft_conv_neg_nb(opt, (-1) * n, dec, nb_len);
	else
		str = ft_conv_pos_nb(opt, n, dec, nb_len);
	return (str);
}

char	*ft_conv_u(va_list *ap, t_option opt)
{
	const char		dec[] = "0123456789";
	char			*str;
	int				nb_len;
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	nb_len = ft_nb_length(10, (long)n);
	if (!n && !opt.prec)
		str = ft_case_nb_prec_zero(opt.length);
	else
		str = ft_conv_pos_nb(opt, n, dec, nb_len);
	return (str);
}
