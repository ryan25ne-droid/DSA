class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses){
// Step 1: sort by deadline
        sort(courses.begin(), courses.end(), [](auto &a, auto &b){
            return a[1]< b[1];
        });

        priority_queue<int> maxHeap; // store durations in this
        int time=0;

// Step 2: process courses
        for(auto &c:courses){
            int duration=c[0], deadline=c[1];
            time+=duration;
            maxHeap.push(duration);

// Step 3:if deadline is exceeded, drop longest course
            if(time>deadline){
                time-=maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size(); //number of courses taken        
    }
};