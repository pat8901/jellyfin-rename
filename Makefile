BUILD_DIR = build
CPPC = g++

CFLAGS = -Wextra -Wall -g -I"/usr/include" -I"./include"

LDLIBS = -L"/usr/lib/x86_64-linux-gnu/" -lm

SRCS = src/main.cpp src/search.cpp src/rename.cpp

OBJS = $(SRCS:.c=.o)

EXE = $(BUILD_DIR)/jellyfin-rename

all: $(EXE)

# Rule to build the target executable
$(EXE): $(OBJS)
	$(CPPC) $(CFLAGS) -o $@ $^ $(LDLIBS)

# Rule to build object files
%.o: %.c
	$(CPPC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*