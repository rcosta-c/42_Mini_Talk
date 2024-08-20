/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:25:45 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/05/08 07:55:52 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c, int fd)
{
	if (fd >= 0)
	{
		(write(fd, &c, 1));
		return (1);
	}
	else
		return (0);
}
/*
int	main()
{
	char	x = 'r';

	ft_putchar_fd(x, 2);
	return (0);
}*/
