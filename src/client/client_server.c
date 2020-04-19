/*
** client_server.c for client_server.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Tue Apr 15 15:33:25 2014 CHAUCHET Alan
** Last update Sat Apr 19 18:44:45 2014 CHAUCHET Alan
*/

#include		"client.h"

void			set_host_port(t_info *info, char **host, int *port)
{
  int			count;

  count = 0;
  while (info->cmd[1][count] && info->cmd[1][count] != ':')
    count++;
  if (!(info->cmd[1][count]))
    {
      *host = info->cmd[1];
      *port = DEFAULT_PORT;
    }
  else
    {
      *host = info->cmd[1];
      (*host)[count] = '\0';
      *port = atoi(&(*host)[count + 1]);
    }
}

int			client_server(t_info *info)
{
  char			*host;
  int			port;
  int			new_fd;

  if (info->cmd[1] == NULL || info->cmd[2] != NULL)
    {
      fprintf(stderr, BAD_SERVER);
      return (0);
    }
  set_host_port(info, &host, &port);
  if ((new_fd = client_connect(host, port)) != -1)
    {
      if (info->fd != -1)
	{
	  client_quit(info);
	  info->stop = FALSE;
	}
      info->fd = new_fd;
      printf("SUCCESS\n");
    }
  return (0);
}
