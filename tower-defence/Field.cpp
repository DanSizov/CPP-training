#include "Field.h"


void main() {
	FieldClass* field = FieldClass::getInstance(10, 10);
	FieldClass& newField = field->generateField(*field, 3, 3, 10, 10);
	newField.changeBelonging(*field, "qwe", 2);
	newField.findPlayersCell("qwe");
	newField.findFractionPlayers(2);

}