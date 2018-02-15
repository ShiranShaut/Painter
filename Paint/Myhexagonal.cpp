#include "StdAfx.h"
#include "Myhexagonal.h"

IMPLEMENT_SERIAL(Myhexagonal, MyShape, 1)

Myhexagonal::Myhexagonal(void){}
Myhexagonal::~Myhexagonal(void){}


void Myhexagonal::innerDraw(CDC *dc)
{
	CPoint hexagonalPoints[6];
	hexagonalPoints[0].SetPoint(start.x,end.y);
	hexagonalPoints[1].SetPoint(end.x,end.y);
	hexagonalPoints[2].SetPoint(end.x+(end.x-start.x),(end.y+start.y)*0.5);
	hexagonalPoints[3].SetPoint(end.x,start.y);
	hexagonalPoints[4].SetPoint(start.x,start.y);
	hexagonalPoints[5].SetPoint(start.x-(end.x-start.x),(end.y+start.y)*0.5);

	dc->Polygon(hexagonalPoints,6);
}

bool Myhexagonal::InShape(CPoint p)
{
	int minX = start.x < (start.x-(end.x-start.x)) ? start.x : (start.x-(end.x-start.x));
	int maxX = end.x+(end.x-start.x) > end.x ? end.x+(end.x-start.x) : end.x;
	int minY = start.y < end.y ? start.y : end.y;
	int maxY = start.y > end.y ? start.y : end.y;

	if (!(p.x < minX || p.x > maxX || p.y < minY || p.y > maxY))
		return true;
	return false;
}