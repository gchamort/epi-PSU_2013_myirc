//
// client.h for client.h in /home/chauch_a/rendu/PSU_2013_myftp
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Tue Apr  8 11:20:01 2014 CHAUCHET Alan
// Last update Sun Apr 20 18:07:58 2014 CHAUCHET Alan
//

#ifndef			CLIENT_H_
# define		CLIENT_H_

# include		"shared_info.h"

# define		PROMPT		"CLIENT -> "

# define		USAGE		"Usage: ./client <ip> <port>\n"
# define		SOCKET_FAILED	"socket failed "
# define		CONNECT_FAILED	"connect failed "
# define		BAD_QUIT	"ERROR: wrong numbers of parameters for quit.\n"
# define		NO_QUIT		"\nPlease use ctrl+d or 'quit' to leave.\n"
# define		NO_SERVER	"ERROR: server might be disconnected\n"
# define		CONNECT_LOST	"Connexion lost with server\n"
# define		OPEN_FAILED	"open failed"
# define		PUT_ERROR	"ERROR: serveur cannot create the requested file.\n"
# define		NO_CONNECT	"ERROR: you have to be connected to a server (use /server _host_[:_port_])\n"
# define		BAD_SERVER	"ERROR: Bad usage: /server _host_[:_port_]\n"

typedef struct		s_info
{
  int			fd;
  char			**cmd;
  e_bool		stop;
  char			*line;
}			t_info;

typedef			int (*func_ptr)(t_info *);

typedef struct		s_func_ptr
{
  char			*cmd_val;
  func_ptr		cmd_func;
}			t_fun_ptr;

typedef			int (*func_ret)(t_info *, void *);

typedef struct		s_answer
{
  char			*cmd_cmp;
  func_ret		cmd_func;
}			t_answer;

int			client(void);
int			client_quit(t_info *);
void			handle_sig_pipe(int);
int			handle_cmd(t_info *, char *);
int			client_server(t_info *);
int			client_send(t_info *);
int			client_quit(t_info *);
int			client_connect(char *, int);
int			receve_from_server(t_info *);
int			receve_is_file(t_info *, void *);
int			receve_is_msg(t_info *, void *);
int			receve_is_nok(t_info *, void *);
int			receve_is_ok(t_info *, void *);
int			receve_is_info(t_info *, void *);
void			handle_ctrl_c(int);
int			has_ctrl_c(int);

#endif
