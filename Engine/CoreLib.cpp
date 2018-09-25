#include "CoreLib.h"
using namespace EngineLib;

Point2D::Point2D()
{

}

Point2D::Point2D(int i_x, int i_y)
{
	X = i_x;
	Y = i_y;
}

Point2D::Point2D(int i_Int) : X(i_Int), Y(i_Int)
{
}

Point2D Point2D::operator+(const Point2D& i_other) const
{
	return Point2D(X + i_other.X, Y + i_other.Y);
}

Point2D Point2D::operator+(int Bias) const
{
	return Point2D(X + Bias, Y + Bias);
}

Point2D EngineLib::Point2D::operator-(const Point2D& i_other) const
{
	return Point2D(X - i_other.X, Y - i_other.Y);
}

Point2D EngineLib::Point2D::operator-(int Bias) const
{
	return Point2D(X - Bias, Y - Bias);
}

Point2D EngineLib::Point2D::operator*(const Point2D & i_other) const
{
	return Point2D(X * i_other.X, Y * i_other.Y);
}

Point2D EngineLib::Point2D::operator*(int Scale) const
{
	return Point2D(X * Scale,Y*Scale);
}

bool EngineLib::Point2D::operator==(const Point2D& V) const
{
	return X == V.X && Y == V.Y;
}


