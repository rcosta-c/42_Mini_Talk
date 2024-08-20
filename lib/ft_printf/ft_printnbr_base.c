/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 07:31:28 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/05/06 11:04:31 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr_base(unsigned long long nbr, char *base, unsigned long long len)
{
	int	counter;

	counter = 0;
	if (nbr / len > 0)
		counter += ft_printnbr_base(nbr / len, base, len);
	counter += ft_printchar(base[nbr % len], STDOUT_FILENO);
	return (counter);
}
