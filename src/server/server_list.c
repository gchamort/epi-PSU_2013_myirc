/*
** server_list.c for server_list.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Wed Apr 16 10:42:20 2014 CHAUCHET Alan
** Last update Sun Apr 20 17:07:23 2014 CHAUCHET Alan
*/

#include		"server.h"

static int		is_in_tab(char **tab, char *search, int size)
{
  int			count;

  count = 0;
  while (count < size)
    {
      if (tab[count] != NULL && !strcmp(tab[count], search))
	return (0);
      count++;
    }
  return (1);
}

static void		fill_ret(t_info *info, char *needle,
				 char **tab, char *ret)
{
  int			count;
  int			count2;
  t_list_client		*prov;

  count = 2;
  count2 = 0;
  prov = info->list_client;
  while (prov)
    {
      if (prov->client.channel != NULL &&
	  (needle == NULL || strstr(prov->client.channel, needle))
	  && is_in_tab(tab, prov->client.channel, info->nb_client))
	{
	  strcpy(&ret[count], prov->client.channel);
	  count += strlen(prov->client.channel) + 1;
	  ret[count - 1] = '\n';
	  tab[count2++] = prov->client.channel;
	}
      prov = prov->next;
    }
}

static char		*get_list_channel(t_info *info, char *needle)
{
  int			count;
  char			*ret;
  char			**tab;

  if ((ret = malloc(info->nb_client * 4097 + 2)) == NULL ||
      (tab = malloc(sizeof(char *) * info->nb_client)) == NULL)
    {
      fprintf(stderr, MALLOC_FAILED);
      return (NULL);
    }
  count = 0;
  while (count < info->nb_client)
    tab[count++] = NULL;
  memset(ret, '\0', info->nb_client * 4096);
  ret[0] = '\n';
  ret[1] = '\n';
  fill_ret(info, needle, tab, ret);
  free(tab);
  return (ret);
}

int			server_list(t_info *info, t_request *request)
{
  char			*needle;
  char			*list_channel;

  if (request->param1 != NULL)
    needle = request->param1;
  else
    needle = NULL;
  if ((list_channel = get_list_channel(info, needle)) == NULL)
    return (-1);
  return (send_is_ok(info->from_client,
		     list_channel, strlen(list_channel), IS_OK));
}
