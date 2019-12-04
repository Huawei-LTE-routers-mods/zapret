CC = arm-linux-androideabi-gcc
CFLAGS += -s -O2 -std=c99
LIBS = -lz
SRC_FILES = *.c

all: tpws

tpws: $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS)

clean:
	rm -f tpws *.o
