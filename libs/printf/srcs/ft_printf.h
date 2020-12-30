/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:57:20 by mlarboul          #+#    #+#             */
/*   Updated: 2020/12/30 09:50:23 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# define TRUE 1
# define FALSE 0

typedef int		t_bool;

typedef struct	s_option
{
	int		length;
	int		prec;
	char	padc;
	t_bool	ladjust;
}				t_option;

typedef char	*(*t_displ_funct)(va_list *, t_option opt);

int				ft_print_conv(t_option opt, const char *conv, va_list *ap);
int				ft_parser(const char **fmt, va_list *ap);
int				ft_printf(const char *fmt, ...);

t_displ_funct	ft_getfuntion(const char conv);
t_bool			ft_isflag(char c);
t_bool			ft_isconv(char c);
t_option		ft_init_opt(void);

void			ft_ladusjt(t_option *opt, const char **fmt);
void			ft_padding(t_option *opt, const char **fmt);
void			ft_width_norm(t_option *opt, const char **fmt);
void			ft_width_star(t_option *opt, const char **fmt, va_list *ap);
void			ft_width_prec(t_option *opt, const char **fmt, va_list *ap);

int				ft_nb_length(int base_len, long n);
void			base_to_str1(long n, const char *base, int i, char *str);
void			base_to_str(long n, const char *base, int i, char *str);

char			*ft_conv_pour(va_list *ap, t_option opt);
int				ft_conv_c(va_list *ap, t_option opt);
char			*ft_conv_s(va_list *ap, t_option opt);
char			*ft_conv_d_i(va_list *ap, t_option opt);
char			*ft_conv_u(va_list *ap, t_option opt);

char			*ft_conv_x1(va_list *ap, t_option opt);
char			*ft_conv_x2(va_list *ap, t_option opt);
char			*ft_conv_p(va_list *ap, t_option opt);

char			*ft_pour_case_0(void);
char			*ft_pour_case_1(t_option opt);

int				ft_char_case_null_byte(char c, t_option opt);
int				ft_char_case_0(char c);

char			*ft_str_case_0(t_option opt);
char			*ft_str_case_1(t_option opt, char *s);
char			*ft_str_case_2(t_option opt, char *s);

char			*ft_case_nb_prec_zero(int opt_length);
char			*ft_conv_neg_nb(t_option opt, long n,
										const char *base, int nb_len);
char			*ft_conv_pos_nb(t_option opt, long n,
										const char *base, int nb_len);

char			*ft_nb_neg_case_1(t_option opt, long n,
										const char *base, int nb_len);
char			*ft_nb_neg_case_2(t_option opt, long n,
										const char *base, int nb_len);
void			ft_nb_neg_case_2a(int *i, char *str, t_option opt, int nb_len);
char			*ft_nb_neg_case_3(t_option opt, long n,
										const char *base, int nb_len);

char			*ft_malloc_nbr0(long n, const char *base, int nb_len);
char			*ft_malloc_nbr1(t_option opt, long n,
										const char *base, int nb_len);
char			*ft_ladjust_nbr1(t_option opt, long n,
										const char *base, int nb_len);
char			*ft_malloc_nbr2(t_option opt, long n,
										const char *base, int nb_len);

char			*ft_str_addr_0(t_option opt, long n,
										const char *base, int nb_len);
char			*ft_str_addr_1(long n, const char *base, int nb_len);
char			*ft_str_addr_2(t_option opt);

#endif
