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
			circle.node.first = circle.x;
			circle.node.second = circle.y;
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

bool Function::L2LIsCross(Line& a, Line& b, Node& node, bool flag)
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

	//ax+b=cy
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
		if (flag) {
			nodes.insert(make_pair(node.first, node.second));
		}
	}
	return true;
}

void Function::output(string filename)
{
	ofstream out(filename);
	out << nodes.size() << endl;
}

bool Function::C2CIsCross(Circle& a, Circle& b)
{
	double distance = getDistance(a.node, b.node);
	double r2 = (a.r + b.r) * (a.r + b.r);
	// 两个圆没有交点
	if (distance > r2) {
		return false;
	}
	Line temp;
	temp.a = 2 * (b.x - a.x);
	temp.b = a.x * a.x + a.y * a.y - b.x * b.x - b.y * b.y - a.r * a.r + b.r * b.r;
	temp.c = 2 * (a.y - b.y);
	C2LIsCross(a, temp);
	return true;
}

double getDistance(Node& a, Node& b)
{
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool Function::C2LIsCross(Circle& circle, Line& line)
{
	Line temp;
	Node node, vect;
	double distance, r2;
	temp.a = line.c;
	temp.c = -line.a;
	temp.b = temp.c * circle.y - temp.a * circle.x;
	temp.x1 = circle.x;
	temp.y1 = circle.y;
	L2LIsCross(line, temp, node, false);		// temp为垂线，node为垂心
	distance = getDistance(node, circle.node);
	r2 = circle.r * circle.r;

	cout << r2 << " " << distance << endl;
	
	// 线与圆没有交点
	if (distance > r2) {
		return false;
	}
	// 线与圆有交点
	double dis = sqrt(r2 - distance);
	// 线与圆有两个交点
	if (dis > 0) {
		vect.first = (double)(line.c) / sqrt(line.a * line.a + line.c * line.c) * dis;
		vect.second = (double)(line.a) / sqrt(line.a * line.a + line.c * line.c) * dis;
		nodes.insert(make_pair(node.first + vect.first, node.second + vect.second));
		nodes.insert(make_pair(node.first - vect.first, node.second - vect.second));
	}
	// 线与圆有一个交点
	else {
		nodes.insert(node);
	}
	return true;
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
			function.L2LIsCross(lines[i], lines[j], temp, true);
		}
	}

	for (int i = 0; i < circles.size(); i++) {
		for (int j = 0; j < lines.size(); j++) {
			function.C2LIsCross(circles[i], lines[j]);
		}
	}

	for (int i = 0; i < circles.size(); i++) {
		for (int j = i + 1; j < circles.size(); j++) {
			function.C2CIsCross(circles[i], circles[j]);
		}
	}

	cout << nodes.size() << endl;
	function.output(outFile);
}

