int main(void)
{
    
    ifstream in("/Users/Xiangyu/Desktop/input.txt");
    string strtmp;
    vector<time_t> timeList;
    vector<string> stateList;
    
    while(getline(in, strtmp, '\n')){
        tm *tmp = new tm();
        
        strtmp = strtmp.substr(strtmp.find('(') + 1);
        
        string month = strtmp.substr(0, strtmp.find('/'));
        tmp->tm_mon = stoi(month) - 1;
        strtmp = strtmp.substr(strtmp.find('/') + 1);
        
        string day = strtmp.substr(0, strtmp.find('/'));
        tmp->tm_mday = stoi(day);
        strtmp = strtmp.substr(strtmp.find('/') + 1);
        
        
        string year = strtmp.substr(0, strtmp.find('-'));
        tmp->tm_year = stoi(year) - 1900;
        strtmp = strtmp.substr(strtmp.find('-') + 1);
        
        string hour = strtmp.substr(0, strtmp.find(':'));
        tmp->tm_hour = stoi(hour);
        strtmp = strtmp.substr(strtmp.find(':') + 1);
        
        string minute = strtmp.substr(0, strtmp.find(':'));
        tmp->tm_min = stoi(minute);
        strtmp = strtmp.substr(strtmp.find(':') + 1);
        
        
        string second = strtmp.substr(0, strtmp.find(')'));
        tmp->tm_sec = stoi(minute);
        strtmp = strtmp.substr(strtmp.find(')') + 1);
        strtmp = strtmp.substr(strtmp.find(' ') + 1);
        strtmp = strtmp.substr(strtmp.find(':') + 1);
        strtmp = strtmp.substr(strtmp.find(':') + 1);
        strtmp = strtmp.substr(strtmp.find(' ') + 1);
        
        string state = strtmp;
        
        timeList.push_back(mktime(tmp));
        stateList.push_back(state);
    }
    
    long total = timeList[timeList.size() - 1] - timeList[0];
    
    long use = 0;
    
    for(int i = 0; i < timeList.size() - 1; ++i) {
        if (stateList[i] == "CONNECTED") {
            cout << timeList[i + 1] << endl;
            cout << timeList[i] << endl;
            use += timeList[i + 1] - timeList[i];
        }
    }

    
    cout << (double)use / total << endl;
    
    return 0;
}