/*
** add_client.c for add_client.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Mon Apr 14 19:18:53 2014 CHAUCHET Alan
** Last update Sun Apr 20 16:24:05 2014 CHAUCHET Alan
*/

#include		"server.h"

static void		init_new(t_list_client *new, int new_client_fd)
{
  new->client.client_fd = new_client_fd;
  new->client.nickname = NULL;
  new->client.channel = NULL;
  new->client.to_send = NULL;
  memset(new->client.buff.buffer, 0, LENGTH_MAX + 1);
  new->client.buff.is_ready = FALSE;
  new->next = NULL;
}

int			add_client(t_info *info, int new_client_fd)
{
  t_list_client		*prov;
  t_list_client		*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    {
      fprintf(stderr, MALLOC_FAILED);
      return (-1);
    }
  init_new(new, new_client_fd);
  info->nb_client++;
  if (info->list_client == NULL)
    {
      info->list_client = new;
      new->prev = NULL;
      return (0);
    }
  prov = info->list_client;
  while (prov->next)
    prov = prov->next;
  prov->next = new;
  new->prev = prov;
  return (0);
}
