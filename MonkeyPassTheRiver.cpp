int solution(vector<int> &A, int D) {
    int N = (int)A.size();
    
    // illegal check
    if(D < 0 || D > 100001 || N > 100000) return -1;
    // corner cases check
    if(N == 0 || D > N) return 0;
    
    // Find the max time in A
    int maxTime = -1;
    for(auto t : A)
        maxTime = max(maxTime, t);
    
    // A[i] time shows No.i stone, and no stone show by -1
    vector<int> stoneShowsTime(maxTime + 1, -1);
    for(int i = 0; i < N; ++i) {
        if(-1 != A[i])
            stoneShowsTime[A[i]] = i;
    }
    
    int most = 0;
    int cur = -1;
    // Traverse time and get answer, Let's go
    // Although 3 loop but it did O(N + maxTime) in time complexity
    for(int t = 0; t <= maxTime; ++t) {
        if(stoneShowsTime[t] == -1) continue;
        int stone = stoneShowsTime[t];
        while(cur + D >= stone && cur < stone && A[stone] <= t) {
            cur = stone;
            if(cur + D >= N) return t;// We can get to the other side now
            
            while(most <= cur + D) {
                if(A[most] <= t && -1 != A[most])
                    stone = most;
                ++most;
            }
        }
    }
    
    return -1;
}
