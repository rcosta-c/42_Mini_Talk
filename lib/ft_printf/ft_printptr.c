/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:47:03 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/05/06 09:06:17 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long long nbr)
{
	int	counter;

	counter = 0;
	if (nbr == 0)
	{
		counter += ft_printstr("(nil)", STDOUT_FILENO);
		return (counter);
	}
	else
	{
		counter += ft_printstr("0x", STDOUT_FILENO);
		counter += ft_printx_lbase(nbr);
		return (counter);
	}
}
