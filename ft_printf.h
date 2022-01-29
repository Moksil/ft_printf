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

#include <stdio.h>

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

int		ft_putnbr_m_fd(int n, int fd);
int		ft_putnbr_um_fd(unsigned int n, int fd);
int		ft_printf(const char *, ...);

#endif
