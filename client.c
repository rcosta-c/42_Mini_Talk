/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:18:31 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/19 11:45:40 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

size_t	how_much_sleep(size_t size)
{
	if (size < 5000)
		return (100);
	else if (size < 10000)
		return (250);
	else if (size < 20000)
		return (300);
	else if (size < 60000)
		return (450);
	else if (size < 100000)
		return (500);
	else
		return (10000);
}

void	ft_the_end(int sigusr)
{
	if (sigusr == SIGUSR2)
		ft_printf("***   Message received by server!   ***\n\n");
	exit (EXIT_SUCCESS);
}

void	send_handler(int pid, char c, size_t len)
{
	int	bit;

	bit = 0;
	while (bit <= 7)
	{
		if (c & (0b10000000 >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		++bit;
		usleep(how_much_sleep(len));
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	unsigned int		x;

	if (ac != 3)
	{
		ft_printf("\nPlease use: %s <pid> <message>\n", av[0]);
		return (EXIT_FAILURE);
	}
	else
	{
		ft_printf("\n***   Welcome to Client!   ***\n\n");
		signal(SIGUSR2, ft_the_end);
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_RESTART;
		x = 0;
		ft_printf("***   Message lengh is : %d ***\n\n", ft_strlen(av[2]));
		ft_printf("***   Starting sending the message to server...    ***\n\n");
		while (av[2][x])
		{
			send_handler(ft_atoi(av[1]), av[2][x], ft_strlen(av[2]));
			x++;
		}
		send_handler(ft_atoi(av[1]), av[2][x], 1);
	}
	exit (EXIT_SUCCESS);
}
