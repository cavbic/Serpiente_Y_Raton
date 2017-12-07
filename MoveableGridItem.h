#if !defined(MoveableGridItemH)
#define MoveableGridItemH
#include "GridItem.h"
#include "constants.h"
class MoveableGridItem: public GridItem {

public:
	//constructors
	MoveableGridItem(const int x, const int y,const char& symbol);
	MoveableGridItem& operator =(const MoveableGridItem&);

	int get_x() const;
	int get_y() const;
	bool is_at_position(const int x, const int y) const;

	void reset_postion(const int x, const int y);
	void update_position(const int dx, const int dy);
	
private:
	int x_, y_;
};





#endif