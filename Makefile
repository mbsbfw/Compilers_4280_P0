CFLAGS = -g -Wall -Wshadow
CC = gcc $(CFLAGS)
OBJS = main.c tree.c tree_print.c treeinsert.c
OBJS1 = main.o tree.o tree_print.o treeinsert.o
HOBJS = node.h tree.h  
TARGET = P0

$(TARGET): $(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o $(TARGET)

$(OBJS1): $(OBJS)
	$(CC) $(CFLAGS) -c $(OBJS)

clean:
	rm -f *.o *.preorder *.inorder *.postorder out $(TARGET) 
