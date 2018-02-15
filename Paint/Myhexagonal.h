#pragma once
#include "myshape.h"
class Myhexagonal : public MyShape
{
public:
	DECLARE_SERIAL(Myhexagonal)
	Myhexagonal(void);
	~Myhexagonal(void);
	void innerDraw(CDC *dc);
	bool InShape(CPoint p);
};