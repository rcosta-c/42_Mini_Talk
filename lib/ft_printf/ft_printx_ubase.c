/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx_ubase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 07:29:54 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/05/06 07:49:24 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx_ubase(unsigned long long nbr)
{
	unsigned long long		len;
	char					*base;
	int						counter;

	counter = 0;
	len = 0;
	base = ft_strdup(HEX_U_BASE);
	len += ft_p_strlen(base);
	counter += ft_printnbr_base(nbr, base, len);
	free(base);
	return (counter);
}
