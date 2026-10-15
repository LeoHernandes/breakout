# Project configuration ========================================

PROJECT = breakout

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -D_POSIX_C_SOURCE=199309L -Iinclude
LDLIBS = -lncurses -lpanel

CDIR = src
ODIR = obj


# Source files ================================================

SRC = $(wildcard $(CDIR)/*.c)
OBJ = $(SRC:$(CDIR)/%.c=$(ODIR)/%.o)


# Build ========================================================

.PHONY: all clean

all: $(PROJECT)

$(PROJECT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

$(ODIR)/%.o: $(CDIR)/%.c
	@mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@


# Automatically generated header dependencies =================

DEPS = $(OBJ:.o=.d)

-include $(DEPS)


# Clean ========================================================

clean:
	rm -rf $(ODIR) $(PROJECT)