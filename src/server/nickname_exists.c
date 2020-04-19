/*
** nickname_exists.c for nickname_exists.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Wed Apr 16 16:46:38 2014 CHAUCHET Alan
** Last update Wed Apr 16 16:49:26 2014 CHAUCHET Alan
*/

#include		"server.h"

int			nickname_exists(t_info *info, char *nickname)
{
  t_list_client		*prov;

  prov = info->list_client;
  while (prov != NULL)
    {
      if (prov->client.nickname != NULL &&
	  strcmp(nickname, prov->client.nickname) == 0)
	return (1);
      prov = prov->next;
    }
  return (0);
}
