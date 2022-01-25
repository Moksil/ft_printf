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

#include <stdio.h>

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

/* -------------------- libft -------------------- */
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);

/* ----------------------------------------------- */

char	*ft_strndup(char *src, int n);

/* ----------------------------------------------- */
int		ft_printf(const char *, ...);

#endif
