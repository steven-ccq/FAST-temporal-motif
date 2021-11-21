IPATH = include
SPATH = src

OBJS = main.o global.o edgeLoader.o starAndPairCount.o triangleCount.o convertMartix.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -O3 -Wall

OMPFLAG = false

ifeq ($(OMPFLAG),true)
	CFLAGS += -fopenmp
endif

FAST_temporal_motif : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o FAST_temporal_motif

main.o : $(SPATH)/main.cpp $(IPATH)/global.h $(IPATH)/edgeLoader.h $(IPATH)/starAndPairCount.h $(IPATH)/triangleCount.h
	$(CC) $(CFLAGS) -c $(SPATH)/main.cpp -I $(IPATH)

global.o : $(SPATH)/global.cpp
	$(CC) $(CFLAGS) -c $(SPATH)/global.cpp -I $(IPATH)

edgeLoader.o : $(SPATH)/edgeLoader.cpp $(IPATH)/global.h
	$(CC) $(CFLAGS) -c $(SPATH)/edgeLoader.cpp -I $(IPATH)

starAndPairCount.o : $(SPATH)/starAndPairCount.cpp $(IPATH)/global.h
	$(CC) $(CFLAGS) -c $(SPATH)/starAndPairCount.cpp -I $(IPATH)

triangleCount.o : $(SPATH)/triangleCount.cpp $(IPATH)/global.h
	$(CC) $(CFLAGS) -c $(SPATH)/triangleCount.cpp -I $(IPATH)

convertMartix.o : $(SPATH)/convertMartix.cpp $(IPATH)/global.h
	$(CC) $(CFLAGS) -c $(SPATH)/convertMartix.cpp -I $(IPATH)

clean : 
	rm FAST_temporal_motif $(OBJS)
