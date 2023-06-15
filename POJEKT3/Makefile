OBJ_DIR := /home/marcin/Desktop/PAMSI/PROJEKT\3/obj
SRC_DIR := /home/marcin/Desktop/PAMSI/PROJEKT\3/src
INC_DIR := /home/marcin/Desktop/PAMSI/PROJEKT\3/inc

kik.o: $(SRC_DIR)/kik.cpp $(INC_DIR)/kik.hh
	g++ -c $(SRC_DIR)/kik.cpp -o $(OBJ_DIR)/kik.o

board.o: $(SRC_DIR)/board.cpp $(INC_DIR)/board.hh
	g++ -c $(SRC_DIR)/board.cpp -o $(OBJ_DIR)/board.o

main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/main.hh
	g++ -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

clean:
	rm $(OBJ_DIR)/*.o

output: $(OBJ_DIR)/main.o $(OBJ_DIR)/board.o $(OBJ_DIR)/kik.o
	g++ -o output $(OBJ_DIR)/main.o $(OBJ_DIR)/board.o $(OBJ_DIR)/kik.o -g