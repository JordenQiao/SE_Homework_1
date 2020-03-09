#include<stdio.h>
#include<set>
#include<string>
#include<iostream>
#include<fstream>	
#include<sstream>
#include <limits>
#include "function.h"	
using namespace std;

//std::string DoubleToString(const double value, unsigned int precisionAfterPoint)
//{
//   std::ostringstream out;
//   // 清除默认精度
//   out.precision(std::numeric_limits<double>::digits10);
//   out << value;
//
//   std::string res = std::move(out.str());
//   auto pos = res.find('.');
//   if (pos == std::string::npos)
//       return res;
//
//   auto splitLen = pos + 1 + precisionAfterPoint;
//   if (res.size() <= splitLen)
//       return res;
//
//   return res.substr(0, splitLen);
//}

void Function::readFile(string filename)
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
		stringstream ss;	//输入流
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

void Function::getLinePara(Line& line)
{
	//if (line.isVertical) {
	//	return;
	//}
	//line.k = (double)(line.y1 - line.y2) / (double)(line.x1 - line.x2);
	//line.b = line.y1 - line.k * line.x1;
	line.a = (double)line.y2 - line.y1;
	line.b = (double)line.x2 * line.y1 - (double)line.x1 * line.y2;
	line.c = (double)line.x2 - line.x1;
}

bool Function::isCross(Line& a, Line& b, Node& node)
{
	//if (a.isHorizontal && b.isHorizontal) {
	//	return false;
	//}
	//else if (a.isVertical && b.isVertical) {
	//	return false;
	//}
	//else if (a.isVertical) {
	//	node.first = a.x1;
	//	node.second = b.k * node.first + b.b;
	//	return nodes.insert(make_pair(node.first, node.second)).second;
	//}
	//else if (b.isVertical) {
	//	node.first = b.x1;
	//	node.second = a.k * node.first + a.b;
	//	return nodes.insert(make_pair(node.first, node.second)).second;
	//}
	//else if (a.k == b.k) {
	//	return false;
	//}
	////node.first = (b.b - a.b) / (a.k - b.k);
	////node.second = a.k * node.first + a.b;
	////return nodes.insert(make_pair(node.first, node.second)).second;

	//node.first = (b.b - a.b) / (a.k - b.k);
	//node.second = a.k * node.first + a.b;
	//return nodes.insert(make_pair(node.first, node.second)).second;

	double temp = a.a * b.c - a.c * b.a;
	if (temp != 0) {
		if (a.a == 0) {
			node.second = (double)a.y1;
			node.first = (a.y1 * b.c - b.b) / b.a;
		}
		else {
			node.second = (a.a * b.b - a.b * b.a) / temp;
			node.first = (node.second * a.c - a.b) / a.a;
		}
		nodes.insert(make_pair(node.first, node.second));
	}
	return true;
}

void Function::output(string filename)
{
	ofstream out(filename);
	out << nodes.size() << endl;
}

//void handleArg(int argc, char** argv)
//{
//	string type;
//	type = argv[1];
//	if (type == "-i") {
//		inFile = argv[2];
//	}
//	else {
//		cout << "WRONG ORDER!" << endl;
//	}
//	type = argv[3];
//	if (type == "-o") {
//		outFile = argv[4];
//	}
//	else {
//		cout << "WRONG ORDER!" << endl;
//	}
//	return;
//}

int main()
{
	Node temp;
	Function function;
	//handleArg(argc, argv);
	inFile = "input.txt";
	outFile = "output.txt";
	function.readFile(inFile);

	for (int i = 0; i < lines.size(); i++) {
		for (int j = i + 1; j < lines.size(); j++) {
			function.isCross(lines[i], lines[j], temp);
		}
	}

	cout << nodes.size() << endl;
	function.output(outFile);
}

