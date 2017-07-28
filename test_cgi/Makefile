
include ../cgiBase.mk

TARGET = test.cgi
INTALL_PATH = /data/wwwroot/fastcgi_demo/cgi-bin/v2.0/

INCLUDE +=

LIBS +=

CFLAGS +=

all = $(BIN)/$(TARGET)

$(all): $(SRC_OBJS) $(ENTRY_OBJS)
	$(CXX) -o $@ $(CFLAGS) $^ $(LIBS) $(INCLUDE)
   
install:
	cp $(all) $(INTALL_PATH) 
clean:
	rm -f $(SRC_OBJS) $(ENTRY_OBJS) $(all) 


