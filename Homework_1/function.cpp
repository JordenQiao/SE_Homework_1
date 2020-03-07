#include<stdio.h>
#include<set>
#include<string>
#include<iostream>
#include<fstream>	
#include<sstream>
#include "function.h"	
using namespace std;

//Line splitLine(string str)
//{
//
//}

//Circle splitCircle(string str)
//{
//
//}

void readFile(string filename)
{
	ifstream file(filename);
	string str;
	char type;
	Line line;
	Circle circle;

	getline(file, str);
	NumOfGraph = atoi(str.c_str());
	for (int i = 0; i < NumOfGraph; i++) {
		getline(file, str);
		stringstream ss;	//ÊäÈëÁ÷
		ss << str;
		ss >> type;
		if (type == 'L') {
			ss >> line.x1;
			ss >> line.y1;
			ss >> line.x2;
			ss >> line.y2;
			line.isHorizontal = (line.y1 - line.y2 == 0);
			line.isVertical = (line.x1 - line.x2 == 0);
			getLinePara(line);
			lines.push_back(line);
		}
		else if (type == 'C') {
			ss >> circle.x;
			ss >> circle.y;
			ss >> circle.r;
			circles.push_back(circle);
		}
		else {
			cout << "WRONG TYPE DATA" << endl;
		}
	}
}

void getLinePara(Line& line)
{
	if (line.isHorizontal || line.isVertical) {
		return;
	}
	line.k = (line.y1 - line.y2) / (line.x1 - line.x2);
	line.b = line.y1 - line.k * line.x1;
}

bool isCross(Line& a, Line& b, Node& node)
{
	if (a.isHorizontal && b.isHorizontal) {
		return false;
	}
	else if (a.isVertical && b.isVertical) {
		return false;
	}
	else if (a.k == b.k) {
		return false;
	}
	node.x = (b.b - a.b) / (a.k - b.k);
	node.y = a.k * node.x + a.b;
	return true;
}

int main()
{
	Node temp;
	readFile("input.txt");
	for (int i = 0; i < lines.size(); i++) {
		for (int j = i + 1; j < lines.size(); j++) {
			if (isCross(lines[i], lines[j], temp))
				nodes.insert(temp);
		}
	}
	cout << nodes.size() << endl;
}

