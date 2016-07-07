#include "PathFinder.h"

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>
#include <fstream>
#include <iostream>

using namespace std;

// Recursive solution
void PathFinder::doFindRecursive(char start, char end, unordered_map<char, vector<char>>& Graph, string& tmp, vector<string>& res, unordered_map<char, bool>& visited) {
    tmp += start;

    if(start == end) {
        res.push_back(tmp);
        return;
    }
    
    visited[start] = true;
    for(auto nb : Graph[start]) {
        if(visited[nb] == false) {
            doFindRecursive(nb, end, Graph, tmp, res, visited);
            tmp = tmp.substr(0, tmp.length() - 1);
        }
    }
    visited[start] = false;
}

// Iterative solution
vector < string > PathFinder::doFindIterative(char start, char end, unordered_map<char, vector<char>>& Graph, unordered_map<char, bool>& visited) {
    vector < string > res;
    string tmp;
    
    stack<char> s;
    s.push(start);
    while(!s.empty()) {
        char now = s.top();
        s.pop();
        
        tmp += now;
        if(now == end) {
            res.push_back(tmp);
            continue;
        }
        
        visited[now] = true;
        
        
        for(auto nb : Graph[now]) {
            if (visited[nb] == false) {
                s.push(nb);
            }
        }
    }
    
    return res;
}



vector < string > PathFinder::parseFile( const string& filename ) {
	ifstream ifs( filename.c_str(), ios::in );
	if ( !ifs ) { throw "File not found!"; }

	vector < string > lines;
	string line;
	while ( getline( ifs, line ) ) {
		lines.push_back( line );
	};

	return PathFinder::parseLines( lines );
}

vector < string > PathFinder::parseLines( const vector < string >& lines ) {
    char start = lines[0][0];
    char end = lines[0][2];
    vector<string> res;
    string tmp;
    unordered_map<char, bool> visited;
    unordered_map<char, vector<char>> Graph;
    for(int i = 1; i < lines.size(); i++) {
        visited[lines[i][0]] = false;
        for(int j = 1; j < lines[i].size(); j++) {
            if (isalpha(lines[i][j])) {
                Graph[lines[i][0]].push_back(lines[i][j]);
            }
        }
    }
    

    // Recursive solution
    doFindRecursive(start, end, Graph, tmp, res, visited);
    // Iterative solution
    //res = doFindIterative(start, end, Graph, visited);
    
    for (auto p : res)
        cout << p << endl;
	return res;
}



