# Tên file thực thi
TARGET = app

# Compiler và cờ biên dịch
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinc/ -Iinc/obj -Iinc/data

# Thư mục chứa mã nguồn
SRC_DIR = src

# Tìm tất cả các file .c trong src/*/*.c, src/*.c và main.c
SRC = $(wildcard $(SRC_DIR)/*/*.c) \
      $(wildcard $(SRC_DIR)/*.c) \
      main.c

OBJ = $(SRC:.c=.o) #build thành file object
all: $(TARGET)

# Link các object file thành executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile từng file .c thành .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Xóa file .o và file thực thi
clean:
	rm -f $(OBJ) $(TARGET)

# Build và chạy
run: all
	./$(TARGET)