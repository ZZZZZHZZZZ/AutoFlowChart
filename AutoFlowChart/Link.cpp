#include "Link.h"

void Link::draw(const int& middle) const
{
	for (int i = 0; i < middle; ++i) {
		cout << " ";
	}
	cout<<"|"<<endl;
	for (int i = 0; i < middle; ++i) {
		cout << " ";
	}
	cout << "V" << endl;
}
