
INCLUDE = -I./ -I../minixml/source

SRCS_CPP = $(wildcard *.cpp)
SRCS_C = $(wildcard *.c)
OBJS = $(patsubst %.cpp, %.o, $(SRCS_CPP)) $(patsubst %.c, %.o, $(SRCS_C))

CFLAGS = -O2 -DNDEBUG -Wall
CXX = g++
CC = g++

# 自动计算文件的依赖关系
%.o: %.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c $<

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

all = libbase.a
libbase.a: $(OBJS)
	ar -crv $@ $^
	
clean:
	rm -f $(OBJS) $(all) 
