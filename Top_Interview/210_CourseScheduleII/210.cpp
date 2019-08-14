ass Solution {
public:
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0); //in-degree vector
        vector<list<int>> G(numCourses, list<int>({})); // 临接链表
        for(vector<int> cp : prerequisites){
            indegrees[cp[0]] ++;
            G[cp[1]].push_back(cp[0]);
        }
        queue<int> myqueue;

        //add node whose in-degree is 0 to queue
        for(int i=0; i<numCourses; i++){
            if(indegrees[i]==0){
                myqueue.push(i);
            }
        }

        //topo sort res
        while(myqueue.size()){
            int num = myqueue.front();
            myqueue.pop();
            res.push_back(num);
            for(auto v : G[num]){
                indegrees[v] --;
                if(indegrees[v]==0){
                    myqueue.push(v);
                }
            }
        }

        if(res.size()==numCourses){
            return res;
        }
        else{
            res.clear();
            return res;
        }
    }
};
