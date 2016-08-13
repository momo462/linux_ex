.PHONY:all
all:fifo_client fifo_server

fifo_client:fifo_client.c
	gcc -o fifo_client fifo_client.c 
fifo_server:fifo_server.c
	gcc -o fifo_server fifo_server.c  

.PHONY:clean
clean:
	rm -f fifo_client fifo_server fifo


