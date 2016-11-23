all: server client special

server: server.c utils.h
	gcc server.c -o server

client: client.c utils.h
	gcc client.c -o client

special: special.c utils.h
	gcc special.c -o special

clean:
	rm server
	rm client
	rm special
