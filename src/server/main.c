/*
** main.c<2> for main.c<2> in /home/chauch_a/rendu/PSU_2013_myftp
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Tue Apr  8 11:44:36 2014 CHAUCHET Alan
** Last update Wed Apr 16 11:34:57 2014 CHAUCHET Alan
*/

#include		"server.h"

int			main(int ac, char **av)
{
  if (ac == 2)
    return (server(atoi(av[1])));
  else
    return (server(DEFAULT_PORT));
}
