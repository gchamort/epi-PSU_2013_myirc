/*
** server_nick.c for server_nick.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Wed Apr 16 10:41:15 2014 CHAUCHET Alan
** Last update Sun Apr 20 18:28:15 2014 CHAUCHET Alan
*/

#include		"server.h"

static int		tell_channel(t_info *info, t_request *request)
{
  if (strlen(request->param1) > LENGTH_NICK)
    {
      if (send_is_ok(info->from_client, NICK_TOO_LONG,
		     strlen(NICK_TOO_LONG), IS_NOK) == -1)
	return (-1);
      return (1);
    }
  if (info->from_client->client.channel == NULL)
    {
      if (info->from_client->client.nickname != NULL)
	free(info->from_client->client.nickname);
      info->from_client->client.nickname = strdup(request->param1);
      if (send_is_ok(info->from_client,
		     NICK_CHANGED, strlen(NICK_CHANGED), IS_OK) == -1)
	return (-1);
      return (1);
    }
  return (0);
}

int			server_nick(t_info *info, t_request *request)
{
  char			*msg;

  if (nickname_exists(info, request->param1))
    return (send_is_ok(info->from_client, NICK_EXISTS,
		       strlen(NICK_EXISTS), IS_NOK));
  if (tell_channel(info, request) == 1)
    return (0);
  if ((msg = malloc(strlen(MSG_NICK) + strlen(request->param1) + 1)) == NULL)
    return (-1);
  strcpy(msg, MSG_NICK);
  strcpy(&msg[strlen(MSG_NICK)], request->param1);
  if (write_info(info, msg, info->from_client->client.channel,
		 NULL) == -1)
    return (-1);
  if (info->from_client->client.nickname != NULL)
    free(info->from_client->client.nickname);
  info->from_client->client.nickname = strdup(request->param1);
  if (send_is_ok(info->from_client,
		 NICK_CHANGED, strlen(NICK_CHANGED), IS_OK) == -1)
    return (-1);
  free(msg);
  return (0);
}
