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
using namespace std;


// Some error here
string ans(string Coder, string J) {
    string res1;
    string res2;
    
    bool JLarge = false;
    int index = 0;
    while(1 && index < Coder.size()) {
        if(Coder[index] == '?' && J[index] == '?') {
            res1 += '0';
            res2 += '0';
        }
        else if(Coder[index] == '?') {
            Coder[index] = J[index];
            res1 += J[index];
            res2 += J[index];
        }
        else if(J[index] == '?') {
            J[index] = Coder[index];
            res1 += Coder[index];
            res2 += Coder[index];
        }
        
        if(Coder[index] != J[index])
            break;
        index++;
    }
    
    if(index < Coder.size()) {
        if(Coder[index] < J[index])
            JLarge = true;
        res1 += Coder[index];
        res2 += J[index];
        index++;
    }
    
    
    while(index < Coder.size()) {
        if(JLarge) {
            if(Coder[index] == '?')
                Coder[index] = '9';
            if(J[index] == '?')
                J[index] = '0';
            
            res1 += Coder[index];
            res2 += J[index];
        }
        else {
            if(Coder[index] == '?')
                Coder[index] = '0';
            if(J[index] == '?')
                J[index] = '9';
            
            res1 += Coder[index];
            res2 += J[index];
        }
        index++;
    }
    
    
    return res1 + " " + res2;
}
int main (int argc, const char * argv[])
{
    //    Solution sol;
    ifstream in("/Users/Xiangyu/Desktop/B-small-attempt0.in");
    ofstream out("/Users/Xiangyu/Desktop/output.txt");
    if (!in.is_open() || !out.is_open()) {
        cout << "Error opening file" << endl;
        exit (1);
    }
    int i = 0;
    in >> i;
    
    string a;
    int index = 1;
    while (index <= i) {
        string Coder, J;
        in >> Coder;
        in >> J;
        out << "Case #" << index << ": " << ans(Coder, J) << endl;
        index++;
    }
    in.close();
    out.close();
    return 0;
}