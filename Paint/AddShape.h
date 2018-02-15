#pragma once
#include "command.h"
#include "MyShape.h"

class AddShape : public command
{
public:
	AddShape(CTypedPtrArray<CObArray, MyShape*> &myShapes, MyShape *s);
	~AddShape(void);
	void perform();
	void rollback();
private:
	CTypedPtrArray<CObArray, MyShape*> &myShapes;
	MyShape *s;
};