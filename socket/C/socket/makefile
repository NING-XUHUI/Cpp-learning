TAR = server client
OBJ = server.o client.o
CC := gcc
RMRF := rm -rf

server client:server.o client.o
	$(CC) server.o -o server
	$(CC) client.o -o client


%.o:%.c
	$(CC) -c $^ -o $@

.PHONY:
clean:
	$(RMRF) $(OBJ) 
