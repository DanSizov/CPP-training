#pragma once
#include <string>

class FractionClass {

private:
	std::string name_;
	int fractionId_;

public:

	FractionClass() : name_("-"), fractionId_(0) {}; // default constructor

	FractionClass(FractionClass&& fraction) noexcept {

		this->name_ = fraction.name_;
		this->fractionId_ = fraction.fractionId_;

		fraction.name_ = "-";
		fraction.fractionId_ = 0;
	}; // move constructor

	FractionClass(const FractionClass& copyFraction) {

		this->name_ = copyFraction.name_;
		this->fractionId_ = copyFraction.fractionId_;
	}; // copy constructor

	void setFractionName(std::string name) {
		this->name_ = name;
	}

	std::string getFractionName() {
		return this->name_;
	}

	void setFractionId(int id) {
		this->fractionId_ = id;
	}

	int getFractionId() {
		return this->fractionId_;
	}
};