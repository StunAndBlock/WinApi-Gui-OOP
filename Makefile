DYNAMICTARGET = sab_winui.dll
STATICTARGET = libsab_winui.a
IMPORTTARGET = libsab_winui.dll.a
BUILD_DIR = build
BUILD_DYNAMIC_DIR = $(BUILD_DIR)/dynamic
BUILD_STATIC_DIR = $(BUILD_DIR)/static

CC_DYNAMIC = x86_64-w64-mingw32-g++
CC_STATIC = ar rcs
INCLUDE_DIR = include
INCLUDE_PATH = $(INCLUDE_DIR)/
SRC_PATH = src/


LIBEXPORT = -DSAB_WINUI_LIB_EXPORT
CINCLUDE = -I$(INCLUDE_DIR)
AVOIDMINGWDYNAMIC = -static
CFLAGS = -std=c++17 \
         -O0 -D_FORTIFY_SOURCE=2 -fstack-protector \
		 -Wall -Wextra -Werror -Wshadow \
		 $(LIBEXPORT) \
		 $(CINCLUDE)
		
LDFLAGS = -shared $(AVOIDMINGWDYNAMIC) -Wl,--out-implib,$(BUILD_DYNAMIC_DIR)/$(IMPORTTARGET)
#LDFLAGS_STATIC = -Wl,--out-implib,$(STATICTARGET)
# $(AVOIDMINGWDYNAMIC) $(WINAPILIBS) $(WINAPIRELATED)


MMAIN = ui/WindowBase.cpp sab/ui/WindowBase.hpp 
 
MODULES = $(MMAIN)

CPP = $(addprefix $(SRC_PATH),$(filter %.cpp,$(MODULES)))
HEADERS = $(addprefix $(INCLUDE_PATH),$(filter %.hpp %.h,$(MODULES)))
OBJECTS = $(patsubst %.cpp,%.o,$(CPP))


.PHONY: all clean static dynamic

all: dynamic static

dynamic: $(OBJECTS) | $(BUILD_DYNAMIC_DIR)
	$(CC_DYNAMIC) $(OBJECTS) $(LDFLAGS) -o $(BUILD_DYNAMIC_DIR)/$(DYNAMICTARGET)  

static: $(OBJECTS) | $(BUILD_STATIC_DIR)
	$(CC_STATIC) $(BUILD_STATIC_DIR)/$(STATICTARGET) $(OBJECTS) 

$(OBJECTS): %.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -rf $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p  $(BUILD_DIR)

$(BUILD_DYNAMIC_DIR): $(BUILD_DIR)
	mkdir -p $(BUILD_DYNAMIC_DIR)

$(BUILD_STATIC_DIR): $(BUILD_DIR)
	mkdir -p  $(BUILD_STATIC_DIR)