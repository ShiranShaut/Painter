#include "StdAfx.h"
#include "AddColor.h"

AddColor::AddColor(MyShape *s,COLORREF color) : s(s), newColor(color) {}

AddColor::~AddColor(void) {}

void AddColor::perform()
{	
	oldColor = s->bgColor;
	oldPen = s->pColor;
	oldSize = s->ShapePenSize;
	oldType = s->ShapePenType;
	s->setBg(newColor);
	s->setP(RGB(0,0,0));
	s->setShapePenSize(1);
	s->setShapePenType(PS_SOLID);
}

void AddColor::rollback()
{
	s->setBg(oldColor);
	s->setP(oldPen);
	s->setShapePenSize(oldSize);
	s->setShapePenType(oldType);
}