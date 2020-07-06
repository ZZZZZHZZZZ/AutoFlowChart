#include "Link.h"
#include "Statement.h"
#include "IfStatement.h"
#include <fstream>
#include <vector>
#include <stack>
void getMaxLength(const vector<string>& statementBodyVec, int& maxLength);
int main() {
	vector<string> statementBodyVec;
	ifstream myFile("test.cpp");
	if (myFile.is_open()) {
		string temp;
		while (getline(myFile, temp)) {
			statementBodyVec.push_back(temp);
		}
	}
	int maxLength=0;
	getMaxLength(statementBodyVec, maxLength);
	int middle = maxLength / 2 + 3;
	maxLength = middle * 2;
	stack<string> tempStack;
	stack<Statement> resStack;
	int frontNumber = 0;
	int backNumber = 0;
	bool structFlag = false;
	for (int i = 0; i < statementBodyVec.size(); ++i) {
		if (statementBodyVec[i].find("{") != statementBodyVec[i].npos) {
			statementBodyVec[i] = statementBodyVec[i].substr(statementBodyVec[i].find("if")+2, statementBodyVec[i].size());
			tempStack.push(statementBodyVec[i].substr(0, statementBodyVec[i].find("{")));
			tempStack.push("{");
			++frontNumber;
			structFlag = true;
		}
		else if (statementBodyVec[i].find("}") != statementBodyVec[i].npos) {
			tempStack.push("}");
			++backNumber;
			if (frontNumber != backNumber) {
				continue;
			}
			else {
				while (!tempStack.empty()) {
					resStack.push(Statement(tempStack.top()));
					tempStack.pop();
				}
				IfStatement ifstatement(resStack);
				ifstatement.draw(middle, maxLength / 2 + 5, maxLength / 2 + 5,resStack);
				structFlag = false;
				/*resStack.top().drawIF(middle, maxLength / 2 - resStack.top().getLength() + 5);
				int length = resStack.top().getLength();
				resStack.pop();
				while (resStack.size() != 1) {
					resStack.top().drawStatement(middle, maxLength / 2 - resStack.top().getLength() - (length - resStack.top().getLength()) / 2 + 5);
					resStack.pop();
				}
				resStack.top().drawLastStatement(middle, maxLength / 2 - resStack.top().getLength() - (length - resStack.top().getLength()) / 2 + 5);
				resStack.pop();
				structFlag = false;*/
			}
			
			
		}
		else if (structFlag==false && statementBodyVec[i].find(";") != statementBodyVec[i].npos) {
			Statement statement(statementBodyVec[i].substr(0, statementBodyVec[i].find(";")));
			if (i != statementBodyVec.size() - 1) {
				statement.drawStatement(middle);
			}
			else {
				statement.drawStatement(middle);
			}
		}
		else if (structFlag == true && statementBodyVec[i].find(";") != statementBodyVec[i].npos) {
			tempStack.push(statementBodyVec[i].substr(0, statementBodyVec[i].find(";")));
		}
	}
	return 0;
}
void getMaxLength(const vector<string> &statementBodyVec,int & maxLength) {
	for (auto temp : statementBodyVec) {
		if (maxLength < temp.length()) {
			maxLength = maxLength < temp.length() ? temp.length() : maxLength;
		}
	}
}