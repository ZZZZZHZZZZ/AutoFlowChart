#pragma once
#ifndef _STATEMENT_
#include "Print.h"
#include "Link.h"
class Statement :public Print
{
public:
	Statement(string initBody);
	virtual void draw(const int& middle) const;
	void drawIF(const int& middle, const int& length) const;
	void drawStatement(const int& middle) const;
	void drawStatement(const int& middle,const int& length) const;
	void drawLastStatement(const int& middle, const int& length) const;
	void tempdraw(const int& length)const;
	int getLength() const;
	string getBody();
private:
	string body;
};
#define _STATEMENT_
#endif //

