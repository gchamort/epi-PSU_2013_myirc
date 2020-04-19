/*
** server_quit.c for server_quit.c in /home/chauch_a/rendu/PSU_2013_myftp
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Tue Apr  8 18:46:44 2014 CHAUCHET Alan
** Last update Sun Apr 20 17:57:08 2014 CHAUCHET Alan
*/

#include		"server.h"

void			disconnect_client(t_info *info, t_list_client *prov)
{
  if (has_closed(-1) == 0)
    {
      printf(CLIENT_DISC, prov->client.client_fd);
      close(prov->client.client_fd);
      rm_client(info, prov->client.client_fd);
    }
}

int			server_quit(t_info *info, t_request *request)
{
  t_request		request_part;

  (void)request;
  if (has_closed(-1) == 0)
    {
      if (info->from_client->client.channel != NULL)
	{
	  request_part.param1 = info->from_client->client.channel;
	  server_part(info, &request_part);
	}
      printf(CLIENT_DISC,
	     info->from_client->client.client_fd);
      close(info->from_client->client.client_fd);
      rm_client(info, info->from_client->client.client_fd);
    }
  return (0);
}
