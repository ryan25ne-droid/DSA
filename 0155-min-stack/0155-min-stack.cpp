// class MinStack {
//     stack<int> st;
//     int minEle;
// public:
//     MinStack() {
//         minEle= INT_MAX;        
//     }
    
//     void push(int value){
//         st.push(value); 
//         minEle=        
//     }
    
//     void pop() {
//         st.pop();   
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         return minEle;        
//     }
// };

//The problem above is that suppose we pop the minEle from the stacck. Now we don;t know the minEle from other elements
#define ll long long

class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
    }
    
    void push(int value) {
        st.push(value);
        if(minSt.empty() || value<= minSt.top()){
            minSt.push(value);
        }
    }
    
    void pop(){
        if(st.empty()){  //i.e. minSt is empty too
            return;
        }

        if(st.top()== minSt.top()){
            minSt.pop();
        }        
        st.pop();
    }
    
    int top() {
        return st.top();        
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */