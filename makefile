# Nome do executável
TARGET = main

# Compilador e flags de compilação
CC = gcc
CFLAGS = -Wall

# Lista de todos os arquivos .c (assumindo que todos estão na mesma pasta)
SRCS = $(wildcard *.c)

# Arquivos objetos correspondentes
OBJS = $(SRCS:.c=.o)

# Regra principal (gera o executável)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar os arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos .o e o executável
clean:
	rm -f $(OBJS) $(TARGET)

# Regra para compilar e rodar o programa
run: $(TARGET)
	./$(TARGET)
