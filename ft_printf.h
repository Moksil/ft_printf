/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmipa <sungmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:53:29 by sungmipa          #+#    #+#             */
/*   Updated: 2022/01/22 21:53:30 by sungmipa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_specifier
{
	int		minus_flag;
	int		zero_flag;
	int		plus_flag;
	int		space_flag;
	int		sharp_flag;
	int 	width;
	int		precision;
	int		len;
	char	specifier;
}					t_spec;

int			is_specifier(char c);
int			is_flag(char c);
int			max_in_2_int(int a, int b);
int			max_in_3_int(int a, int b, int c);
int			str_validation(const char *str);
const char	*get_valid_spec(const char *mod_op_ptr);
int			get_nbr_length(int n);
int			get_unbr_length(unsigned int n);
int			get_hexa_len_int(unsigned int nbr);
int			get_hexa_len_long(unsigned long nbr);
void		put_nbr(int n);
void		put_nbr_u(unsigned int n);
void		put_hexa_from_long(unsigned long nbr, char flag);
void		put_hexa_from_int(unsigned int nbr, char flag);
t_spec		get_specifier_info(const char *str, int n) ;
t_spec		spec_init(void);
t_spec		spec_parsing(char *mod_op_ptr);
t_spec		check_minus_flag(t_spec ret, char *mod_op_ptr, int i);
t_spec		check_zero_flag(t_spec ret, char *mod_op_ptr, int i);
t_spec		check_plus_flag(t_spec ret, char *mod_op_ptr, int i);
t_spec		check_space_flag(t_spec ret, char *mod_op_ptr, int i);
t_spec		check_sharp_flag(t_spec ret, char *mod_op_ptr, int i);
t_spec		check_width(t_spec ret, char *mod_op_ptr, int i);
t_spec		check_precision(t_spec ret, char *mod_op_ptr, int i);
int			call_dispenser(va_list* ap, t_spec s);
int			mod_op_handling(t_spec s);
int			c_handling(va_list* ap, t_spec s);
int			s_handling(va_list* ap, t_spec s);
int			d_handling(va_list* ap, t_spec s);
int			u_handling(va_list* ap, t_spec s);
int			p_handling(va_list* ap, t_spec s);
int			lower_x_handling(va_list* ap, t_spec s);
int			upper_x_handling(va_list* ap, t_spec s);
void		fadding_space(t_spec s, int arglen, int sign);
void		fadding_zero(t_spec s, int arglen, int sign);

int		ft_printf(const char *, ...);

#endif
