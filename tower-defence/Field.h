#pragma once
#include <string>
#include <vector>
#include "Cell.h"
#include "Player.h"
#include "Fraction.h"
#include <iostream>

class FieldClass {

private:
	int rows_, cols_;
	
	std::vector<std::vector<CellClass>> cells_;
	std::vector<PlayerClass> players_;
	std::vector<FractionClass> fractions_;

	static FieldClass* fieldClassInstance;

	FieldClass(int rows, int cols) : rows_(rows), cols_(cols) {
		cells_.resize(rows_);
		for (int i = 0; i < rows_; i++) {
			cells_[i].resize(cols_);
			for (int j = 0; j < cols_; j++) {
				cells_[i][j].generateRandomCellType();
				cells_[i][j].generateRandomPassability();
				cells_[i][j].setBelonging("-");
				cells_[i][j].setInfluence(0);
				cells_[i][j].generateTower();
				cells_[i][j].generateRandomResource();
			}
		}
	};

	FieldClass(const FieldClass& obj) = delete;

public:
	FieldClass& operator = (const FieldClass& obj) = delete;

	static FieldClass* getInstance(int rows, int cols) {

		if (fieldClassInstance == nullptr) {
			fieldClassInstance = new FieldClass(rows, cols);
			return fieldClassInstance;
		}
		else {
			return fieldClassInstance;
		}
	}

	//void generatePlayers() {

	//	int rowsNumber = cells_.size();
	//	int colsNumber = cells_[0].size();
	//	int cellsNumber = rowsNumber * colsNumber;

	//	if (cellsNumber <= 10) {
	//		players_.resize(2);
	//	}
	//	else if (cellsNumber > 10 && cellsNumber <= 20) {
	//		players_.resize(4);
	//	}
	//	else if (cellsNumber > 20 && cellsNumber <= 30) {
	//		players_.resize(6);
	//	}
	//}

	//void generateFractions() {
	//	int playersNumber = players_.size();
	//	if (playersNumber <= 2) {
	//		fractions_.resize(2);
	//	}
	//	else if (playersNumber > 2 && playersNumber <= 8) {
	//		fractions_.resize(4);
	//	}
	//	else if (playersNumber > 8) {
	//		fractions_.resize(7);
	//	}
	//}

	void createPlayers(int number) {
		players_.resize(number);
	}

	void createFructions(int number) {
		fractions_.resize(number);
	}

	FieldClass& generateField(int cellsNumber, int playersNumber, int fractionsNumber, int rows, int cols) {
			FieldClass& newField = *FieldClass::getInstance(rows, cols);
			newField.cells_.resize(rows);
			for (int i = 0; i < rows; i++) {
				newField.cells_[i].resize(cols);
				for (int j = 0; j < cols; j++) {
					newField.cells_[i][j].generateRandomCellType();
					newField.cells_[i][j].generateRandomPassability();
					newField.cells_[i][j].setBelonging("-");
					newField.cells_[i][j].setInfluence(0);
					newField.cells_[i][j].generateTower();
					newField.cells_[i][j].generateRandomResource();
				}
			}
			newField.createPlayers(playersNumber);
			newField.createFructions(fractionsNumber);
			return newField;
	}

	auto findPlayersCell(std::string nick) {
		std::vector<std::pair<int, int>>result;
		for (int i = 0; i < cells_.size(); i++) {
			for (int j = 0; j < cells_[i].size(); j++) {
				if (cells_[i][j].getBelonging() == nick) {
					result.push_back(std::make_pair(i, j));
				}
			}
		}
		return result;
	}

	~FieldClass() {}
};

FieldClass* FieldClass::fieldClassInstance = nullptr;