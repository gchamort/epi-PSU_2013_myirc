//
// shared_info.h for shared_info.h in /home/chauch_a/rendu/PSU_2013_myftp
//
// Made by CHAUCHET Alan
// Login   <chauch_a@epitech.net>
//
// Started on  Fri Apr 11 12:30:28 2014 CHAUCHET Alan
// Last update Sun Apr 20 15:16:32 2014 CHAUCHET Alan
//

#ifndef			SHARED_INFO__H_
# define		SHARED_INFO__H_

# include		<sys/types.h>
# include		<sys/socket.h>
# include		<sys/stat.h>
# include		<netdb.h>
# include		<arpa/inet.h>
# include		<netinet/in.h>
# include		<string.h>
# include		<stdlib.h>
# include		<unistd.h>
# include		<stdio.h>
# include		<signal.h>
# include		<dirent.h>
# include		<errno.h>
# include		<fcntl.h>

# define		ERROR_RET	"ERROR:"
# define		FILE_RET	"FILE:"
# define		MSG_RET		"MESSAGE:"
# define		INFO_RET	"INFO:"
# define		SUCCESS_RET	"SUCCESS:"

# define		SERVER_CMD	"/server"
# define		NICK_CMD	"/nick"
# define		LIST_CMD	"/list"
# define		JOIN_CMD	"/join"
# define		PART_CMD	"/part"
# define		USERS_CMD	"/users"
# define		MSG_CMD		"/msg"
# define		SEND_CMD	"/send_file"
# define		ACCEPT_CMD	"/accept_file"
# define		QUIT_CMD	"/quit"

# define		BAD_READ	"ERROR: read failed.\n"
# define		BAD_WRITE	"ERROR: write failed.\n"
# define		MALLOC_FAILED	"ERROR: malloc failed.\n"
# define		BAD_NICK	"ERROR: /nick needs one parameter with a length inferior to 9.\n"
# define		BAD_JOIN	"ERROR: /join needs one parameter.\n"
# define		BAD_PART	"ERROR: /part needs one parameter.\n"
# define		BAD_MSG		"ERROR: /msg needs two parameters.\n"
# define		BAD_USERS	"ERROR: /users needs no parameter.\n"

# define		LENGTH_MAX	512
# define		PROTOCOL	"TCP"
# define		DEFAULT_PORT	6667
# define		FILESIZE(x)	lseek(x, 0, SEEK_END)
# define                OPENFLAG	(O_CREAT | O_WRONLY | O_NOFOLLOW)
# define                OPENRIGHT       (S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH)
# define		SIZE_PACK	4096
# define		SIZE_SEND(x)	(((x) > SIZE_PACK) ? SIZE_PACK : (x))

typedef enum		e_bool
  {
    FALSE = 0,
    TRUE = 1
  }			e_bool;

typedef enum		e_request
  {
    IS_NOK = 0,
    IS_OK = 1,
    IS_MSG = 2,
    IS_FILE = 3,
    IS_INFO = 4
  }			e_request;

typedef enum		e_type
  {
    NICK = 0,
    LIST = 1,
    JOIN = 2,
    PART = 3,
    USERS = 4,
    MSG = 5,
    SEND = 6,
    ACCEPT = 7,
    QUIT = 8,
    MESSAGE = 9
  }			e_type;

typedef struct		s_request
{
  e_type		type;
  char			*param1;
  char			*param2;
  size_t		size_file;
}			t_request;

typedef struct		s_server_ret
{
  e_request		is_ok;
  size_t		size_answer;
  size_t		size_package;
}			t_server_ret;

int			send_data(void *, size_t, int);
void			*receve_data(size_t, int);
int			call_select(int, fd_set *, fd_set *);
char			**my_str_to_wordtab(char *);

#endif
