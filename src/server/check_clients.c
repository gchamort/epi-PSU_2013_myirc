/*
** check_clients.c for check_clients.c in /home/chauch_a/rendu/PSU_2013_myftp
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Sat Apr 12 17:26:11 2014 CHAUCHET Alan
** Last update Sun Apr 20 17:58:23 2014 CHAUCHET Alan
*/

#include		"server.h"

t_info			*get_current_info(t_info *new_info)
{
  static t_info		*info;

  if (new_info != NULL)
    info = new_info;
  return (info);
}

void			check_on_write(t_list_client *prov,
				       fd_set *list_fd_w)
{
  if (prov->client.to_send != NULL &&
      FD_ISSET(prov->client.client_fd, list_fd_w))
    {
      send_data(prov->client.to_send, strlen(prov->client.to_send),
		prov->client.client_fd);
      free(prov->client.to_send);
      prov->client.to_send = NULL;
    }
}

void			check_clients(t_info *info, fd_set *list_fd_r,
				      fd_set *list_fd_w)
{
  int			ret;
  t_list_client		*prov;
  t_list_client		*tmp;

  prov = info->list_client;
  while (prov != NULL)
    {
      tmp = prov->next;
      check_on_write(prov, list_fd_w);
      if (FD_ISSET(prov->client.client_fd, list_fd_r))
	{
	  info->from_client = prov;
	  get_current_info(info);
	  if ((ret = check_cmd(info)) == -1)
	    {
	      disconnect_client(info, prov);
	      if (info->list_client == NULL)
		return ;
	    }
	}
      has_closed(0);
      prov = tmp;
    }
  return ;
}
