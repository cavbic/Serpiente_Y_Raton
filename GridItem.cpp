#include "GridItem.h"


GridItem::GridItem(const char& symbol):symbol_(symbol)
{}

const char GridItem::get_Symbol() {
	return symbol_;
}

