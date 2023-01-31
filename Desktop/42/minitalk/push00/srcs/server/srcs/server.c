
#include "../server.h"

void	byte_handler(uint8_t byte)
{
	static uint32_t	recieved = 0;

	++recieved;
	if (recieved <= 3)
	{
		if (recieved == 1)
			client.pid |= (int32_t)byte;
		else if (recieved == 2)
			client.pid |= ((int32_t)byte) << 8;
		else
		{
			client.pid |= ((int32_t)byte) << 16;
			client.defined = 1;
			ft_printf("Message de : %d\n\n", client.pid);
		}
	}
	else if (!byte)
	{
		ft_printf("\nFin du message, %d octets recus.\n", recieved - 5);
		recieved = 0;
		client.pid = 0;
		client.defined = 0;
	}
	else
		ft_putchar_fd(byte, STDOUT_FILENO);
}

void	bit_handler(int signal)
{
	static uint8_t	byte = 0;
	static uint8_t	count = 0;
	static uint8_t	mask = 1;

	if (signal == SIGUSR1)
		byte |= mask;
	++count;
	if (count == 8)
	{
		byte_handler(byte);
		byte = 0;
		count = 0;
		mask = 1;
	}
	else 
		mask <<= 1;
	if (client.defined)
		kill(client.pid, SIGUSR1);
}