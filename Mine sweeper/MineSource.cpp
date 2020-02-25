#include "Mine.h"

CMine::CMine() {
	count = 4;
	icon = '@';
};
CMine::CMine(unsigned count, char icon) {
	if (count != 0)
	{
		this->count = count;
	}
	else
	{
		this->count = 1;
	}
	this->icon = icon;
};

CMine::~CMine() {};


int CMine::setCount(unsigned count) {
	if (count != 0)
	{
		this->count = count;
	}
	else
	{
		this->count = 1;
	}
	return 0;
};
int CMine::setIcon(char icon) {
	this->icon = icon;
	return 0;
};

unsigned CMine::getCount() const {
	return count;
};
char CMine::getIcon() const {
	return icon;
};