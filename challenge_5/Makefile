CXX = g++
TARGET = output
SRC = repeating_key_xor.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	@./$(TARGET)