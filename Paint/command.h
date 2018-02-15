#pragma once
class command
{
public:
	command(void);
	~command(void);
	virtual void perform() = 0;
	virtual void rollback() = 0;
};

