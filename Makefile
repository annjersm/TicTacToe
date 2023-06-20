EXEC = TicTacToe
CFLAGS = -g -Wall -Werror -Isrc/
CLIB = -lSDL2main -lSDL2


all: $(EXEC)
	@./$(EXEC)
	@echo " "


$(EXEC): main.o application.o init.o event.o brett.o
	@echo "Linking and producing the final application."
	@echo "--------------------------------------------"
	@gcc -o $(EXEC) main.o application.o init.o        \
		event.o brett.o $(CLIB)
	
main.o: src/main.c 
	@echo "Compiling: main.c"
	@gcc $(CFLAGS) -c src/main.c 

application.o: src/application.c
	@echo "Compiling: application.c"
	@gcc $(CFLAGS) -c src/application.c

init.o: src/init.c
	@echo "Compiling: init.c"
	@gcc $(CFLAGS) -c src/init.c

event.o: src/event.c
	@echo "Compiling: event.c"
	@gcc $(CFLAGS) -c src/event.c

brett.o: src/brett.c
	@echo "Compiling: brett.c"
	@gcc $(CFLAGS) -c src/brett.c

clean:
	@echo "Removing everything but the source files."
	@rm *.o $(EXEC)
	@echo " "
