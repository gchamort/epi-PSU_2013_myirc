/*
** rm_client.c for rm_client.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Mon Apr 14 19:43:10 2014 CHAUCHET Alan
** Last update Sun Apr 20 19:27:42 2014 CHAUCHET Alan
*/

#include		"server.h"

static void		is_not_first(t_info *info, int client_fd,
				     t_list_client *prov)
{
  while (prov != NULL && prov->client.client_fd != client_fd)
    prov = prov->next;
  if (prov == NULL)
    return ;
  if (prov->client.nickname)
    free(prov->client.nickname);
  if (prov->client.channel)
    free(prov->client.channel);
  if (prov->prev != NULL)
    prov->prev->next = prov->next;
  if (prov->next != NULL)
    prov->next->prev = prov->prev;
  free(prov);
  info->nb_client--;
}

void			rm_client(t_info *info, int client_fd)
{
  t_list_client		*prov;

  if (info->list_client == NULL)
    return ;
  prov = info->list_client;
  if (info->list_client->client.client_fd == client_fd)
    {
      if (info->list_client->client.nickname)
	free(info->list_client->client.nickname);
      if (info->list_client->client.channel)
	free(info->list_client->client.channel);
      info->nb_client--;
      info->list_client = info->list_client->next;
      if (info->list_client != NULL)
	info->list_client->prev = NULL;
      free(prov);
      return ;
    }
  is_not_first(info, client_fd, prov);
}
