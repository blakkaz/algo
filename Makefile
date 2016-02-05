SOURCES = bessel.c extrema.c extremum.c linspace.c logspace.c

DOCS = $(SOURCES:.c=.3.md)

CFLAGS = -Wall -O3

SLEXT = a

ifeq ($(shell uname), Darwin)
DLEXT = dylib
else
DLEXT = so
endif

LIB = algo-nt
STATIC = lib$(LIB).$(SLEXT)
SHARED = lib$(LIB).$(DLEXT)

MKDIR = mkdir -p
RMDIR = rm -rf
MV = mv
RONN = ronn --html --style=toc --organization="@ntessore" --manual="algorithms"

.PHONY: all static shared html clean

all:
	@echo "This Makefile does nothing by default."
	@echo "You can make the html documentation using 'make html'."
	@echo "You can make a static library using 'make static'."
	@echo "You can make a shared library using 'make shared'."
	@echo "You can clean up using 'make clean'."

static: $(STATIC)

shared: $(SHARED)

html: $(DOCS:.md=.html)
	@$(MKDIR) html
	@$(MV) $^ html

clean:
	$(RM) $(SOURCES:.c=.static.o) $(STATIC)
	$(RM) $(SOURCES:.c=.shared.o) $(SHARED)
	$(RMDIR) html

$(STATIC): $(SOURCES:.c=.static.o)
	$(AR) $(ARFLAGS) $@ $^

$(SHARED): $(SOURCES:.c=.shared.o)
	$(CC) $(CFLAGS) -shared -o $@ $^

%.static.o: %.c
	$(CC) $(CFLAGS) -static -c -o $@ $<

%.shared.o: %.c
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

%.html: %.md
	@$(RONN) $<
