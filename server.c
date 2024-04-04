#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

// char	*print_string(char *message)
// {
// 	ft_printf("%s",message);
// 	free(message);
// 	return (NULL);
// }

// char	*ft_straddc_first(char c)
// {
// 	char	*add;
// 	add = (char *)malloc(sizeof(char) * 2);
// 	if (!add)
// 		return (NULL);
// 	add[0] = c;
// 	add[1] = '\0';
// 	return (add);
// }

// char	*ft_straddc(char *str, char c)
// {
// 	char	*add;
// 	int		i;
// 	if (!c)
// 		return (NULL);
// 	if (!str)
// 		return (ft_straddc_first(c));
// 	add = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
// 	if (!add)
// 	{
// 		free(str);
// 		return (NULL);
// 	}
// 	i = -1;
// 	while (str[++i])
// 		add[i] = str[i];
// 	free(str);
// 	add[i++] = c;
// 	add[i] = '\0';
// 	return (add);
// }

// void sig_handler(int bit)
// {
// 	static char *str = 0;
// 	static int i = 0;
// 	int j = 0;
// 	unsigned char c;
// 	if (bit == SIGUSR2)
// 		c = c << 1;
// 	else if (bit == SIGUSR1)
// 		c = (c << 1) | 0b00000001;
// 	i++;
// 	str = (char *) malloc(sizeof(char) * 100 +1);
// 	if (i == 8)
// 	{
// 		if (c)
// 			str = ft_straddc(str, c);
// 		else
// 			str = print_string(str);
// 		i = 0;
// 		c = 0;
// 	}
// }

// void	sig_handler(int sig)
// {
// 	static int				i = 0;
// 	static unsigned char	c = 0;
// 	if (sig == SIGUSR2)
// 	{
// 		c = c << 1;
// 	}
// 	else if (sig == SIGUSR1)
// 	{
// 		c = (c << 1) | 1;
// 	}
// 	i++;
// 	if (i == 8)
// 	{
// 		ft_printf("%c", c);
// 		i = 0;
// 		c = 0;
// 	}
// }

// int main (void)
// {
// 	ft_printf("PID: %d", getpid());
// 	while(1)
// 	{
// 		signal(SIGUSR1, sig_handler);
// 		signal(SIGUSR2, sig_handler);
// 		pause();
// 	}
// 	return (0);
// }


void	handler(int sig)
{
	static int				i = 0;
	static int	c = 0;

	if (sig == SIGUSR2)
		c = c << 1;
	else if (sig == SIGUSR1)
		c = (c << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		ft_printf("%i", c);
		i = 0;
		c = 0;
	}
}


int main() {
    
	ft_printf("PID: %d", getpid());
	printf("Aguardando tamanho da string...\n");
	while(1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}

    return 0;
}