SOURCES = bessel.c cholesky.c extrema.c extremum.c linspace.c logspace.c

DOCS = $(SOURCES:.c=.3.md)

CFLAGS = -Wall -O3

LIB = ntessore-algo

ifeq ($(shell uname), Darwin)
SLEXT = a
DLEXT = dylib
else
SLEXT = a
DLEXT = so
endif

STATIC = lib$(LIB).$(SLEXT)
SHARED = lib$(LIB).$(DLEXT)

RONN = ronn --html --style=toc --organization="@ntessore" --manual="algorithms"

.PHONY: all static shared docs clean

all:
	@echo "This Makefile does nothing by default."
	@echo "You can make the documentation using 'make docs'."
	@echo "You can make a static library using 'make static'."
	@echo "You can make a shared library using 'make shared'."
	@echo "You can clean up using 'make clean'."

static: $(STATIC)

shared: $(SHARED)

docs: $(DOCS:.md=.html)

clean:
	$(RM) $(SOURCES:.c=.static.o) $(STATIC)
	$(RM) $(SOURCES:.c=.shared.o) $(SHARED)
	$(RM) $(DOCS:.md=.html)

$(STATIC): $(SOURCES:.c=.static.o)
	$(AR) $(ARFLAGS) $@ $^

$(SHARED): $(SOURCES:.c=.shared.o)
	$(CC) $(CFLAGS) -shared -o $@ $^

%.static.o: %.c
	$(CC) $(CFLAGS) -static -c -o $@ $<

%.shared.o: %.c
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

%.3.html: %.3.md
	@$(RONN) $^
