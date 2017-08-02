
AP_PATH     = ..
OPEN_COMMON = $(AP_PATH)/open_common
SRC         = ./src
ENTRY       = ./entry
BIN         = ./bin

include $(AP_PATH)/cgiBase.mk

TARGET      = test.cgi
INTALL_PATH = /data/wwwroot/fastcgi_demo/cgi-bin/v2.0/

INCLUDE +=

LIBS +=

CFLAGS +=

all = $(BIN)/$(TARGET)

$(all): $(SRC_OBJS) $(ENTRY_OBJS)
	$(CXX) -o $@ $(CFLAGS2) $^ $(LIBS) $(INCLUDE)
   
install:
	cp $(all) $(INTALL_PATH) 
clean:
	rm -f $(SRC_OBJS) $(ENTRY_OBJS) $(all) 


