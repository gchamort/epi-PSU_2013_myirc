/*
** handle_sig_pipe.c for handle_sig_pipe.c in /home/chauch_a/rendu/PSU_2013_myftp
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Sun Apr 13 19:37:44 2014 CHAUCHET Alan
** Last update Sun Apr 20 17:56:37 2014 CHAUCHET Alan
*/

#include		"server.h"

int			has_closed(int val)
{
  static int		ret = 0;

  if (val != -1)
    ret = val;
  return (ret);
}

void			handle_sig_pipe(int sig)
{
  t_info		*info;

  (void)sig;
  info = get_current_info(NULL);
  disconnect_client(info, info->from_client);
  has_closed(1);
}
