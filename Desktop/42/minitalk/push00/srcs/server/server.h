#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <stdint.h>
# include "../../libs/libft/libft.h"

typedef struct s_client
{
	int32_t	pid;
	uint8_t	defined;
}	t_client;

t_client	client;

void	bit_handler(int signal);
void    byte_handler(uint8_t byte);

#endif