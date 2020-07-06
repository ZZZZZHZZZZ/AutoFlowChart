#include "Statement.h"

Statement::Statement(string initBody):body(initBody){}

void Statement::draw(const int& middle) const
{
	int begin = middle - (this->getLength()) / 2 - 3;
	for (int i = 0; i < begin; ++i) {
		cout << " ";
	}
	cout << "/--";
	for (int i = 0; i < this->getLength(); ++i) {
		cout << "-";
	}
	cout << "--\\"<<endl;

	for (int i = 0; i < begin; ++i) {
		cout << " ";
	}
	cout << "|  " << this->body << "  |" << endl;

	for (int i = 0; i < begin; ++i) {
		cout << " ";
	}
	cout << "\\--";
	for (int i = 0; i < this->getLength(); ++i) {
		cout << "-";
	}
	cout << "--/" << endl;
}

void Statement::drawIF(const int& middle,const int& length) const
{
	int begin = middle - (this->getLength()) / 2 - 3;
	for (int i = 0; i < begin; ++i) {
		cout << " ";
	}
	cout << "/--";
	for (int i = 0; i < this->getLength(); ++i) {
		cout << "-";
	}
	cout << "--\\"<< " No"<<endl;


	for (int i = 0; i < begin; ++i) {
		cout << " ";
	}
	cout << "|  " << this->body << "  |";

	for (auto i = 0; i < length; ++i) {
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < begin; ++i) {
		cout << " ";
	}
	cout << "\\--";
	for (int i = 0; i < this->getLength(); ++i) {
		cout << "-";
	}
	cout << "--/";
	tempdraw(length);


	for (int i = 0; i < middle; ++i) {
		cout << " ";
	}
	cout << "| Yes";
	if (this->getLength() % 2 == 0) {
		tempdraw(length+this->getLength()/2-2);
	}
	else {
		tempdraw(length + this->getLength()/2 - 1);
	}
	for (int i = 0; i < middle; ++i) {
		cout << " ";
	}
	cout << "V";
	if (this->getLength() % 2 == 0) {
		tempdraw(length + this->getLength() / 2 +2);
	}
	else {
		tempdraw(length + this->getLength() / 2 + 3);
	}
}

void Statement::drawStatement(const int& middle) const
{
	draw(middle);
	for (int i = 0; i < middle; ++i) {
		cout << " ";
	}
	cout << "|" << endl;
	for (int i = 0; i < middle; ++i) {
		cout << " ";
	}
	cout << "V" << endl;
}

void Statement::drawStatement(const int& middle, const int& length) const
{
	int begin = middle - (this->getLength()) / 2 - 3;
	for (int i = 0; i < begin; ++i) {
		cout << " ";
	}
	cout << "/--";
	for (int i = 0; i < this->getLength(); ++i) {
		cout << "-";
	}
	cout << "--\\";
	tempdraw(length);

	for (int i = 0; i < begin; ++i) {
		cout << " ";
	}
	cout << "|  " << this->body << "  |";
	tempdraw(length);

	for (int i = 0; i < begin; ++i) {
		cout << " ";
	}
	cout << "\\--";
	for (int i = 0; i < this->getLength(); ++i) {
		cout << "-";
	}
	cout << "--/";
	tempdraw(length);
	for (int i = 0; i < middle; ++i) {
		cout << " ";
	}
	cout << "|";
	if (this->getLength() % 2 != 0) {
		tempdraw(length + this->getLength() / 2 + 3);
	}
	else {
		tempdraw(length + this->getLength() / 2 + 2);
	}
	for (int i = 0; i < middle; ++i) {
		cout << " ";
	}
	cout << "V";
	if (this->getLength() % 2 != 0) {
		tempdraw(length + this->getLength() / 2 + 3);
	}
	else {
		tempdraw(length + this->getLength() / 2 + 2);
	}
}

void Statement::drawLastStatement(const int& middle, const int& length) const
{
	int begin = middle - (this->getLength()) / 2 - 3;
	for (int i = 0; i < begin; ++i) {
		cout << " ";
	}
	cout << "/--";
	for (int i = 0; i < this->getLength(); ++i) {
		cout << "-";
	}
	cout << "--\\";
	tempdraw(length+2-this->getLength()/2-2);

	for (int i = 0; i < begin; ++i) {
		cout << " ";
	}
	cout << "|  " << this->body << "  |";
	tempdraw(length + 2 - this->getLength() / 2 - 2);

	for (int i = 0; i < begin; ++i) {
		cout << " ";
	}
	cout << "\\--";
	for (int i = 0; i < this->getLength(); ++i) {
		cout << "-";
	}
	cout << "--/";
	tempdraw(length + 2 - this->getLength() / 2 - 2);

	for (int i = 0; i < middle; ++i) {
		cout << " ";
	}
	cout << "|" << " <";
	for (int i = 0; i < length; ++i) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < middle; ++i) {
		cout << " ";
	}
	cout << "V"<<endl;
}

void Statement::tempdraw(const int& length) const
{
	for (int i = 0; i < length; ++i) {
		cout << " ";
	}
	cout << "|" << endl;
}



int Statement::getLength() const
{
	return this->body.length();
}

string Statement::getBody()
{
	return this->body;
}


