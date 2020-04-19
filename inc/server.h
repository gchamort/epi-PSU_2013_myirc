//
// server.h for server.h in /home/chauch_a/rendu/PSU_2013_myirc
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 18 11:38:27 2014 CHAUCHET Alan
// Last update Mon Apr 21 14:52:22 2014 CHAUCHET Alan
//

#ifndef			SERVER_H_
# define		SERVER_H_

# include		"shared_info.h"

# define		MAX_CLIENT	8000

# define		LENGTH_NICK	9

# define		USAGE		"Usage: ./serveur <port>\n"
# define		SOCKET_FAILED	"socket failed "
# define		BIND_FAILED	"bind failed "
# define		LISTEN_FAILED	"listen failed "
# define		NO_CLIENT	"ERROR: connection might be lost with client.\n"
# define		NO_PATH		"cannot find client's path."
# define		NEW_CLIENT	"New client added. ID is [%d]\n"
# define		NO_MORE		"ERROR: cannot add a new client.\n"
# define		CLIENT_DISC	"Client with id [%d] just quit\n"
# define		SELECT_FAIL	"select failed"
# define		START_DIR	"Starting directory is : '%s'\n"
# define		SERVER_END	"\nServer quit\n"
# define		NICK_EXISTS	"nickname already exists"
# define		NICK_CHANGED	"nickname correctly changed."
# define		CHANNEL_NICK	"please declare a nickname before joinning a channel"
# define		CHANNEL_CHANGED	"channel correctly changed."
# define		NOT_IN_CHANNEL	"not connected to this channel"
# define		CHANNEL_LEFT	"channel correctly left"
# define		MSG_SEND	"message correctly send"
# define		MSG_ERROR	"message not send"
# define		CLIENT_LEFT	"just left the channel"
# define		CLIENT_JOIN	"just enter the channel"
# define		MSG_NICK	"changed his nickname to: "
# define		NO_CHANNEL	"you first need to join a channel"
# define		NO_INFO		"cannot get info"
# define		NICK_TOO_LONG	"nickname is too long (maximum is 9 characters)"

typedef struct		s_tamp_buff
{
  char			buffer[LENGTH_MAX + 1];
  e_bool		is_ready;
}			t_tamp_buff;

typedef struct		s_client
{
  int			client_fd;
  char			*nickname;
  char			*channel;
  t_tamp_buff		buff;
  char			*to_send;
}			t_client;

typedef struct		s_list_client
{
  t_client		client;
  struct s_list_client	*next;
  struct s_list_client	*prev;
}			t_list_client;

typedef struct		s_info
{
  int			fd_socket;
  t_list_client		*list_client;
  int			nb_client;
  t_list_client		*from_client;
  t_list_client		*to_client;
}			t_info;

typedef			int (*func_ptr)(t_info *, t_request *);

typedef struct		s_func_ptr
{
  char			*type_str;
  func_ptr		type_func;
  e_type		type;
}			t_func_ptr;

typedef struct		s_send_name
{
  char			*name;
}			t_send_name;

int			server(int);
int			add_client(t_info *, int);
void			accept_client(t_info *);
void			rm_client(t_info *, int);
void			select_client(t_info *, fd_set *, fd_set *);
int			call_select(int, fd_set *, fd_set *);
int			higher_client(t_info *);
int			server_connect(int);
int			server_nick(t_info *, t_request *);
int			server_list(t_info *, t_request *);
int			server_join(t_info *, t_request *);
int			server_part(t_info *, t_request *);
int			server_users(t_info *, t_request *);
int			server_msg(t_info *, t_request *);
int			server_send(t_info *, t_request *);
int			server_accept(t_info *, t_request *);
int			server_message(t_info *, t_request *);
int			server_quit(t_info *, t_request *);
void			check_clients(t_info *, fd_set *, fd_set *);
int			send_is_ok(t_list_client *, void *, size_t, e_request);
int			nickname_exists(t_info *, char *);
int			write_msg(t_info *, char *, char *, char *);
int			write_info(t_info *, char *, char *, char *);
char			*list_users(t_info *, char *);
void			disconnect_client(t_info *, t_list_client *);
int			check_cmd(t_info *);
t_info			*get_current_info(t_info *);
void			handle_sig_pipe(int);
int			has_closed(int);

#endif
