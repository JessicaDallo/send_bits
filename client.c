/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:57:18 by jesilva-          #+#    #+#             */
/*   Updated: 2024/03/28 12:57:48 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

// void	error(char *str)
// {
// 	if (str)
// 		free(str);
// 	ft_printf("client: unexpected error.\n");
// 	exit(EXIT_FAILURE);
// }

// int	send_message(int pid, char *str)
// {
// 	static char	*message = 0;
// 	static int	s_pid = 0;
// 	static int	bits = -1;
// 	if (str)
// 		message = ft_strdup(str);
// 	if (!message)
// 		error(0);
// 	if (pid)
// 		s_pid = pid;
// 	if (message[++bits / 8])
// 	{
// 		if (message[bits / 8] & (0x80 >> (bits % 8)))
// 		{
// 			if (kill(s_pid, SIGUSR2) == -1)
// 				error(message);
// 		}
// 		else if (kill(s_pid, SIGUSR1) == -1)
// 			error(message);
// 		return (0);
// 	}
// 	free(message);
// 	return (1);
// }

// void send_message(int pid, char *message, int size)
// {
// 	int i;
// 	int x;
// 	static char *str = 0;
// 	if (message)
// 		str = ft_strdup(message);
// 	if(!str)
// 		return ; //fazer função erro para free
// 	i = 0;
// 	while(i <= size)
// 	{
// 		x = 8;
// 		while (x > 0)
// 		{
// 			if (str[i] & 0b10000000)
// 				kill(pid, SIGUSR1);
// 			else
// 				kill(pid, SIGUSR2);
// 			x--;
// 			str[i] = str[i] << 1;
// 			usleep(300);
// 		}
// 		i++;
// 	}
// }

void send_size(int pid, int size)
{
	int i = 8;
	ft_printf("%d\n", size);
		while (i > 0) {
			
			if (size & 0b10000000)
			{
				ft_printf("1");
				kill(pid, SIGUSR1);
			}
			else
			{
				ft_printf("0");
				kill(pid, SIGUSR2);
			}
			i--;
			size = size << 1;
			usleep(100);
		}
	
}
int main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("tente de novo");
		return (0);
	}
	send_size(ft_atoi(av[1]), ft_strlen(av[2]));
	return (1);
}