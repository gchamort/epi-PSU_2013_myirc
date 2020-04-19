/*
** receve_from_server.c for receve_from_server.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Wed Apr 16 16:11:14 2014 CHAUCHET Alan
** Last update Sun Apr 20 16:19:09 2014 CHAUCHET Alan
*/

#include		"client.h"

static t_answer		g_answer[2] =
  {
    {ERROR_RET, &receve_is_nok},
    {FILE_RET, &receve_is_file}
  };

int			receve_is_ok(t_info *info, void *data)
{
  (void)info;
  printf("%s", (char *)data);
  return (0);
}

int			receve_is_nok(t_info *info, void *data)
{
  (void)info;
  fprintf(stderr, "%s", (char *)data);
  return (0);
}

int			receve_is_file(t_info *info, void *data)
{
  (void)info;
  (void)data;
  return (0);
}

int			receve_from_server(t_info *info)
{
  int			count;
  char			**cmd;
  char			*answer;
  int			ret;

  if ((answer = receve_data(512, info->fd)) == NULL ||
      (cmd = my_str_to_wordtab(answer)) == NULL)
    return (-1);
  if (!cmd[0])
    return (0);
  count = 0;
  while (count < 2 && strcmp(cmd[0], g_answer[count].cmd_cmp))
    count++;
  if (count >= 2)
    ret = receve_is_ok(info, answer);
  else
    ret = (g_answer[count].cmd_func)(info, answer);
  count = 0;
  while (cmd[count])
    free(cmd[count++]);
  free(cmd);
  return (ret);
}
