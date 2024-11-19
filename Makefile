TARGET = san_winapi_gui.dll
BUILDFOLDER = build
STATICFOLDER = static
CC =x86_64-w64-mingw32-g++

STATICLIBNAME = libsan_winapi_gui.a
LIPSPECIFIC = -DSAN_WINAPI_GUI_EXPORTS
CFLAGS = -std=c++17 \
         -O0 -D_FORTIFY_SOURCE=2 -fstack-protector \
		 -Wall -Wextra -Werror -Wshadow \
		 $(LIPSPECIFIC)
LDFLAGS = -Wl,--out-implib,$(STATICLIBNAME) -shared 
# $(AVOIDMINGWDYNAMIC) $(WINAPILIBS) $(WINAPIRELATED)
MMAIN = san_winapi_gui.cpp san_winapi_gui.hpp 

MODULES = $(MMAIN)

CPP = $(filter %.cpp,$(MODULES))
HEADERS = $(filter %.hpp %.h,$(MODULES))
OBJECTS = $(patsubst %.cpp,%.o,$(CPP))


.PHONY: all clean

all: $(TARGET) static_move

$(TARGET): $(OBJECTS) | $(BUILDFOLDER)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(BUILDFOLDER)/$(TARGET)  

$(OBJECTS): %.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

static_move: $(STATICLIBNAME) | $(STATICFOLDER)
	mv $(STATICLIBNAME) $(STATICFOLDER)
clean:
	rm -f $(OBJECTS)
	rm -f $(BUILDFOLDER)/$(TARGET)
	rm -f  $(STATICFOLDER)/$(STATICLIBNAME)


$(BUILDFOLDER):
	mkdir build

$(STATICFOLDER):
	mkdir static