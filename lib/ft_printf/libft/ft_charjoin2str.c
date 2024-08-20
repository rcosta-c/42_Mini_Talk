/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin2str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:12:07 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/19 10:12:54 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charjoin2str(char *s1, char s2)
{
	char	*newstr;
	size_t	counter;
	size_t	x;

	if (!s1)
		return (ft_strdup(s1));
	x = ft_strlen(s1);
	newstr = (char *)malloc(sizeof(char) * (x + 2));
	if (!newstr)
		return (NULL);
	counter = 0;
	while (s1[counter])
	{
		newstr[counter] = s1[counter];
		counter++;
	}
	newstr[counter++] = s2;
	newstr[counter] = '\0';
	free(s1);
	return (newstr);
}
