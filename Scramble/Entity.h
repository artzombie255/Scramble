#pragma once
class Entity
{
public:
	virtual void move();
	int getY();
	int getX();
protected:
	int Y, X;
};

