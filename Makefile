all: mksawk

CFLAGS = -O
OBJS = awk0.o awk1.o awk2.o awk3.o awk4.o y.tab.o wsprintf.o

$(OBJS): awk.h portme.h y.tab.h

y.tab.o: y.tab.c
	$(CC) $(CFLAGS) -c $<

y.tab.c y.tab.h: awk.y
	$(YACC) -d $<

mksawk: $(OBJS)
	$(CC) $(OBJS) -lm -o $@

clean:
	$(RM) $(OBJS) y.tab.[ch] mksawk
