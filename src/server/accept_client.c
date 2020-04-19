/*
** accept_client.c for accept_client.c in /home/chauch_a/rendu/PSU_2013_myftp
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Sat Apr 12 17:28:56 2014 CHAUCHET Alan
** Last update Tue Apr 15 12:20:41 2014 CHAUCHET Alan
*/

#include		"server.h"

void			accept_client(t_info *info)
{
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  int			client_fd;

  s_in_size = sizeof(s_in_client);
  client_fd = accept(info->fd_socket, (struct sockaddr *)&s_in_client,
		     &s_in_size);
  if (client_fd == -1)
    {
      perror(NO_MORE);
      return ;
    }
  if (add_client(info, client_fd) == -1)
    {
      fprintf(stderr, NO_MORE);
      return ;
    }
  printf(NEW_CLIENT, client_fd);
}
