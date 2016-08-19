//ser=$(server)
//cli=$(client)
//cc=$(gcc)

.PHONY:all
all:server client
//all:$(ser) $(cli)

server:server.c comm.c
	gcc -o $@ $^
client:client.c comm.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f server client
