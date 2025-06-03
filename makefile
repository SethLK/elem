# Compiler
CC = cc
# Flags
CFLAGS = -Wall -Wextra -g -I./header
# Directories
SRCDIR = ./src
OBJDIR = ./obj
# Source and Object Files
SRC = ./main.c $(SRCDIR)/handleToken.c
OBJS = $(OBJDIR)/main.o $(OBJDIR)/handleToken.o
# Output Binary
TARGET = main

# Header files for dependencies
HEADER_FILES = ./header/tokenType.h ./header/tokenList.h

# Target Rules
$(TARGET): $(OBJS)
	$(CC) $^ -o $@

# Rule to compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/main.o: ./main.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure the obj directory exists
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean Rule
.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Dependencies (each .o depends on the source file and headers)
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@
