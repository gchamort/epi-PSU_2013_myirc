/*
** list_users.c for list_users.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Fri Apr 18 10:29:33 2014 CHAUCHET Alan
** Last update Fri Apr 18 12:05:56 2014 CHAUCHET Alan
*/

#include		"server.h"

char			*list_users(t_info *info, char *channel)
{
  char			*ret;
  int			count;
  t_list_client		*prov;

  if ((ret = malloc(info->nb_client * 4097 + 2)) == NULL)
    {
      fprintf(stderr, MALLOC_FAILED);
      return (NULL);
    }
  memset(ret, '\0', info->nb_client * 4096);
  ret[0] = '\n';
  ret[1] = '\n';
  count = 2;
  prov = info->list_client;
  while (prov)
    {
      if (prov->client.channel && !strcmp(channel, prov->client.channel))
	{
	  strcpy(&ret[count], prov->client.nickname);
	  count += strlen(prov->client.nickname) + 1;
	  ret[count - 1] = '\n';
	}
      prov = prov->next;
    }
  return (ret);
}
