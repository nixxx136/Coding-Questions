//from c
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
//stream
#include <fstream>
#include <iostream>
#include <sstream>

//containers
#include <string>
#include <bitset>
#include <vector>
#include <list>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <limits>
#include <climits>
#include <numeric>
#include <iomanip>
using namespace std;


class Solution {
public:
    string minimumString(vector<string> input) {
        string res;
        unordered_map<char, unordered_set<char>> map;
        unordered_set<char> charSet;
        
        makeGraph(input, map, charSet);
        
        queue<char> traverse;
        
        for (auto c : charSet) {
            if (map[c].size() == 0) { //add c to the map here, weird!!!
                traverse.push(c);
            }
        }

        while (traverse.size() != 0) {
            char tmp = traverse.front();
            traverse.pop();
            res += tmp;
            for (auto& pair : map) { // & is important here
                if (pair.second.count(tmp) != 0) {
                    pair.second.erase(tmp);
                    if (pair.second.size() == 0) {
                        traverse.push(pair.first);
                    }
                }
            }
        }
        return res;
    }
    
    void makeGraph(vector<string> input, unordered_map<char, unordered_set<char>>& map, unordered_set<char>& charSet) {
        for (auto s : input) {
            for (int i = 1; i < s.size(); i++) {
                char pre = s[i - 1];
                char now = s[i];
                map[now].insert(pre);
                charSet.insert(pre);
                charSet.insert(now);
            }
        }
    }
};

int main(void)
{
    vector<string> input = {"gcd", "jd", "fcj"};
    Solution sol;
    sol.minimumString(input);
    return 0;
}