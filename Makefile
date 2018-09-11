CC = gcc
ARGS = -rdynamic -w


all:
	@echo Making...
	$(CC) getpng.c $(ARGS) -o getpng
	@echo Done

clean:
	rm -rf getpng

