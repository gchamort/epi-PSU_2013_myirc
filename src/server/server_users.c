/*
** server_users.c for server_users.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Wed Apr 16 10:43:09 2014 CHAUCHET Alan
** Last update Sun Apr 20 17:06:29 2014 CHAUCHET Alan
*/

#include		"server.h"

int			server_users(t_info *info, t_request *request)
{
  int			ret;
  char			*list;

  (void)request;
  if (info->from_client->client.channel == NULL)
    return (send_is_ok(info->from_client,
		       NO_CHANNEL, strlen(NO_CHANNEL), IS_NOK));
  if ((list = list_users(info, info->from_client->client.channel)) == NULL)
    return (send_is_ok(info->from_client,
		       NO_INFO, strlen(NO_INFO), IS_NOK));
  ret = send_is_ok(info->from_client,
		   list, strlen(list), IS_OK);
  free(list);
  return (ret);
}
