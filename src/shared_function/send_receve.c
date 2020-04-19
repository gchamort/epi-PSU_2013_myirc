/*
** send_receve.c for send_receve.c in /home/chauch_a/rendu/PSU_2013_myirc
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Mon Apr 14 16:49:59 2014 CHAUCHET Alan
** Last update Sat Apr 19 18:52:23 2014 CHAUCHET Alan
*/

#include		"shared_info.h"

int			send_data(void *data, size_t size_data, int fd)
{
  int			len;
  int			len2;

  len = 0;
  while ((len2 = write(fd, data + len, size_data - len))
	 < (int)(size_data) - len)
    {
      if (len2 <= 0)
	{
	  perror(BAD_WRITE);
	  return (-1);
	}
      len += len2;
    }
  return (0);
}

void			*receve_data(size_t size_data, int fd)
{
  void			*data;

  if ((data = malloc(size_data + 1)) == NULL)
    {
      fprintf(stderr, MALLOC_FAILED);
      return (NULL);
    }
  memset(data, 0, size_data + 1);
  if (read(fd, data, size_data) <= 0)
    {
      perror(BAD_READ);
      return (NULL);
    }
  return (data);
}
