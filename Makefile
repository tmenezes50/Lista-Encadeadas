CC = gcc
CFLAGS = -c -fdiagnostics-color=always -g

INCLUDE = ./src/include
SOURCE = ./src
OUT = ./obj

defaults: out colection.o main.o linkar

out: 
	@rm -r $(OUT)/
	mkdir -p $(OUT)/

main.o: ./src/main.c 
	$(CC) -o $(OUT)/main.o -I $(INCLUDE) $(CFLAGS) $(SOURCE)/main.c

colection.o: ./src/colection.c 
	$(CC) -o $(OUT)/colection.o -I $(INCLUDE) $(CFLAGS) $(SOURCE)/colection.c

linkar: $(OUT)
	$(CC) -o ./main $(OUT)/*