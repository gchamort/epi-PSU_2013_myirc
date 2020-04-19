/*
** call_select.c for call_select.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Mon Apr 14 17:17:56 2014 CHAUCHET Alan
** Last update Mon Apr 14 17:19:24 2014 CHAUCHET Alan
*/

#include		"shared_info.h"

int			call_select(int size, fd_set *list_fd_r,
				    fd_set *list_fd_w)
{
  return (select(size, list_fd_r, list_fd_w, NULL, NULL));
}
