#pragma once
#include "LinkList.h"

namespace EngineLib 
{
	class Point2D
	{
	public:
		int X, Y;

		Point2D();
		Point2D(int i_x,int i_y);
		Point2D(int i_Int);

		// get
		//int x() const { return X; }
		//int y() const { return Y; }

		// set
		//void x(int i_x) { X = i_x; }
		//void y(int i_y) { Y = i_y; }

		// add operator ( Internal class)
		Point2D operator+(const Point2D & i_other) const;

		Point2D operator+(int Bias) const;

		Point2D operator-(const Point2D & i_other) const;

		Point2D operator-(int Bias) const;

		Point2D operator*(const Point2D & i_other) const;

		Point2D operator*(int Scale) const;

		bool operator==(const Point2D & V) const;
	};


}