/*
** tcp_ip.c for tcp_ip.c in /home/chauch_a/test
**
** Made by CHAUCHET Alan
** Login   <chauch_a@epitech.net>
**
** Started on  Mon Apr  7 15:20:55 2014 CHAUCHET Alan
** Last update Sun Apr 20 18:08:37 2014 CHAUCHET Alan
*/

#include		"client.h"

int			end_client(t_info *info)
{
  if (info->fd != -1)
    client_quit(info);
  printf(CONNECT_LOST);
  return (EXIT_SUCCESS);
}

void			init_info(t_info *info)
{
  info->fd = -1;
  signal(SIGINT, handle_ctrl_c);
  signal(SIGTERM, handle_ctrl_c);
  signal(SIGPIPE, handle_sig_pipe);
  write(1, PROMPT, strlen(PROMPT));
  info->stop = FALSE;
}

void			check_on_select(t_info *info, char *line,
					fd_set *list_fd)
{
  size_t		len;

  if (info->stop == FALSE && info->fd != -1 && FD_ISSET(info->fd, list_fd))
    {
      if (receve_from_server(info) == -1)
	client_quit(info);
      else
	write(1, PROMPT, strlen(PROMPT));
    }
  if (info->stop == FALSE && FD_ISSET(0, list_fd))
    {
      if (getline(&line, &len, stdin) > 0)
	{
	  if (strlen(line) > LENGTH_MAX)
	    fprintf(stderr, "ERROR: command too long\n");
	  else if (handle_cmd(info, line) == -1)
	    client_quit(info);
	  else if (info->stop == FALSE)
	    write(1, PROMPT, strlen(PROMPT));
	}
      else if (strlen(line) == 0)
	client_quit(info);
    }
}

int			client(void)
{
  t_info		info;
  char			*line;
  fd_set		list_fd;

  init_info(&info);
  line = NULL;
  while (info.stop == FALSE)
    {
      FD_ZERO(&list_fd);
      FD_SET(0, &list_fd);
      if (info.fd != -1)
	FD_SET(info.fd, &list_fd);
      if (line != NULL)
	memset(line, '\0', strlen(line));
      if (call_select(((info.fd > 0) ? info.fd + 1 : 1), &list_fd, NULL) == -1
	  && has_ctrl_c(-1) == 0)
	{
	  info.stop = TRUE;
	  perror("ERROR: select failed");
	}
      if (has_ctrl_c(-1) == 0)
	check_on_select(&info, line, &list_fd);
      has_ctrl_c(0);
    }
  return (end_client(&info));
}
