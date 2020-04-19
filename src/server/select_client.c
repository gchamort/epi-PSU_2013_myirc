/*
** select_client.c for select_client.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Mon Apr 14 19:46:56 2014 CHAUCHET Alan
** Last update Sun Apr 20 16:25:16 2014 CHAUCHET Alan
*/

#include		"server.h"

void			select_client(t_info *info, fd_set *list_fd_r,
				      fd_set *list_fd_w)
{
  t_list_client         *prov;

  prov = info->list_client;
  while (prov != NULL)
    {
      FD_SET(prov->client.client_fd, list_fd_r);
      if (prov->client.to_send != NULL)
	FD_SET(prov->client.client_fd, list_fd_w);
      prov = prov->next;
    }
}
