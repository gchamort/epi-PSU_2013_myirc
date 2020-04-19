/*
** higher_client.c for higher_client.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Tue Apr 15 12:15:11 2014 CHAUCHET Alan
** Last update Tue Apr 15 12:16:34 2014 CHAUCHET Alan
*/

#include		"server.h"

int			higher_client(t_info *info)
{
  int			higher;
  t_list_client		*prov;

  higher = 0;
  prov = info->list_client;
  while (prov != NULL)
    {
      if (higher < prov->client.client_fd)
	higher = prov->client.client_fd;
      prov = prov->next;
    }
  return (higher);
}
