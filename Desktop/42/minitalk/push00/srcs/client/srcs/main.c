#include "../client.h"


void bit_received(int signal)
{
    (void)(signal);
    transmitted++;
}

int main(int ac, char **av)
{
    char *msg;
    int pid;

    transmitted = 0;
    signal(SIGUSR1, bit_received);
    if (ac == 3)
    {
        pid = ft_atoi(av[1]);
        msg = av[2];
        send_pid(pid);
        send_string(pid, msg);
        ft_printf("\n%d octets sur %d transmis a %d depuis %d.\n", transmitted / 8 - 2, ft_strlen(msg), pid, getpid());
    }
    else
        ft_putstr_fd("Mauvais parametres. utilisation : [CLIENT] [PID] [MESSAGE]\n", 1);
    return (0);
}