/*
** client.h for client in /home/segfault/Delivery/Alpha/tekadventure/mark
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Fri Aug 25 14:07:25 2017 Marc PEREZ
** Last update Thu Oct  5 00:31:15 2017 Marc PEREZ
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <err.h>
# include <sys/queue.h>
# include <SFML/Graphics.h>

# define DFL_PORT			12345
# define DATA_SIZE			8192

# define ERR_EXIT(fd, str, code)	{ err(fd, str); exit(code); }

typedef struct		s_client
{
  TAILQ_ENTRY(s_client)	entries;
  struct bufferevent	*buf_ev;
  int			fd;
}			t_client;

TAILQ_HEAD(, s_client)	g_client_tailq_head;

int	setnonblock(int fd);
void	init_socket(char *port, int *listen_fd);


typedef struct		s_packet
{
  int			id;
  sfVector2f		pos;
  int			health;
  _Bool			is_attack;
}			t_packet;

#endif /* !SERVER_H_ */
