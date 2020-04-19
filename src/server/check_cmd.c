/*
** check_cmd.c for check_cmd.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Sun Apr 20 17:47:11 2014 CHAUCHET Alan
** Last update Sun Apr 20 17:49:46 2014 CHAUCHET Alan
*/

#include		"server.h"

static t_func_ptr	g_func_ptr[10] =
  {
    {NICK_CMD, &server_nick, NICK},
    {LIST_CMD, &server_list, LIST},
    {JOIN_CMD, &server_join, JOIN},
    {PART_CMD, &server_part, PART},
    {USERS_CMD, &server_users, USERS},
    {MSG_CMD, &server_msg, MSG},
    {SEND_CMD, &server_send, SEND},
    {ACCEPT_CMD, &server_accept, ACCEPT},
    {QUIT_CMD, &server_quit, QUIT},
    {NULL, &server_message, MESSAGE}
  };

void			create_request(t_request *request, int count,
				       char **cmd, char *line)
{
  if (count == 9)
    {
      request->type = MESSAGE;
      request->param1 = line;
    }
  else if (count == 5)
    {
      request->type = MSG;
      request->param1 = cmd[1];
      request->param2 = line;
    }
  else
    {
      request->type = g_func_ptr[count].type;
      request->param1 = NULL;
      request->param2 = NULL;
      if (cmd[1] != NULL)
	{
	  request->param1 = cmd[1];
	  if (cmd[2] != NULL)
	    request->param2 = cmd[2];
	}
    }
}

void			fill_buffer(t_info *info, char *line)
{
  t_client		*client;

  client = &info->from_client->client;
  if (strlen(line) + strlen(client->buff.buffer) > LENGTH_MAX)
    return ;
  strcpy(&(client->buff.buffer[strlen(client->buff.buffer)]), line);
  if (client->buff.buffer[strlen(client->buff.buffer) - 1] == '\n')
    client->buff.is_ready = TRUE;
}

void			end_command(t_info *info, t_request *request, char **cmd)
{
  int			count;

  count = 0;
  while (cmd[count])
    free(cmd[count++]);
  free(cmd);
  if (request->type != QUIT)
    {
      memset(info->from_client->client.buff.buffer, 0, LENGTH_MAX + 1);
      info->from_client->client.buff.is_ready = FALSE;
    }
}

int			check_cmd(t_info *info)
{
  int			ret;
  int			count;
  char			*line;
  char			**cmd;
  t_request		request;

  if ((line = receve_data(512, info->from_client->client.client_fd)) == NULL)
    return (-1);
  fill_buffer(info, line);
  if (info->from_client->client.buff.is_ready == FALSE)
    return (0);
  if ((cmd = my_str_to_wordtab(info->from_client->client.buff.buffer)) == NULL)
    return (-1);
  if (cmd[0] == NULL)
    return (0);
  count = 0;
  while (count < 9 && strcmp(cmd[0], g_func_ptr[count].type_str))
    count++;
  create_request(&request, count, cmd, info->from_client->client.buff.buffer);
  ret = (g_func_ptr[(int)(request.type)].type_func)(info, &request);
  end_command(info, &request, cmd);
  return (ret);
}
