#include "StdAfx.h"
#include "MyTrapeze.h"

IMPLEMENT_SERIAL(MyTrapeze, MyShape, 1)

MyTrapeze::MyTrapeze(void) {}
MyTrapeze::~MyTrapeze(void) {}

void MyTrapeze::innerDraw(CDC *dc)
{
	CPoint TrapezePoints[4];
	TrapezePoints[0].SetPoint(start.x,end.y);
	TrapezePoints[1].SetPoint(end.x,end.y);
	TrapezePoints[2].SetPoint((end.x-start.x)*3/4+start.x,start.y);
	TrapezePoints[3].SetPoint((end.x-start.x)*1/4+start.x,start.y);

	dc->Polygon(TrapezePoints,4);
}

bool MyTrapeze::InShape(CPoint p)
{
	int minX = start.x < ((end.x-start.x)*1/4) ? start.x : ((end.x-start.x)*1/4);
	int maxX = ((end.x-start.x)*3/4) > end.x ? ((end.x-start.x)*3/4) : end.x;
	int minY = start.y < end.y ? start.y : end.y;
	int maxY = start.y > end.y ? start.y : end.y;

	if (!(p.x < minX || p.x > maxX || p.y < minY || p.y > maxY))
		return true;
	return false;
}