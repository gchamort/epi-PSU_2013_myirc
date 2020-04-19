##
## Makefile for Makefile in /home/chauch_a/rendu/PSU_2013_myftp
## 
## Made by CHAUCHET Alan
## Login   <chauch_a@epitech.net>
## 
## Started on  Tue Apr  8 11:57:23 2014 CHAUCHET Alan
## Last update Sun Apr 27 21:48:52 2014 CHAUCHET Alan
##

NAME_1	= serveur

NAME_2	= client

PATH_1	= src/server/

PATH_2	= src/client/

PATH_3	= src/shared_function/

SRC_1	= $(PATH_1)main.c		\
	  $(PATH_1)server.c		\
	  $(PATH_1)server_nick.c	\
	  $(PATH_1)server_list.c	\
	  $(PATH_1)server_join.c	\
	  $(PATH_1)server_part.c	\
	  $(PATH_1)server_users.c	\
	  $(PATH_1)server_msg.c		\
	  $(PATH_1)server_send.c	\
	  $(PATH_1)server_accept.c	\
	  $(PATH_1)server_message.c	\
	  $(PATH_1)server_quit.c	\
	  $(PATH_1)server_connect.c	\
	  $(PATH_1)accept_client.c	\
	  $(PATH_1)handle_sig_pipe.c	\
	  $(PATH_1)add_client.c		\
	  $(PATH_1)rm_client.c		\
	  $(PATH_1)select_client.c	\
	  $(PATH_1)check_clients.c	\
	  $(PATH_1)higher_client.c	\
	  $(PATH_1)send_is_ok.c		\
	  $(PATH_1)write_msg.c		\
	  $(PATH_1)nickname_exists.c	\
	  $(PATH_1)list_users.c		\
	  $(PATH_1)check_cmd.c		\
	  $(PATH_3)call_select.c	\
	  $(PATH_3)send_receve.c	\
	  $(PATH_3)my_str_to_wordtab.c	\

SRC_2	= $(PATH_2)main.c		\
	  $(PATH_2)client.c		\
	  $(PATH_2)client_server.c	\
	  $(PATH_2)client_send.c	\
	  $(PATH_2)client_quit.c	\
	  $(PATH_2)handle_cmd.c		\
	  $(PATH_2)handle_ctrl_c.c	\
	  $(PATH_2)handle_sig_pipe.c	\
	  $(PATH_2)client_connect.c	\
	  $(PATH_2)receve_from_server.c	\
	  $(PATH_3)call_select.c	\
	  $(PATH_3)send_receve.c	\
	  $(PATH_3)my_str_to_wordtab.c	\

OBJ_1	= $(SRC_1:.c=.o)

OBJ_2	= $(SRC_2:.c=.o)

PATH_I	= inc/

CFLAGS	= -W -Wall -Werror -I$(PATH_I)

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_1)
	gcc -o $(NAME_1) $(OBJ_1)

$(NAME_2): $(OBJ_2)
	gcc -o $(NAME_2) $(OBJ_2)

clean:
	rm -rf $(OBJ_1) $(OBJ_2)

fclean: clean
	rm -rf $(NAME_1) $(NAME_2)

re: fclean all
