
INCLUDE = -I$(SRC) -I$(ENTRY) -I$(AP_PATH)/base/ -I$(AP_PATH)/open_common/ \
		-I$(AP_PATH)/minixml/source

LIBS = -lpthread -lcurl -lcrypto -lfcgi \
	   -L$(AP_PATH)/base/ -lbase -L./entry/ \
	   $(AP_PATH)/minixml/.libs/libminixml.a


OPEN_COMMON_CPP = $(wildcard $(OPEN_COMMON)/*.cpp) $(wildcard $(OPEN_COMMON)/*.c)
SRC_CPP = $(wildcard $(SRC)/*.cpp) $(wildcard $(SRC)/*.c)
ENTRY_CPP = $(wildcard $(ENTRY)/*.cpp) $(wildcard $(ENTRY)/*.c)

SRC_OBJS = $(patsubst %.cpp, $(SRC)/%.o, $(notdir $(SRC_CPP)))  $(patsubst %.cpp, $(SRC)/%.o, $(notdir $(OPEN_COMMON_CPP)))
ENTRY_OBJS = $(patsubst %.cpp, $(ENTRY)/%.o, $(notdir $(ENTRY_CPP)))


CFLAGS = -Wall -g -O2
CFLAGS += -fpic
CFLAGS2 = $(CFLAGS) -DTIXML_USE_STL
CXX = g++
CC = g++


# 自动计算文件的依赖关系
$(SRC)/%.o: $(OPEN_COMMON)/%.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(SRC)/%.o: $(SRC)/%.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(ENTRY)/%.o: $(ENTRY)/%.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(ENTRY)/%.o: $(ENTRY)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


