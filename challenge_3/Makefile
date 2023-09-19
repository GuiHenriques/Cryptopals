CXX = g++
TARGET = output
SRC = single_byte_xor.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	@./$(TARGET)