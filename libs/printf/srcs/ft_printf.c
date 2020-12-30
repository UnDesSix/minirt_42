/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:06:54 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/25 12:22:09 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_conv(t_option opt, const char *conv, va_list *ap)
{
	char			*str;
	int				count;
	t_displ_funct	f;

	if (*conv == 'c')
		return (ft_conv_c(ap, opt));
	f = ft_getfuntion(*conv);
	if (!(str = f(ap, opt)))
		return (0);
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}

int		ft_parser(const char **fmt, va_list *ap)
{
	t_option	opt;

	opt = ft_init_opt();
	(*fmt)++;
	while (ft_isflag(**fmt) || ft_isconv(**fmt))
	{
		if (**fmt == '-')
			ft_ladusjt(&opt, fmt);
		if (**fmt == '0')
			ft_padding(&opt, fmt);
		if (ft_isdigit(**fmt))
			ft_width_norm(&opt, fmt);
		else if (**fmt == '*')
			ft_width_star(&opt, fmt, ap);
		if (**fmt == '.')
			ft_width_prec(&opt, fmt, ap);
		if (ft_isconv(**fmt))
			return (ft_print_conv(opt, *fmt, ap));
	}
	if (**fmt == '\0')
		return (0);
	return (0);
}

int		ft_printf(const char *fmt, ...)
{
	int		count;
	int		tmp;
	va_list	ap;

	count = 0;
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			if ((tmp = ft_parser(&fmt, &ap)) < 0)
				return (-1);
			count += tmp;
		}
		else
		{
			write(1, fmt, 1);
			count++;
		}
		if (*fmt)
			fmt++;
	}
	va_end(ap);
	return (count);
}
