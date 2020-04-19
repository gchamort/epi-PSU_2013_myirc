/*
** client_accept.c for client_accept.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Tue Apr 15 15:32:32 2014 CHAUCHET Alan
** Last update Tue Apr 15 15:32:40 2014 CHAUCHET Alan
*/

#include		"client.h"

int			client_accept(t_info *info)
{
  if (info->fd == -1)
    {
      fprintf(stderr, NO_CONNECT);
      return (0);
    }
  return (0);
}
