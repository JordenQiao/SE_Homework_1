#pragma once
#include<set>
#include<vector>	
using namespace std;

struct Line {
	double x1, y1, x2, y2, k, b;
	bool isVertical = false;
	bool isHorizontal = false;
};

struct Circle {
	int x, y, r;
};

struct Node {
	double x, y;

	bool operator <(const Node& a) const
	{
		return x * x + y * y < a.x * a.x + a.y * a.y;
	}
};

set<Node> nodes;
vector<Line> lines;
vector<Circle> circles;
int NumOfGraph;

void readFile(string filename);
void getLinePara(Line& line);
bool isCross(Line& a, Line& b, Node& node);
