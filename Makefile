# Makefile

TARGET = bin/Horizon.exe

SFML_INCLUDE = C:/Libraries/sfml/include
SFML_LIB = C:/Libraries/sfml/lib

OBJ_FILES := $(patsubst src/%.cpp,obj/%.o,$(wildcard src/*.cpp))
OBJ_FILES += $(patsubst src/graphics/%.cpp,obj/graphics/%.o,$(wildcard src/graphics/*.cpp))

REBUILDABLES = $(OBJ_FILES) $(LINK_TARGET) obj/*.d obj/graphics/*.d

CXXFLAGS += -MMD
CXXFLAGS += -Wall

$(TARGET): $(OBJ_FILES)
	g++ -g -o $@ $^ -I$(INCLUDE) -I$(SFML_INCLUDE) -L$(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system

obj/%.o: src/%.cpp
	g++ -g -std=c++17 $(CXXFLAGS) -c -o $@ -Iinclude -I$(SFML_INCLUDE) $<

obj/graphics/%.o: src/graphics/%.cpp
	g++ -g -std=c++17 $(CXXFLAGS) -c -o $@ -Iinclude -I$(SFML_INCLUDE) $<

clean :
	rm -f $(REBUILDABLES)

-include $(OBJ_FILES:.o=.d)

