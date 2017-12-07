#if !defined(GridItemH)
#define GridItemH

#include "constants.h"

class GridItem {
public:
	//constructors
	GridItem(const char& symbol);
	const char get_Symbol();

private:
	const char symbol_;
};

#endif