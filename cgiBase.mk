
OPEN_COMMON = ../open_common
SRC         = ./src
ENTRY       = ./entry
BIN         = ./bin

INCLUDE = -I$(SRC) -I$(ENTRY) -I../base/ -I../open_common/


OPEN_COMMON_CPP = $(wildcard $(OPEN_COMMON)/*.cpp) $(wildcard $(OPEN_COMMON)/*.c)
SRC_CPP = $(wildcard $(SRC)/*.cpp) $(wildcard $(SRC)/*.c)
ENTRY_CPP = $(wildcard $(ENTRY)/*.cpp) $(wildcard $(ENTRY)/*.c)

SRC_OBJS = $(patsubst %.cpp, $(SRC)/%.o, $(notdir $(SRC_CPP)))  $(patsubst %.cpp, $(SRC)/%.o, $(notdir $(OPEN_COMMON_CPP)))
ENTRY_OBJS = $(patsubst %.cpp, $(ENTRY)/%.o, $(notdir $(ENTRY_CPP)))

LIBS = -lpthread -lcurl -lcrypto -lfcgi \
	   -L../base/ -lbase -L./entry/

CFLAGS = -Wall -g -O0
CFLAGS += -Wall -DTIXML_USE_STL
CFLAGS += -fpic
CXX = g++
CC = g++

CFLAGS2 = -O3 -DNDEBUG -Wall

# 自动计算文件的依赖关系
$(SRC)/%.o: $(OPEN_COMMON)/%.cpp
	$(CXX) $(CFLAGS2) $(INCLUDE) -c $< -o $@

$(SRC)/%.o: $(SRC)/%.cpp
	$(CXX) $(CFLAGS2) $(INCLUDE) -c $< -o $@

$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS2) $(INCLUDE) -c $< -o $@

$(ENTRY)/%.o: $(ENTRY)/%.cpp
	$(CXX) $(CFLAGS2) $(INCLUDE) -c $< -o $@

$(ENTRY)/%.o: $(ENTRY)/%.c
	$(CC) $(CFLAGS2) $(INCLUDE) -c $< -o $@


