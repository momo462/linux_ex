.PHONY:all
all:client server 

server:comm.c server.c
	gcc -o $@ $^

client:comm.c client.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f client server
