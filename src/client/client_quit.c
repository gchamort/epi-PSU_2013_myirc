/*
** client_quit.c for client_quit.c in /home/chauch_a/rendu/PSU_2013_myftp
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Tue Apr  8 15:37:39 2014 CHAUCHET Alan
** Last update Sun Apr 20 15:44:32 2014 CHAUCHET Alan
*/

#include		"client.h"

int			client_quit(t_info *info)
{
  send_data("/quit\n", strlen("/quit\n"), info->fd);
  close(info->fd);
  info->fd = -1;
  printf("Disconnected from server\n");
  info->stop = TRUE;
  return (0);
}
