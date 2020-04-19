/*
** handle_ctrl_c.c for handle_ctrl_c.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Sun Apr 20 18:08:25 2014 CHAUCHET Alan
** Last update Sun Apr 20 18:08:39 2014 CHAUCHET Alan
*/

#include		"client.h"

int			has_ctrl_c(int new_val)
{
  static int		val = 0;

  if (new_val != -1)
    val = new_val;
  return (val);
}

void			handle_ctrl_c(int sig)
{
  (void)sig;
  write(1, NO_QUIT, strlen(NO_QUIT));
  write(1, PROMPT, strlen(PROMPT));
  has_ctrl_c(1);
}
