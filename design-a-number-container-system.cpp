class NumberContainers {
    unordered_map<int,int>num;
    unordered_map<int,set<int>>ind;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(num.find(index)!=num.end()){
            int n = num[index];
            ind[n].erase(index);
            if(ind[n].size()==0){
                ind.erase(n);
            }
        }
        num[index] = number;
        ind[number].insert(index);
    }
    
    int find(int number) {
        if(ind.find(number)==ind.end()){
            return -1;
        }
        return *ind[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */