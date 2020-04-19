/*
** tcp_ip.c for tcp_ip.c in /home/chauch_a/test
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Mon Apr  7 15:20:55 2014 CHAUCHET Alan
** Last update Sun Apr 20 17:53:24 2014 CHAUCHET Alan
*/

#include		"server.h"

static int		get_stop(int new_val)
{
  static int		stop = 0;

  if (new_val != 0)
    stop = new_val;
  return (stop);
}

static void		close_connect(t_info *info)
{
  t_list_client		*prov;

  close(info->fd_socket);
  while (info->list_client != NULL)
    {
      close(info->list_client->client.client_fd);
      prov = info->list_client;
      info->list_client = info->list_client->next;
      if (prov->client.nickname != NULL)
      free(prov->client.nickname);
      free(prov);
    }
}

static void		handle_ctrl_c(int sig)
{
  (void)sig;
  get_stop(1);
}

static void		my_select(t_info *info, fd_set *list_fd_r,
				       fd_set *list_fd_w)
{
  int			higher;

  FD_ZERO(list_fd_r);
  FD_ZERO(list_fd_w);
  FD_SET(info->fd_socket, list_fd_r);
  select_client(info, list_fd_r, list_fd_w);
  higher = higher_client(info);
  if (call_select(((higher > info->fd_socket) ? higher + 1 :
		   info->fd_socket + 1),
		  list_fd_r, list_fd_w) == -1 && get_stop(0) == 0)
    {
      perror(SELECT_FAIL);
      get_stop(1);
    }
  else
    if (get_stop(0) == 0)
      {
	if (FD_ISSET(info->fd_socket, list_fd_r))
	  accept_client(info);
	check_clients(info, list_fd_r, list_fd_w);
      }
}

int			server(int port)
{
  t_info		info;
  fd_set		list_fd_r;
  fd_set		list_fd_w;

  info.list_client = NULL;
  info.nb_client = 0;
  signal(SIGINT, handle_ctrl_c);
  signal(SIGTERM, handle_ctrl_c);
  signal(SIGPIPE, handle_sig_pipe);
  if ((info.fd_socket = server_connect(port)) == -1)
    return (EXIT_FAILURE);
  while (get_stop(0) == 0)
    my_select(&info, &list_fd_r, &list_fd_w);
  printf(SERVER_END);
  close_connect(&info);
  return (0);
}
