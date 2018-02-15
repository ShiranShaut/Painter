#pragma once
#include "command.h"
#include "MyShape.h"

class DeleteShape : public command
{
public:
	DeleteShape(CTypedPtrArray<CObArray, MyShape*> &myShapes, MyShape *s);
	~DeleteShape(void);
	void perform();
	void rollback();
private:
	CTypedPtrArray<CObArray, MyShape*> &myShapes;
	MyShape *s;
	CPoint oldStart, oldEnd;
};