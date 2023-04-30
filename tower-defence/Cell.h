#pragma once
#include <string>
#include "Enums.h"
#include "Structs.h"

class CellClass {

private:

	CellType type_;
	double passability_;
	std::string belonging_;
	double influence_;
	Tower tower_;
	Resource resource_;


public:
	CellClass() : type_(Field), passability_(1.0), belonging_("-"), influence_(0.0), tower_(), resource_() {}; // default constructor

	CellClass(CellClass&& moveField) noexcept {

		this->type_ = moveField.type_;
		this->passability_ = moveField.passability_;
		this->belonging_ = moveField.belonging_;
		this->influence_ = moveField.influence_;
		this->tower_ = moveField.tower_;
		this->resource_ = moveField.resource_;

		moveField.type_ = Empty;
		moveField.passability_ = 0;
		moveField.belonging_ = "-";
		moveField.influence_ = 0;
		moveField.tower_.towerExistence = NotExists;
		moveField.tower_.towerLevel = Zero;
		moveField.resource_.resourceExistence = NotExists;
		moveField.resource_.resourceProductionRate = None;
		moveField.resource_.resourceType = NoResource;
	}; // move constructor

	CellClass(const CellClass& copyFiled) {

		type_ = copyFiled.type_;
		passability_ = copyFiled.passability_;
		influence_ = copyFiled.influence_;
		tower_ = copyFiled.tower_;
		resource_ = copyFiled.resource_;
	}; // copy constructor

	CellType getCellType() {
		return this->type_;
	}

	double getPassability() {
		return this->passability_;
	}

	void setBelonging(std::string belonging) {
		this->belonging_ = belonging;
	}

	std::string getBelonging() const {
		return this->belonging_;
	}

	void setInfluence(double influence) {
		this->influence_ = influence;
	}

	double getInfluence() {
		return this->influence_;
	}

	void setTower(Tower tower) {
		this->tower_.towerExistence = tower.towerExistence;
		this->tower_.towerLevel = tower.towerLevel;
	}

	Tower getTower() {
		return this->tower_;
	}

	void setResource(Resource resource) {
		this->resource_.resourceExistence = resource.resourceExistence;
		this->resource_.resourceProductionRate = resource.resourceProductionRate;
		this->resource_.resourceType = resource.resourceType;
	}

	Resource getResource() {
		return this->resource_;
	}

	void generateRandomCellType() {
		int randomNumber = rand() % 4 + 1;
		switch (randomNumber)
		{
		case 1:
			this->type_ = Field;
			break;
		case 2:
			this->type_ = Swamp;
			break;
		case 3:
			this->type_ = Elevation;
			break;
		case 4:
			this->type_ = Mountain;
			break;
		default:
			this->type_ = Field;
			break;
		}
	}

	double generateRandomPassability() {
		int randomNumber = rand() % 1000;
		this->passability_ = static_cast<double>(randomNumber) / 100;
		return this->passability_;
	}

	void generateTower() {
		this->tower_.towerExistence = NotExists;
		this->tower_.towerLevel = Zero;
	}

	void generateRandomResource() {
		int randomNumberExist = rand() % 2;
		switch (randomNumberExist)
		{
		case 0:
			this->resource_.resourceExistence = NotExists;
			break;
		case 1:
			this->resource_.resourceExistence = Exists;
			break;
		default:
			this->resource_.resourceExistence = NotExists;
			break;
		}

		int randomNumberResType = rand() % 4;
		switch (randomNumberResType)
		{
		case 0:
			this->resource_.resourceType = NoResource;
			break;
		case 1:
			this->resource_.resourceType = Wood;
			break;
		case 2:
			this->resource_.resourceType = Gold;
			break;
		case 3:
			this->resource_.resourceType = Stone;
			break;
		default:
			this->resource_.resourceType = NoResource;
			break;
		}

		this->resource_.resourceProductionRate = None;
	}
};