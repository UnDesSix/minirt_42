/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annex3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:30:35 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/24 21:41:33 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nb_length(int base_len, long n)
{
	int count;

	count = 1;
	while (n / base_len)
	{
		count++;
		n /= base_len;
	}
	return (count);
}

void	base_to_str(long n, const char *base, int i, char *str)
{
	int	base_len;

	str[i + 1] = '\0';
	base_len = (int)ft_strlen(base);
	str[i] = base[n % base_len];
	while (n / base_len)
	{
		n /= base_len;
		str[--i] = base[n % base_len];
	}
}

void	base_to_str1(long n, const char *base, int i, char *str)
{
	int	base_len;

	base_len = (int)ft_strlen(base);
	str[i] = base[n % base_len];
	while (n / base_len)
	{
		n /= base_len;
		str[--i] = base[n % base_len];
	}
}
