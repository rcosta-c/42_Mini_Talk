/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:30:51 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/05/06 09:25:10 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s, int fd)
{
	size_t	size;

	if (s == NULL)
		return (ft_printstr("(null)", STDOUT_FILENO));
	size = ft_p_strlen(s);
	write(fd, s, size);
	return (size);
}
/*
int     main()
{
        char    *x = "ruben";

        ft_putstr_fd(x, 1);
        return (0);
}*/
