CFLAGS 		:= -Wall -std=c++0x
DIR 		:= vmPrism
OBJ_DIR 	:= $(DIR)/obj
EXECUTABLE	:= $(DIR)/vmPrism
CPP_FILES 	:= $(wildcard $(DIR)/*.cpp)
OBJ_FILES 	:= $(addprefix $(OBJ_DIR)/,$(notdir $(CPP_FILES:.cpp=.obj)))

CPP_FILES_WITHOUT_RUN 	:= $(wildcard $(DIR)/*Policy.cpp)
GOOGLE_TEST_LIB_PATH:= /usr/lib/x86_64-linux-gnu
GOOGLE_TEST_INCLUDE := /usr/local/include
TESTS_CFLAGS 		:= $(CFLAGS) -I $(GOOGLE_TEST_INCLUDE) -g
TESTS_LD_FLAGS      := $(GOOGLE_TEST_LIB_PATH)/libgtest.a $(GOOGLE_TEST_LIB_PATH)/libgtest_main.a -l pthread -lgtest -lgtest_main -fprofile-arcs -ftest-coverage
TESTS_DIR 		    := tests
TESTS_OBJ_DIR 	    := $(TESTS_DIR)/obj
TESTS_EXECUTABLE	:= $(TESTS_DIR)/testMain
TESTS_CPP_FILES 	:= $(wildcard $(TESTS_DIR)/*.cpp)
TESTS_OBJ_FILES 	:= $(addprefix $(TESTS_OBJ_DIR)/,$(notdir $(TESTS_CPP_FILES:.cpp=.obj))) $(addprefix $(OBJ_DIR)/,$(notdir $(CPP_FILES_WITHOUT_RUN:.cpp=.obj)))

all: directories $(EXECUTABLE)

directories: $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(EXECUTABLE): $(OBJ_FILES)
	g++ $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.obj: $(DIR)/%.cpp
	g++ $(CFLAGS) -c -o $@ $<

clean:
	rm -r -f $(OBJ_DIR) $(EXECUTABLE)
	rm -r -f $(TESTS_OBJ_DIR) $(TESTS_EXECUTABLE)

test: directories_tests $(TESTS_EXECUTABLE)

directories_tests: $(TESTS_OBJ_DIR)

$(TESTS_OBJ_DIR):
	mkdir $(TESTS_OBJ_DIR)

$(TESTS_EXECUTABLE): $(TESTS_OBJ_FILES)
	g++ $(TESTS_CFLAGS) $(TESTS_LD_FLAGS) -o $@ $^

$(TESTS_OBJ_DIR)/%.obj: $(TESTS_DIR)/%.cpp
	g++ $(TESTS_CFLAGS) -c -o $@ $<