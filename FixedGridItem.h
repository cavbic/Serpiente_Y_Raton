#if !defined(FixedGridItemH)
#define FixedGridItemH
#include "GridItem.h"
#include "constants.h"
class FixedGridItem : public GridItem {

public:
	//constructors
	FixedGridItem(const int& x, const int& y, const char& symbol);
	FixedGridItem& operator =(const FixedGridItem&);

	int get_x() const;
	int get_y() const;
	bool is_at_position(const int& x, const int& y) const;
private:
	int x_, y_;
};
#endif