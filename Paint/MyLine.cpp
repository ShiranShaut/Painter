#include "StdAfx.h"
#include "MyLine.h"

IMPLEMENT_SERIAL(MyLine, MyShape, 1)

MyLine::MyLine(void) {}
MyLine::~MyLine(void) {}

void MyLine::innerDraw(CDC *dc)
{
	dc->MoveTo(start.x, start.y);
	dc->LineTo(end.x, end.y);
}

bool MyLine::InShape(CPoint p)
{
	int x = start.x - end.x;
	int y = start.y - end.y;
	int minX = start.x < end.x ? start.x : end.x;
	int maxX = start.x > end.x ? start.x : end.x;
	int minY = start.y < end.y ? start.y : end.y;
	int maxY = start.y > end.y ? start.y : end.y;

	double m = (double)y/(double)x;
	if ((p.y-start.y - m*(p.x-start.x))-7 && (p.y-start.y - m*(p.x-start.x) < 7)  && (!(p.x < minX || p.x > maxX || p.y < minY || p.y > maxY))) 
		return true;
	return false;
}