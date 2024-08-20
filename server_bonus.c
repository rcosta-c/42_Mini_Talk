/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:15:49 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/08/19 11:46:07 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	error(void)
{
	ft_printf("Error - Server");
	exit (EXIT_FAILURE);
}

void	print_pid(void)
{
	ft_printf("\n\n***** \n\nSERVER PID ---> %d\n\n*****\n\n", getpid());
}

void	receive_handler(int sig, siginfo_t *info, void *more_info)
{
	static char	x;
	static int	bit;
	static char	*buffer;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	(void)more_info;
	if (SIGUSR1 == sig)
		x |= (0b10000000 >> bit);
	++bit;
	if (8 == bit)
	{
		buffer = ft_charjoin2str(buffer, (char)x);
		if (x == '\0')
		{
			ft_printf("%s\n", buffer);
			kill(info->si_pid, SIGUSR2);
			free(buffer);
			buffer = NULL;
		}
		x = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_handler;
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		error();
	if (sigaction(SIGUSR2, &sa, NULL) < 0)
		error();
	print_pid();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
