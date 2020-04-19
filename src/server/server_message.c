/*
** server_message.c for server_message.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Wed Apr 16 10:44:10 2014 CHAUCHET Alan
** Last update Sun Apr 20 17:53:07 2014 CHAUCHET Alan
*/

#include		"server.h"

int			server_message(t_info *info, t_request *request)
{
  int			ret;
  char			*msg;

  msg = request->param1;
  msg[strlen(msg) - 1] = '\0';
  if (info->from_client->client.channel == NULL)
    return (send_is_ok(info->from_client,
		       MSG_ERROR, strlen(MSG_ERROR), IS_NOK));
  if ((ret = write_msg(info, msg, info->from_client->client.channel,
		       NULL)) == 1)
    return (send_is_ok(info->from_client,
		       MSG_ERROR, strlen(MSG_ERROR), IS_NOK));
  return (ret);
}
