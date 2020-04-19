/*
** handle_cmd.c for handle_cmd.c in /home/chauch_a/rendu/PSU_2013_myftp
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Sat Apr 12 18:04:56 2014 CHAUCHET Alan
** Last update Sun Apr 20 15:06:42 2014 CHAUCHET Alan
*/

#include		"client.h"

static t_fun_ptr	func_call[3] =
  {
    {SERVER_CMD, &client_server},
    {QUIT_CMD, &client_quit},
    {SEND_CMD, &client_send}
  };

int			handle_cmd(t_info *info, char *line)
{
  int			ret;
  int			count;

  info->line = line;
  if ((info->cmd = my_str_to_wordtab(line)) == NULL)
    return (-1);
  if (info->cmd[0] == NULL)
    return (0);
  count = 0;
  while (count < 3 && strcmp(info->cmd[0], func_call[count].cmd_val))
    count++;
  if (count == 3)
    send_data(line, strlen(line), info->fd);
  else
    ret = (func_call[count].cmd_func)(info);
  count = 0;
  while (info->cmd[count])
    free(info->cmd[count++]);
  free(info->cmd);
  return (ret);
}
