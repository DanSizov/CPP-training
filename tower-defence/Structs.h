#pragma once
#include "Enums.h"

struct Tower {

	Existence towerExistence;
	TowerLevel towerLevel;
};

struct Resource {

	Existence resourceExistence;
	ResourceType resourceType;
	ResourceProductionRate resourceProductionRate;
};