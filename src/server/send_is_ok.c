/*
** send_is_ok.c for send_is_ok.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Wed Apr 16 16:40:34 2014 CHAUCHET Alan
** Last update Sun Apr 20 17:52:47 2014 CHAUCHET Alan
*/

#include		"server.h"

static t_send_name	g_send_name[5] =
  {
    {ERROR_RET},
    {SUCCESS_RET},
    {MSG_RET},
    {FILE_RET},
    {INFO_RET}
  };

int			send_is_ok(t_list_client *client, void *to_send,
				   size_t size_send, e_request is_ok)
{
  int			pos;
  char			*msg;
  int			len;

  if ((msg = malloc(size_send + 16)) == NULL)
    return (-1);
  memset(msg, 0, size_send + 15);
  strcpy(msg, g_send_name[(int)is_ok].name);
  pos = strlen(g_send_name[(int)is_ok].name);
  msg[pos] = ' ';
  strcpy(&msg[pos + 1], (char *)to_send);
  msg[strlen(msg)] = '\n';
  len = (client->client.to_send == NULL) ? 0 : strlen(client->client.to_send);
  if ((client->client.to_send = realloc(client->client.to_send, len
					+ strlen(msg) + 1)) == NULL)
    {
      free(msg);
      fprintf(stderr, MALLOC_FAILED);
      return (-1);
    }
  strcpy(&(client->client.to_send[len]), msg);
  free(msg);
  return (0);
}
