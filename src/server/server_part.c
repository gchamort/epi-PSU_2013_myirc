/*
** server_part.c for server_part.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Wed Apr 16 10:42:52 2014 CHAUCHET Alan
** Last update Sun Apr 20 18:17:25 2014 CHAUCHET Alan
*/

#include		"server.h"

int			server_part(t_info *info, t_request *request)
{
  if (info->from_client->client.channel == NULL ||
      strcmp(info->from_client->client.channel, request->param1))
    return (send_is_ok(info->from_client,
		       NOT_IN_CHANNEL, strlen(NOT_IN_CHANNEL), IS_NOK));
  if (info->from_client->client.channel != NULL)
    free(info->from_client->client.channel);
  if (write_info(info, CLIENT_LEFT, info->from_client->client.channel,
		 NULL) == -1)
    return (-1);
  info->from_client->client.channel = NULL;
  return (send_is_ok(info->from_client,
		     CHANNEL_LEFT, strlen(CHANNEL_LEFT), IS_OK));
}
