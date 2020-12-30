/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:17:29 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/24 19:40:56 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ladusjt(t_option *opt, const char **fmt)
{
	(*fmt)++;
	opt->ladjust = TRUE;
}

void	ft_padding(t_option *opt, const char **fmt)
{
	(*fmt)++;
	opt->padc = '0';
}

void	ft_width_norm(t_option *opt, const char **fmt)
{
	while (ft_isdigit(**fmt))
	{
		opt->length = opt->length * 10 + (**fmt - 48);
		(*fmt)++;
	}
}

void	ft_width_star(t_option *opt, const char **fmt, va_list *ap)
{
	(*fmt)++;
	opt->length = va_arg(*ap, int);
	if (opt->length < 0)
	{
		opt->ladjust = 1;
		opt->length = -(opt->length);
	}
}

void	ft_width_prec(t_option *opt, const char **fmt, va_list *ap)
{
	(*fmt)++;
	opt->prec = 0;
	if (ft_isdigit(**fmt))
	{
		while (ft_isdigit(**fmt))
		{
			opt->prec = opt->prec * 10 + (**fmt - 48);
			(*fmt)++;
		}
	}
	else if (**fmt == '*')
	{
		opt->prec = va_arg(*ap, int);
		if (opt->prec < 0)
			opt->prec = -1;
		(*fmt)++;
	}
}
