/*
** server_connect.c for server_connect.c in /home/chauch_a/rendu/PSU_2013_myftp
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Sat Apr 12 17:27:39 2014 CHAUCHET Alan
** Last update Sat Apr 12 17:27:56 2014 CHAUCHET Alan
*/

#include		"server.h"

int			server_connect(int port)
{
  int			fd;
  struct sockaddr_in	s_in;

  if ((fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
    {
      perror(SOCKET_FAILED);
      return (-1);
    }
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      perror(BIND_FAILED);
      close(fd);
      return (-1);
    }
  if (listen(fd, MAX_CLIENT) == -1)
    {
      perror(LISTEN_FAILED);
      close(fd);
      return (-1);
    }
  return (fd);
}
