class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int m= logs.size();
        int currTime= 0;
        int prevTime= 0;
        int id=0;
        int longest= INT_MIN;

        for(int i=0; i<m; i++){
            prevTime= currTime;
            currTime= logs[i][1];

            if(currTime- prevTime> longest){
                longest= currTime- prevTime;
                id= logs[i][0];
            }
            else if(currTime- prevTime== longest){
                id= min(id, logs[i][0]);
            }
        }
        return id;
    }
};