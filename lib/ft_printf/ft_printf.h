/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:50:31 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/05/08 08:04:12 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_U_BASE "0123456789ABCDEF"
# define HEX_L_BASE "0123456789abcdef"
# define DEC_BASE "0123456789"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

//char	*ft_strdup(const char *s);
int		ft_printf(const char *format, ...);
int		ft_printnbr(int n, int fd);
int		ft_printx_lbase(unsigned long long nbr);
int		ft_printx_ubase(unsigned long long nbr);
int		ft_printu(unsigned long long nbr);
int		ft_printnbr_base(unsigned long long nbr, char *base, \
		unsigned long long len);
int		ft_printchar(char c, int fd);
int		ft_printstr(char *s, int fd);
int		ft_printptr(unsigned long long nbr);
int		ft_p_strlen(char *s);

#endif
