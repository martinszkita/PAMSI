OBJ_DIR := ./obj
SRC_DIR := ./src
INC_DIR := ./inc

$(OBJ_DIR)/kik.o: $(SRC_DIR)/kik.cpp $(INC_DIR)/kik.hh $(INC_DIR)/size.hh
	g++ -c $(SRC_DIR)/kik.cpp -I$(INC_DIR) -o $(OBJ_DIR)/kik.o

$(OBJ_DIR)/board.o: $(SRC_DIR)/board.cpp $(INC_DIR)/board.hh $(INC_DIR)/size.hh
	g++ -c $(SRC_DIR)/board.cpp -I$(INC_DIR) -o $(OBJ_DIR)/board.o

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/size.hh
	g++ -c $(SRC_DIR)/main.cpp -I$(INC_DIR) -o $(OBJ_DIR)/main.o

clean:
	rm $(OBJ_DIR)/*.o

kik: $(OBJ_DIR)/main.o $(OBJ_DIR)/board.o $(OBJ_DIR)/kik.o
	g++ $(OBJ_DIR)/main.o $(OBJ_DIR)/board.o $(OBJ_DIR)/kik.o -o kik

