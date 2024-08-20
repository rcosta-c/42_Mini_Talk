/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:50:31 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/05/06 08:47:20 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printu(unsigned long long nbr)
{
	char	*base;
	int		len;
	int		counter;

	counter = 0;
	base = ft_strdup(DEC_BASE);
	len = ft_p_strlen(base);
	counter += ft_printnbr_base(nbr, base, len);
	free(base);
	return (counter);
}
