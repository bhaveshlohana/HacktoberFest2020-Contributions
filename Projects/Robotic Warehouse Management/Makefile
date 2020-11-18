.phony: all leak-check clean

APP = WearhouseManager
TEST = Test

HEADERS = $(wildcard *.h)
SRC = $(foreach src, $(wildcard *c), $(patsubst test%,,$(src)))
TEST_SRC = $(foreach src, $(wildcard *c), $(patsubst app%,,$(src)))
# OBJ = $(patsubst %.c,%.o,$(SRC))

CC = gcc
CFLAGS = -O0 -std=c9x -g -Wall 
LIBS = 

all: $(APP) $(TEST)

$(APP): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) -D_POSIX_C_SOURCE=200809L

$(TEST): $(TEST_SRC) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) -D_POSIX_C_SOURCE=200809L

leak-check:
	@echo
	@echo "**********************************************************"
	@echo "USAGE: make leak-check ARGS=\"wearhouse parkinglot\""
	@echo "**********************************************************"
	@echo
	valgrind --leak-check=full --track-origins=yes -q --log-file=leak-check.log ./$(APP) $(ARGS)


clean:
	rm -f *.o *.d $(APP) $(TEST)
