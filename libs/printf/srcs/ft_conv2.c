/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:28:04 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/25 13:11:42 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_x1(va_list *ap, t_option opt)
{
	const char		hexa1[] = "0123456789abcdef";
	char			*str;
	int				nb_len;
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	nb_len = ft_nb_length(16, (long)n);
	if (!n && !opt.prec)
		str = ft_case_nb_prec_zero(opt.length);
	else
		str = ft_conv_pos_nb(opt, n, hexa1, nb_len);
	return (str);
}

char	*ft_conv_x2(va_list *ap, t_option opt)
{
	const char		hexa2[] = "0123456789ABCDEF";
	char			*str;
	int				nb_len;
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	nb_len = ft_nb_length(16, (long)n);
	if (!n && !opt.prec)
		str = ft_case_nb_prec_zero(opt.length);
	else
		str = ft_conv_pos_nb(opt, n, hexa2, nb_len);
	return (str);
}

char	*ft_conv_p(va_list *ap, t_option opt)
{
	const char	hexa1[] = "0123456789abcdef";
	char		*str;
	int			nb_len;
	long		n;

	n = (long)va_arg(*ap, void *);
	n = (n < 0) ? (unsigned int)n : n;
	nb_len = ft_nb_length(16, n) + 2;
	if (opt.prec == 0 && !n)
		str = ft_str_addr_2(opt);
	else if (opt.length > nb_len)
		str = ft_str_addr_0(opt, n, hexa1, nb_len);
	else
		str = ft_str_addr_1(n, hexa1, nb_len);
	return (str);
}
