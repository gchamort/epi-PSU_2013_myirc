/*
** server_msg.c for server_msg.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Wed Apr 16 10:43:22 2014 CHAUCHET Alan
** Last update Sun Apr 20 17:08:38 2014 CHAUCHET Alan
*/

#include		"server.h"

int			server_msg(t_info *info, t_request *request)
{
  int			ret;
  char			*dest;
  char			*msg;

  if (request->param1 == NULL || request->param2 == NULL)
    return (send_is_ok(info->from_client,
		       BAD_MSG, strlen(BAD_MSG), IS_NOK));
  dest = request->param1;
  msg = request->param2;
  msg[strlen(msg) - 1] = '\0';
  while (*msg == ' ' || *msg == '\t')
    msg++;
  while (*msg && *msg != ' ' && *msg != '\t')
    msg++;
  while (*msg == ' ' || *msg == '\t')
    msg++;
  while (*msg && *msg != ' ' && *msg != '\t')
    msg++;
  while (*msg == ' ' || *msg == '\t')
    msg++;
  if ((ret = write_msg(info, msg, NULL, dest)) == 1)
    return (send_is_ok(info->from_client,
		       MSG_ERROR, strlen(MSG_ERROR), IS_NOK));
  return (ret);
}
