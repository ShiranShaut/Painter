#include "StdAfx.h"
#include "MyShape.h"

IMPLEMENT_SERIAL(MyShape, CObject, 1)

MyShape::MyShape(void) {}

MyShape::~MyShape(void) {}

void MyShape::Serialize( CArchive& archive )
{
    // call base class function first
    // base class is CObject in this case
    CObject::Serialize( archive );

    // now do the stuff for our specific class
    if(archive.IsStoring())
		archive << start.x << start.y << end.x << end.y << bgColor << pColor << ShapePenSize << ShapePenType;
    else
        archive >> start.x >> start.y >> end.x >> end.y >> bgColor >> pColor >> ShapePenSize >> ShapePenType;
}

void MyShape::draw(CDC *dc) {
	CPen pen(ShapePenType, ShapePenSize, pColor); 
	CBrush brush(bgColor);
	CBrush *oldBrush = dc->SelectObject(&brush);
	CPen *oldPen = dc->SelectObject(&pen);
	innerDraw(dc);
	dc->SelectObject(oldPen);
	dc->SelectObject(oldBrush);
}