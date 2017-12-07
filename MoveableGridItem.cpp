#include "MoveableGridItem.h"


MoveableGridItem::MoveableGridItem(const int& x, const int& y, const char& symbol):x_(x),y_(y),GridItem(symbol)
{}

MoveableGridItem & MoveableGridItem::operator=(const MoveableGridItem& mgi)
{
	x_=  mgi.get_x();
	y_ = mgi.get_y();
	return *this;
}
int MoveableGridItem::get_x() const
{
	return x_;
}
int MoveableGridItem::get_y() const
{
	return y_;
}

bool MoveableGridItem::is_at_position(const int& x, const int& y) const {
	return (x_ == x) && (y_ == y);
}

void MoveableGridItem::reset_postion(const int & x, const int & y)
{
	x_ = x;
	y_ = y;
}

void MoveableGridItem::update_position(const int& dx, const int& dy) {
	x_ += dx;
	y_ += dy;
}