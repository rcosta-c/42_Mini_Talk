/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 07:18:47 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/05/02 11:33:53 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n, int fd)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		counter += ft_printstr("-2147483648", fd);
		return (counter);
	}
	if (n < 0)
	{
		n = n * -1;
		counter += ft_printchar(45, fd);
	}
	if (n > 9)
	{
		counter += ft_printnbr(n / 10, fd);
		counter += ft_printchar((n % 10 + 48), fd);
	}
	else
		counter += ft_printchar(n + 48, fd);
	return (counter);
}
/*
#include <stdio.h>

int     main()  
{
        ft_putnbr_fd(-2147483647, 1);
        return (0);
}*/
