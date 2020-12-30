/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:31:24 by mlarboul          #+#    #+#             */
/*   Updated: 2020/12/16 17:06:07 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

t_list	*ft_create_elmem(int fd)
{
	t_list	*elm;

	if (!(elm = malloc(sizeof(t_list))))
		return (NULL);
	elm->fd = fd;
	elm->flag_eof = 0;
	elm->buff_size = 0;
	elm->line_size = 0;
	elm->buff_indx = 0;
	elm->buffer = NULL;
	elm->next = NULL;
	return (elm);
}

t_list	*ft_push_front(t_list **begin_list, int fd)
{
	t_list	*elm;

	if (!(*begin_list))
		(*begin_list) = ft_create_elmem(fd);
	else
	{
		elm = ft_create_elmem(fd);
		elm->next = (*begin_list);
		(*begin_list) = elm;
	}
	return (*begin_list);
}

char	*ft_strncpy(char *dst, char *src, t_size len)
{
	t_size	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strncat(char *dst, char *src, t_size line_offset, t_size add_len)
{
	t_size i;
	t_size j;

	i = 0;
	while (i < line_offset)
		i++;
	j = 0;
	while (j < add_len)
	{
		if (src[j] == '\n')
			dst[i] = '\0';
		else
			dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_realloc_spe(char *src, t_size init_len, t_size add_len)
{
	char	*dst;
	t_size	i;

	if (!(dst = malloc(sizeof(char) * (init_len + add_len + 1))))
		return (NULL);
	i = 0;
	while (i < init_len)
	{
		dst[i] = src[i];
		i++;
	}
	free(src);
	return (dst);
}
