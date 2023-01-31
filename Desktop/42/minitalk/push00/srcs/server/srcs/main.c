#include "../server.h"

int main(void)
{
	client.pid = 0;
	client.defined = 0;
	ft_printf("PID : %d\n", getpid());
	signal(SIGUSR2, bit_handler);
	signal(SIGUSR1, bit_handler);
	while(1);
	return(0);
}
