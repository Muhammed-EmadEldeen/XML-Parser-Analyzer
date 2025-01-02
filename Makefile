# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -Wextra -O2

# Directories
SRC_DIR = .
XML_ANALYZER_DIR = XmlAnalyzer
XML_PARSER_DIR = XmlParser

# Source files
SRC = \
	$(SRC_DIR)/main.cpp \
	$(XML_PARSER_DIR)/compression.cpp \
	$(XML_PARSER_DIR)/decompress.cpp \
	$(XML_PARSER_DIR)/error_correction.cpp \
	$(XML_PARSER_DIR)/error_detection_s.cpp \
	$(XML_PARSER_DIR)/help_func.cpp \
	$(XML_PARSER_DIR)/json.cpp \
	$(XML_PARSER_DIR)/prettify_minify.cpp \
	$(XML_PARSER_DIR)/readXmlTags.cpp \
	$(XML_PARSER_DIR)/Tags_utilities.cpp \
	$(XML_PARSER_DIR)/XmlParser.cpp \
	$(XML_ANALYZER_DIR)/getMostFollowingUser.cpp \
	$(XML_ANALYZER_DIR)/graph.cpp \
	$(XML_ANALYZER_DIR)/most_followed.cpp \
	$(XML_ANALYZER_DIR)/findMutualFollowers.cpp \
	$(XML_ANALYZER_DIR)/searchPosts.cpp \
	$(XML_ANALYZER_DIR)/searchWord.cpp \
	$(XML_ANALYZER_DIR)/UsersVector.cpp \
	$(XML_ANALYZER_DIR)/suggestFollow.cpp \



	
# Headers
HEADERS = \
	$(XML_ANALYZER_DIR)/User.h \
	$(XML_ANALYZER_DIR)/UsersData.h \
	$(XML_PARSER_DIR)/help_func.h \
	$(XML_PARSER_DIR)/json.h \
	$(XML_PARSER_DIR)/Tags_utilities.h \
	$(XML_PARSER_DIR)/XmlParser.h \
	$(XML_ANALYZER_DIR)/UsersVector.h \
	$(XML_ANALYZER_DIR)/UsersData.h \
	$(XML_ANALYZER_DIR)/User.h \

# Object files
OBJ = $(SRC:.cpp=.o)

# Output executable
TARGET =  xml_editor

# Rules
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
