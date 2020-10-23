# “=”:变量替换
# “:=”:常量替换
# “+=”:追加
# %.c：任意的.c文件     
# *.c：所有的.c文件
# $^所有的依赖文件 
# $@所有的目标文件 
# $<所有的依赖文件的第一个文件
TAR=main
OBJ=main.o Array.o
CC:=gcc
RMRF:=rm -rf
$(TAR):$(OBJ)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) -c $^ -o $@
# 类似于定义函数的固定格式	
.PHONY:
clearall:
	$(RMRF) $(OBJ) $(TAR)
clear:
	$(RMRF) $(OBJ)