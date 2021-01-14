/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 07:55:43 by mlarboul          #+#    #+#             */
/*   Updated: 2021/01/14 09:20:06 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

char	*get_bmp_name(char *file)
{
	char	*name;
	int		i;
	int		j;
	int		len_name;
	int		tmp;

	i = ft_strlen(file) - 3;
	len_name = 0;
	while (i - len_name - 1 > 0 && file[i - len_name - 1] != '/')
		len_name++;
	if (!(name = malloc(sizeof(char) * (len_name + 13 + 4 + 1))))
		return (NULL);
	name[0] = '\0';
	name[(len_name + 17)] = '\0';
	ft_strlcat(name, "saved_images/", (len_name + 13 + 4 + 1));
	j = 13;
	tmp = len_name + 13;
	while (j < tmp)
	{
		name[j++] = file[i - len_name];
		len_name--;
	}
	name[j] = '\0';
	ft_strlcat(name, ".bmp", (tmp + 4 + 1));
	return (name);
}

void	init_header(t_saver *rt, t_bmp_head *bmp)
{
	bmp->signature[0] = 'B';
	bmp->signature[1] = 'M';
	bmp->size = 54 + (4 * rt->res.w * rt->res.h);
	bmp->rsv_byte = 0;
	bmp->offset_img = 54;
	bmp->img_head.size_img_head = 54 - 14;
	bmp->img_head.width = rt->res.w;
	bmp->img_head.height = -rt->res.h;
	bmp->img_head.plans_nb = 1;
	bmp->img_head.bpp = 32;
	bmp->img_head.compression = 0;
	bmp->img_head.size_img = (4 * rt->res.w * rt->res.h);
	bmp->img_head.height_res = 3780;
	bmp->img_head.width_res = 3780;
	bmp->img_head.color_pal = 0;
	bmp->img_head.important_color = 0;
}

void	write_header(int fd, t_bmp_head bmp, char *img_buffer)
{
	write(fd, &bmp.signature[0], 2);
	write(fd, &bmp.size, 4);
	write(fd, &bmp.rsv_byte, 4);
	write(fd, &bmp.offset_img, 4);
	write(fd, &bmp.img_head.size_img_head, 4);
	write(fd, &bmp.img_head.width, 4);
	write(fd, &bmp.img_head.height, 4);
	write(fd, &bmp.img_head.plans_nb, 2);
	write(fd, &bmp.img_head.bpp, 2);
	write(fd, &bmp.img_head.compression, 4);
	write(fd, &bmp.img_head.size_img, 4);
	write(fd, &bmp.img_head.height_res, 4);
	write(fd, &bmp.img_head.width_res, 4);
	write(fd, &bmp.img_head.color_pal, 4);
	write(fd, &bmp.img_head.important_color, 4);
	write(fd, &img_buffer[0], bmp.img_head.size_img);
}

int		create_bmp(t_saver *rt, char *file)
{
	t_bmp_head	bmp;
	int			fd;
	char		*bmp_name;

	if ((bmp_name = get_bmp_name(file)) < 0)
		return (-1);
	if ((fd = open(bmp_name, O_WRONLY | O_TRUNC | O_CREAT, 0755)) < 0)
		return (-2);
	free(bmp_name);
	init_header(rt, &bmp);
	write_header(fd, bmp, rt->image->buffer);
	close(fd);
	return (1);
}
