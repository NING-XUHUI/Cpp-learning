TAR = test
OBJ = Circle.o Cube.o main.o
CC := g++
RMRF := rm -rf

# $^ 所有以来文件， $@所有目标文件
$(TAR):$(OBJ)
	$(CC) $^ -o $@

# %.o任意的.o文件，*.o所有的.o文件
%.o:%.c
	$(CC) -c %.c  -o %.o

.PHONY:
clean:
	$(RMRF) $(OBJ) 
cleanall:
	$(RMRF) $(OBJ) $(TAR)
