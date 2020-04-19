/*
** write_msg.c for write_msg.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Thu Apr 17 14:25:44 2014 CHAUCHET Alan
** Last update Sun Apr 20 18:14:07 2014 CHAUCHET Alan
*/

#include		"server.h"

static int		is_cond(t_info *info, t_list_client *prov,
				char *channel, char *nickname)
{
  if (prov != info->from_client)
    if (channel == NULL || (prov->client.channel &&
			    !strcmp(channel, prov->client.channel)))
      if (nickname == NULL || (prov->client.nickname &&
			       !strcmp(nickname, prov->client.nickname)))
	return (1);
  return (0);
}

static char		*create_msg(t_info *info, char *msg)
{
  char			*str_msg;
  size_t		size;

  size = strlen(msg) + strlen(info->from_client->client.nickname) + 3;
  if ((str_msg = malloc(size)) == NULL)
    {
      fprintf(stderr, MALLOC_FAILED);
      return (NULL);
    }
  memset(str_msg, '\0', size);
  strcpy(str_msg, info->from_client->client.nickname);
  strcpy(str_msg + strlen(info->from_client->client.nickname), ": ");
  strcpy(str_msg + strlen(info->from_client->client.nickname) + 2, msg);
  return (str_msg);
}

int			write_msg(t_info *info, char *msg,
				  char *channel, char *nickname)
{
  t_list_client		*prov;
  char			*str_msg;

  if (info->from_client->client.nickname == NULL)
    return (1);
  prov = info->list_client;
  if ((str_msg = create_msg(info, msg)) == NULL)
    return (-1);
  while (prov)
    {
      if (is_cond(info, prov, channel, nickname) &&
	  send_is_ok(prov, str_msg, strlen(str_msg), IS_MSG) == -1)
	{
	  free(str_msg);
	  return (1);
	}
      prov = prov->next;
    }
  free(str_msg);
  return (0);
}

int			write_info(t_info *info, char *msg,
				  char *channel, char *nickname)
{
  t_list_client		*prov;
  char			*str_msg;

  if (info->from_client->client.nickname == NULL)
    return (1);
  prov = info->list_client;
  if ((str_msg = create_msg(info, msg)) == NULL)
    return (-1);
  while (prov)
    {
      if (is_cond(info, prov, channel, nickname) &&
	  send_is_ok(prov, str_msg, strlen(str_msg), IS_INFO) == -1)
	{
	  free(str_msg);
	  return (1);
	}
      prov = prov->next;
    }
  free(str_msg);
  return (0);
}
