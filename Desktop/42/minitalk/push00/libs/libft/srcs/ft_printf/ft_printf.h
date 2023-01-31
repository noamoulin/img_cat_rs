#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUFFER_SIZE 42

void	cat(char *buffer, char chr);
void	cat_str(char *buffer, char *str);
char	*stoa(char *str);
char	*ptoa(void *ptr);
char	*ctoa(char chr);
char	*m_itoa(long n);
char	*lhextoa(unsigned int n);
char	*uhextoa(unsigned int n);
int		ft_printf(const char *str, ...);
int		append_chr(char chr, int len);
int		append_str(char *str);

#endif
