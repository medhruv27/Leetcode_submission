class MinStack {
public:
    stack<long long> s;
    long long min;
    MinStack() {}
    void push(int val) {
        if (s.size() == 0) {
            s.push(val);
            min = val;

        } else {
            if (val >= min) {
                s.push(val);
            }
            else // if (val<min)
            {   // s.push(2*val-min);this line is causing integer overflow error
                // so to remove it we have something special to remember for the
                // lifetime lessons
                long long temp = val;
                temp = temp * 2;
                s.push(temp - min);
                min = val;
            }
        }
    }

    void pop() {           // pop ko samjhana is very  very important
        if (s.size() == 0) // you cant do return -1 in void function
        {
            //  return -1;
        } else {
            if (s.top() >= min)
                s.pop();

            else // if(s.top()<min)
            {

                min = 2 * min - s.top();
                s.pop();
            }
        }
    }

    int top() { // also top ko samjhana is very very important
        if (s.size() == 0) {
            return -1;

        } else {

            if (s.top() >= min)
                return s.top();
            else // if(s.top()<min)
            {
                return min;
            }
        }
        return -1; // i added this myself to make the code pass becoz an int
                   // function must return something
    }

    int getMin() {
        if (s.size() == 0) {
            return -1;
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */