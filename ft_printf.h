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
	char	flag;
	int 	width;
	int		precision;
	int		len;
	char	specifier;
	char	*start_ptr;
	char	*end_ptr;
}					t_spec;

int		ft_putnbr_m_fd(int n, int fd);
int		ft_putnbr_um_fd(unsigned int n, int fd);
int		ft_printf(const char *, ...);

#endif
