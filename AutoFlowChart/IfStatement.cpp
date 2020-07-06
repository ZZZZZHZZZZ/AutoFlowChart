#include "IfStatement.h"

IfStatement::IfStatement(const stack<Statement>& iniIfstruct) :IfStruct(iniIfstruct) {}

void IfStatement::draw(int middle,int length,int lastLength,stack<Statement>& ifStruct)
{
	if (ifStruct.empty()) {
		return;
	}
	else {
		while (ifStruct.size()>1) {
			Statement tempState = ifStruct.top();
			ifStruct.pop();
			if (!ifStruct.empty() && ifStruct.top().getBody() == "{") {
				int frontnumber = 0, backnumber = 0;
				tempState.drawIF(middle, length-tempState.getLength()/2-3);
				frontnumber++;
				stack<Statement> temp1;
				temp1.push(ifStruct.top());
				ifStruct.pop();
				while (!ifStruct.empty()) {
					if (ifStruct.top().getBody() == "}") {
						backnumber++;
					}
					else if (ifStruct.top().getBody() == "{") {
						frontnumber++;
					}
					temp1.push(ifStruct.top());
					ifStruct.pop();
					if (ifStruct.top().getBody() == "}" && frontnumber == backnumber + 1) {
						ifStruct.pop();
						break;
					}
				}
				stack<Statement> temp2;
				while (!temp1.empty()) {
					temp2.push(temp1.top());
					temp1.pop();
				}
				draw(middle, length - 5, length, temp2);
			}
			else if(tempState.getBody()!="{") {
				if (tempState.getLength() % 2 != 0) {
					tempState.drawStatement(middle, lastLength - tempState.getLength()/2- 4);
				}
				else {
					tempState.drawStatement(middle, lastLength - tempState.getLength()/2 - 2);
				}
			}
		}
		if (!ifStruct.empty()) {
			if (ifStruct.top().getLength()%2==0) {
				ifStruct.top().drawLastStatement(middle, lastLength - 2);
			}
			else {
				ifStruct.top().drawLastStatement(middle, lastLength - 3);
			}
			ifStruct.pop();
		}
	}

}
