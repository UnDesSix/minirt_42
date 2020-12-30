/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:30:23 by mlarboul          #+#    #+#             */
/*   Updated: 2020/12/16 17:09:29 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024

# include <stdlib.h>
# include <unistd.h>

typedef	unsigned int	t_size;

typedef struct	s_list
{
	int				fd;
	int				flag_eof;
	t_size			buff_size;
	t_size			line_size;
	t_size			buff_indx;
	char			*buffer;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
int				ft_read_fd(t_list *elm, char **line);
int				ft_fill_line(t_list *elm, char **line);
void			ft_clear_elm(t_list **begin_list, t_list *elm_to_del);
t_list			*ft_create_elmem(int fd);
t_list			*ft_push_front(t_list **begin_list, int fd);
char			*ft_strncpy(char *dst, char *src, t_size len);
char			*ft_realloc_spe(char *src, t_size init_len, t_size add_len);
char			*ft_strncat(char *dst, char *src,
										t_size line_offset, t_size add_len);

#endif
