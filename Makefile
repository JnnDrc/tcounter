CC := gcc
CFLAGS := -Wall -Wextra
OBJ := cnt.o input.o
TGT := cnt

$(TGT): $(OBJ)
	$(CC) $^ -o $@

$(OBJ): %.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)
