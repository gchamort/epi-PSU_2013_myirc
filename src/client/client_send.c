/*
** client_send.c for client_send.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Tue Apr 15 15:32:20 2014 CHAUCHET Alan
** Last update Tue Apr 15 15:32:27 2014 CHAUCHET Alan
*/

#include		"client.h"

int			client_send(t_info *info)
{
  if (info->fd == -1)
    {
      fprintf(stderr, NO_CONNECT);
      return (0);
    }
  return (0);
}
