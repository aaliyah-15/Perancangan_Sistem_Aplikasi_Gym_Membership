TARGET = main 
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	g++ -o $(TARGET) $(SRC)

run:
	@g++ -o $(TARGET) $(SRC)
	@./$(TARGET)

.PHONY: all run