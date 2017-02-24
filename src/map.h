
// Needs to be compiled with flag -std=c++11 


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <unistd.h>

#define POLY_START      "BEGIN POLYGON"
#define POLY_END        "END POLYGON"
#define POLY_INSIDE     "INSIDE"
#define POLY_OUTSIDE    "OUTSIDE"
#define MARKING_START   "BEGIN MARKING"
#define MARKING_END     "END MARKING" 
#define COMMENT_SIGN    '#'

using namespace std;

struct Marking
{
    int id;
    int x, y;
};

struct Node
{
	int id;
    int x,y;
};

struct Polygon
{
    bool allowedInside;
    int numOfNodes;
	vector<Node> nodes;
};

class Map{
    public:
        vector<Polygon> polygons;
        vector<Marking> markings;
        void printPoly(Polygon *poly);
        void printMarking(Marking *marking);
        void printMap();
        void getMarkingPos(int id, int &x, int &y);
        bool isPosInPoly(Polygon *poly, int x, int y);
        void isForbiddenPos(int x, int y, bool &b);
        string getexepath();
        Map();        
        
    private:
        void createPoly(ifstream &in, Polygon &poly);
        void createMarking(ifstream &in, Marking &marking);
        bool isCommentLine(string &str);
};




