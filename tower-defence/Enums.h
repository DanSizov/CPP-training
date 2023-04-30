#pragma once

enum CellType {

	Empty,
	Field,
	Swamp,
	Elevation,
	Mountain
};

enum Existence {

	NotExists,
	Exists
};

enum TowerLevel {

	Zero,
	First,
	Second,
	Third
};

enum ResourceType {

	NoResource,
	Wood,
	Gold,
	Stone
};

enum ResourceProductionRate {

	None,
	Low,
	Midium,
	High
};