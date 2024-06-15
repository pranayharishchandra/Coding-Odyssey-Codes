#include <iostream>
#include <vector>
using namespace std;


class Solution
{
    public:
    
    //create struct 
    struct meeting{
        int start;
        int end;
        int pos;
    };
    
    //comparator
    static bool comparator(struct meeting m1,  meeting m2){
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if(m1.pos < m2.pos) return true;
        else if(m1.start > m2.start) return false; // return true or false, doesn't matter
        return false;
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meeting meet[n];
        
        for(int i = 0; i<n; i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i+1;
        }
        
        sort(meet, meet+n, comparator);
        
        vector<int> answer;
        int limit = meet[0].end;
        answer.push_back(meet[0].pos);
        
        for(int i = 0; i<n; i++){
            if(meet[i].start > limit){
                answer.push_back(meet[i].pos);
                limit = meet[i].end;
            }
        }
        return answer.size();
    }
};
