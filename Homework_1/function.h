#pragma once
#include<set>
#include<vector>
#include<unordered_map>
using namespace std;


typedef pair<double, double> Node;
double getDistance(Node& a, Node& b);

struct cmp {
	bool operator() (const Node a, const Node b) const
	{
		if (abs(a.first - b.first) <= 1e-12 && abs(a.second - b.second) <= 1e-12)
		{
			return false;
		}
		else if (abs(a.first - b.first) > 1e-12)
		{
			return a.first < b.first;
		} 
		else 
		{
			return a.second < b.second;
		}
	}
};

struct Line {
	long x1, y1, x2, y2;
	double a, b, c;
	bool isVertical = false;
	bool isHorizontal = false;
};

struct Circle {
	long x, y, r;
	Node node;
};

class Function
{
public:
	void readFile(string filename);
	void getLinePara(Line& line);
	bool L2LIsCross(Line& a, Line& b, Node& node, bool flag);
	bool C2CIsCross(Circle& a, Circle& b);
	bool C2LIsCross(Circle& circle, Line& line);
	void output(string filename);
	int Solve(string inFile, string outFile);

private:
	set<Node, cmp> nodes;
	vector<Line> lines;
	vector<Circle> circles;
	string inFile, outFile;
};

