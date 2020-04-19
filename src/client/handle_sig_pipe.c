/*
** handle_sig_pipe.c for handle_sig_pipe.c in /home/chauch_a/rendu/PSU_2013_myftp
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Sun Apr 13 19:50:53 2014 CHAUCHET Alan
** Last update Sun Apr 13 19:55:17 2014 CHAUCHET Alan
*/

#include		"client.h"

int			get_socket(int new_fd)
{
  static int		fd = 0;

  if (new_fd != 0)
    fd = new_fd;
  return (fd);
}

void			handle_sig_pipe(int sig)
{
  (void)sig;
  close(get_socket(0));
  fprintf(stderr, "ERROR: you have been siconnected.\n");
  exit(1);
}
