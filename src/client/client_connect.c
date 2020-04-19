/*
** client_connect.c for client_connect.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Tue Apr 15 15:38:50 2014 CHAUCHET Alan
** Last update Tue Apr 15 18:59:52 2014 CHAUCHET Alan
*/

#include		"client.h"

int			client_connect(char *ip, int port)
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
  s_in.sin_addr.s_addr = inet_addr(ip);
  if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      perror(CONNECT_FAILED);
      close(fd);
      return (-1);
    }
  return (fd);
}
