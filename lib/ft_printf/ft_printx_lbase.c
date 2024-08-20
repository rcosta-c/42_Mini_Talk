/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx_lbase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 07:28:11 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/05/06 10:59:27 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx_lbase(unsigned long long nbr)
{
	unsigned long long		len;
	char					*base;
	int						counter;

	counter = 0;
	len = 0;
	base = ft_strdup(HEX_L_BASE);
	if (!base)
		return (0);
	len += ft_p_strlen(base);
	counter += ft_printnbr_base(nbr, base, len);
	free(base);
	return (counter);
}
//
//int	main()
//{
//	return (printf("\n%d\n", ft_printx_lbase( LONG_MAX)));
//}
