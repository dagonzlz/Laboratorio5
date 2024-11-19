# Variables
CC = gcc
CFLAGS = -Wall -g
TARGET = main
OBJS = double_list.o main.o

# Regla: Compilar el ejecutable
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilar double_list.c
double_list.o: double_list.c double_list.h
	$(CC) $(CFLAGS) -c double_list.c

# Compilar main.c
main.o: main.c double_list.h
	$(CC) $(CFLAGS) -c main.c

#Regla Para limpiar los archivos generados
clean:
	rm -f $(TARGET) *.o

