/*
** server_join.c for server_join.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Wed Apr 16 10:42:38 2014 CHAUCHET Alan
** Last update Sun Apr 20 17:08:07 2014 CHAUCHET Alan
*/

#include		"server.h"

int			server_join(t_info *info, t_request *request)
{
  if (request->param1 == NULL || strlen(request->param1) > 9)
    return (send_is_ok(info->from_client,
		       BAD_NICK, strlen(BAD_NICK), IS_NOK));
  if (info->from_client->client.nickname == NULL)
    return (send_is_ok(info->from_client,
		       CHANNEL_NICK, strlen(CHANNEL_NICK), IS_NOK));
  if (info->from_client->client.channel != NULL)
    free(info->from_client->client.channel);
  info->from_client->client.channel = strdup(request->param1);
  if (write_info(info, CLIENT_JOIN, info->from_client->client.channel,
		 NULL) == -1)
    return (-1);
  return (send_is_ok(info->from_client,
		     CHANNEL_CHANGED, strlen(CHANNEL_CHANGED), IS_OK));
}
