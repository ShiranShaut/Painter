#include "StdAfx.h"
#include "MyPentagon.h"

IMPLEMENT_SERIAL(MyPentagon, MyShape, 1)
MyPentagon::MyPentagon(void){}
MyPentagon::~MyPentagon(void){}

void MyPentagon::innerDraw(CDC *dc)
{
	CPoint pentagonPoints[5];

	pentagonPoints[0].SetPoint(start.x,end.y);
	pentagonPoints[1].SetPoint(end.x,end.y);
	pentagonPoints[2].SetPoint(end.x+(end.x-start.x),(end.y+start.y)*0.5);
	pentagonPoints[3].SetPoint(end.x,start.y);
	pentagonPoints[4].SetPoint(start.x,start.y);

	dc->Polygon(pentagonPoints,5);
}

bool MyPentagon::InShape(CPoint p)
{
	int minX = start.x < end.x ? start.x : end.x;
	int maxX = start.x > (end.x+(end.x-start.x)) ? start.x : (end.x+(end.x-start.x));
	int minY = start.y < end.y ? start.y : end.y;
	int maxY = start.y > end.y ? start.y : end.y;

	if (!(p.x < minX || p.x > maxX || p.y < minY || p.y > maxY))
		return true;
	return false;
}