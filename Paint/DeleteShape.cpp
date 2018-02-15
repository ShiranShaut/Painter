#include "StdAfx.h"
#include "DeleteShape.h"

DeleteShape::DeleteShape(CTypedPtrArray<CObArray, MyShape*> &myShapes, MyShape *s)
	: myShapes(myShapes), s(s) {}

DeleteShape::~DeleteShape(void) {}

void DeleteShape::perform()
{
	oldStart = s->start;
	oldEnd = s->end;
	s->start = 0;
	s->end = 0;
	//s->start.x = 0;
	//s->start.y = 0;
	//s->end.x = 0;
	//s->end.y = 0;
}

void DeleteShape::rollback()
{ 
	s->start = oldStart;
	s->end = oldEnd;
	//s->start.x = oldStart.x;
	//s->start.y = oldStart.y;
	//s->end.x = oldEnd.x;
	//s->end.y = oldEnd.y;
}