
CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -IXmlParser -IXmlAnalyzer

TARGET = xml_editor

SRC = main.cpp \
	  temp.cpp \
      XmlParser/compression.cpp \
      XmlParser/error_correction.cpp \
      XmlParser/help_func.cpp \
      XmlParser/json.cpp \
      XmlParser/prettify_minify.cpp \
      XmlParser/Tags_utilities_s.cpp

OBJS = $(SRC:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)


# Compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets (non-file targets)
.PHONY: clean
