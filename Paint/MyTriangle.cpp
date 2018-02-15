#include "StdAfx.h"
#include "MyTriangle.h"

IMPLEMENT_SERIAL(MyTriangle, MyShape, 1)

MyTriangle::MyTriangle(void) {}
MyTriangle::~MyTriangle(void) {}

void MyTriangle::innerDraw(CDC *dc)
{
	CPoint TPoints[3];
	TPoints[0].SetPoint(start.x,end.y);
	TPoints[1].SetPoint(end.x,end.y);
	TPoints[2].SetPoint((start.x+end.x)/2,start.y);

	dc->Polygon(TPoints,3);
}

bool MyTriangle::InShape(CPoint p)
{
	int minX = start.x < end.x ? start.x : end.x;
	int maxX = start.x > end.x ? start.x : end.x;
	int minY = start.y < end.y ? start.y : end.y;
	int maxY = start.y > end.y ? start.y : end.y;

	if (!(p.x < minX || p.x > maxX || p.y < minY || p.y > maxY))
		return true;
	return false;
}