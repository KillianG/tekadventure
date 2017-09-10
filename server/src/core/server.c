/*
** main.c for tekadventure in /home/segfault/Desktop/tekaventure
** 
** Made by Marc PEREZ
** Login   <marc.perez@epitech.eu>
** 
** Started on  Wed Sep  6 19:09:00 2017 Marc PEREZ
<<<<<<< HEAD:server/src/core/server.c
** Last update Sun Sep 10 13:15:19 2017 Killian
=======
** Last update Fri Sep  8 15:19:30 2017 Marc PEREZ
>>>>>>> 29937771bfc938a13c7170c11e65c5cc56e2a990:server/src/core/main.c
*/

#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>
#include <sys/queue.h>
#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/bufferevent.h>
#include "server.h"
#include "game.h"

static struct event_base	*g_evbase;

void		buffered_on_read(struct bufferevent *bev, void *arg)
{
  t_client	*client;
  t_player	data;
  size_t	n;

  while (1)
    {
      n = bufferevent_read(bev, &data, sizeof(data));
      if (n <= 0)
	break;
      TAILQ_FOREACH(client, &g_client_tailq_head, entries)
	{
	  if (client != (t_client *)arg)
	    {
	      bufferevent_write(client->buf_ev, &data, n);
	    }
	}
    }

}

void	buffered_on_error(struct bufferevent *bev, short what, void *arg)
{
  (void)bev;
  if (what & BEV_EVENT_EOF)
    {
      printf("Client disconnected.\n");
    }
  else
    {
      warn("Client socket error, disconnecting.\n");
    }
  TAILQ_REMOVE(&g_client_tailq_head, (t_client *)arg, entries);
  bufferevent_free(((t_client *)arg)->buf_ev);
  close(((t_client *)arg)->fd);
  free(arg);
}

void			on_accept(int fd, short ev, void *arg)
{
  struct sockaddr_in	client_addr;
  socklen_t		client_len;
  int			client_fd;
  t_client		*client;

  (void)ev;
  (void)arg;
  client_len = sizeof(client_addr);
  client_fd = accept(fd, (struct sockaddr *)&client_addr, &client_len);
  if (client_fd < 0)
    {
      warn("accept failed");
      return;
    }
  if (setnonblock(client_fd) < 0)
    warn("failed to set client socket non-blocking");
  if ((client = calloc(1, sizeof(*client))) == NULL)
    ERR_EXIT(1, "calloc failed", 1);
  client->fd = client_fd;
  client->buf_ev = bufferevent_socket_new(g_evbase, client_fd, 0);
  bufferevent_setcb(client->buf_ev, buffered_on_read, NULL,
		    buffered_on_error, client);
  bufferevent_enable(client->buf_ev, EV_READ);
  TAILQ_INSERT_TAIL(&g_client_tailq_head, client, entries);
  printf("Accepted connection from %s\n", inet_ntoa(client_addr.sin_addr));
}
<<<<<<< HEAD:server/src/core/server.c
=======

int		main(int argc, char **argv)
{
  struct event	ev_accept;
  int		listen_fd;

  if (argc == 2)
    {
  g_evbase = event_base_new();
  TAILQ_INIT(&g_client_tailq_head);
  init_socket(argv[1], &listen_fd);
  if (setnonblock(listen_fd) < 0)
    err(1, "failed to set server socket to non-blocking");
  event_assign(&ev_accept, g_evbase, listen_fd, EV_READ | EV_PERSIST,
	       on_accept, NULL);
  event_add(&ev_accept, NULL);
  event_base_dispatch(g_evbase);
    }
  else
    printf("USAGE: %s PORT\n", argv[0]);
  return (0);
}
>>>>>>> 29937771bfc938a13c7170c11e65c5cc56e2a990:server/src/core/main.c
