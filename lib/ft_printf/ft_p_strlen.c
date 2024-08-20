/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:34:20 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/05/08 07:57:37 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_strlen(char *s)
{
	unsigned int	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s[counter] != '\0')
		counter++;
	return (counter);
}
/*
int	main()
{
	char	*x;

	x = "asddasdasdadsd";
	printf(" value : %zu \n", ft_strlen(x));
}*/
