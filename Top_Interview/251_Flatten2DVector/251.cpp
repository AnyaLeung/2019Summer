class Vector2D {
private:
    vector<int> vec1d;
    int i = 0;
    
public:
    Vector2D(vector<vector<int>>& v) {
        for(auto a : v){
            vec1d.insert(vec1d.end(), a.begin(), a.end());
        }
    }
    
    int next() {
        return vec1d[i++];
    }
    
    bool hasNext() {
        return i < vec1d.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
