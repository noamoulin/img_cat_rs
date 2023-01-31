#include "../client.h"

void	send_string(int pid, char *str)
{
	while (*str)
		send_byte(pid, (*(str++)));
	send_byte(pid, '\n');
	send_byte(pid, 0);
}

void	send_bit(int pid, uint8_t bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(1000);
}

void send_byte(int pid, uint8_t byte)
{
	uint8_t count;

	count = 0;
	while (count < 8)
	{
		if (byte & (1 << count))
			send_bit(pid, 1);
		else
			send_bit(pid, 0);
		++count;
	}
}

void	send_byte_force(int pid, uint8_t byte, uint32_t delay)
{
	uint8_t count;

	count = 0;
	while (count < 8)
	{
		if (byte & (1 << count))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(delay);
		++count;
	}
}

void    send_pid(int spid)
{
	uint32_t	pid;

	pid = getpid();
	send_byte_force(spid, (uint8_t)pid, DBIT_DELAY);
	send_byte_force(spid, (uint8_t)(pid >> 8), DBIT_DELAY);
	send_byte_force(spid, (uint8_t)(pid >> 16), DBIT_DELAY);
}