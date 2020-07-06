#pragma once
#ifndef _LINK_
#define _LINK_
#include "Print.h"

class Link :public Print
{
public:
	virtual void draw (const int& middle) const;
};

#endif // !_LINK

