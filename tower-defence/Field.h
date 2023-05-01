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

	FieldClass(const FieldClass& obj) = delete; // copy constructor deleted

public:
	FieldClass& operator = (const FieldClass& obj) = delete; // "=" operator deleted

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
		for (int i = 0; i < players_.size(); i++) {
			players_[i].setPlayerId(std::to_string(i));
			players_[i].setFractionId(std::to_string(i));
		}
	}

	void createFructions(int number) {
		fractions_.resize(number);
		for (int i = 0; i < fractions_.size(); i++) {
			fractions_[i].setFractionId(i);
		}
	}

	FieldClass& generateField(FieldClass& newField, int playersNumber, int fractionsNumber, int rows, int cols) {
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
	} // random field generation method

	auto findPlayersCell(std::string nick) {
		std::vector<std::pair<int, int>>result;
		for (int i = 0; i < cells_.size(); i++) {
			for (int j = 0; j < cells_[i].size(); j++) {
				if (cells_[i][j].getBelonging() == nick) {
					result.push_back(std::make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < result.size(); i++) {
			std::cout << "( " << result[i].first << " , " << result[i].second << " ) " << std::endl;
		}
		return result;
	} // searching player's cells method

	auto findFractionPlayers(int fractionId) {
		std::vector<std::string>result;
		for (int i = 0; i < players_.size(); i++) {
			if (players_[i].getFractionId() == std::to_string(fractionId)) {
				result.push_back(players_[i].getPlayerId());
			}
		}
		std::cout << "fraction id " << fractionId << " players: " << std::endl;
		for (int i = 0; i < result.size(); i++) {
			std::cout << result[i] << std::endl;
		}
		return result;
	} // searching player belonging to the specific fraction

	void changeBelonging(FieldClass& field, std::string belonging, int number) {
		if (number > field.cells_.size() || number > field.cells_[0].size())
			return;
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				field.cells_[i][j].setBelonging(belonging);
			}
		}
	}

	~FieldClass() {}
};

FieldClass* FieldClass::fieldClassInstance = nullptr;