# Nome do nosso programa final
TARGET = projeto_escola.exe

# Qual compilador estamos usando
CC = gcc

# O Segredo: Avisa o compilador em quais pastas ele deve procurar os arquivos .h
CFLAGS = -I./model -I./view -I./controller -I./utils

SRCS = escola.c model/*.c view/*.c controller/*.c utils/*.c

# A regra principal (o que acontece quando você digita 'make')
all:
	$(CC) $(SRCS) $(CFLAGS) -o $(TARGET)

# Regra para limpar o executável antigo
clean:
	del $(TARGET)