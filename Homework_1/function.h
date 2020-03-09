#pragma once
#include<set>
#include<vector>
#include<unordered_map>
using namespace std;

//std::string DoubleToString(const double value, unsigned int precisionAfterPoint);
//
//class Node
//{
//public:
//	double x, y;
//	string getValue() {
//		return DoubleToString(x, 10) + "#" + DoubleToString(y, 10);
//	}
//};

typedef pair<double, double> Node;

struct Line {
	int x1, y1, x2, y2;
	double a, b, c;
	bool isVertical = false;
	bool isHorizontal = false;
};

struct Circle {
	int x, y, r;
};

class Function
{
public:
	void readFile(string filename);
	void getLinePara(Line& line);
	bool isCross(Line& a, Line& b, Node& node);
	void output(string filename);
};

//struct Node {
//	float x, y;
//
//	bool operator <(const Node& a) const
//	{
//		return x * x + y * y < a.x * a.x + a.y * a.y;
//	}
//}

set<Node> nodes;
vector<Line> lines;
vector<Circle> circles;
int NumOfGraph;
string inFile, outFile;

//void handleArg(int argc, char** argv);
