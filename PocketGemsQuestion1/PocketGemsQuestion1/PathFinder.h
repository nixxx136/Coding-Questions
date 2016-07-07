#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
class PathFinder {
public:
	static std::vector < std::string > parseFile( const std::string& );
	static std::vector < std::string > parseLines( const std::vector < std::string >& lines );
    static void doFindRecursive(char, char, unordered_map<char, vector<char>>&, string&, vector<string>&, unordered_map<char, bool>&);
    static std::vector < std::string > doFindIterative(char, char, unordered_map<char, vector<char>>&, unordered_map<char, bool>&);
};

#endif
