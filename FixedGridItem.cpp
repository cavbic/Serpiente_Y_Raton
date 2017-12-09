#include "FixedGridItem.h"
FixedGridItem::FixedGridItem(const int x, const int y, const char& symbol) :x_(x), y_(y), GridItem(symbol)
{}

FixedGridItem & FixedGridItem::operator=(const FixedGridItem& fgi)
{
	x_ = fgi.get_x();
	y_ = fgi.get_y();
	return *this;
}
int FixedGridItem::get_x() const
{
	return x_;
}
int FixedGridItem::get_y() const
{
	return y_;
}
bool FixedGridItem::is_at_position(const int x, const int y) const {
	return (x_ == x) && (y_ == y);
}
