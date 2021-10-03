/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    
    stack<NestedInteger> mystack;
    bool cached;
    int v;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size()-1;i >= 0;i--)
            mystack.push(nestedList[i]);
        cached = false;
    }

    int next() {
        hasNext();
        cached = false;
        return v;
    }

    bool hasNext() {
        if (cached) return true;
        while (!mystack.empty()) {
            NestedInteger tmp = mystack.top();
            mystack.pop();
            if (tmp.isInteger()) {
                v = tmp.getInteger();
                cached = true;
                return true;
            }
            vector<NestedInteger> nlist = tmp.getList();
            for (int i = nlist.size()-1;i >= 0;i--) mystack.push(nlist[i]);
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */







// pointer
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    stack<NestedInteger*> mystack;
    int cache = 0;
    bool cached = false;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            mystack.push(&nestedList[i]);
        }
    }
    
    int next() {
        hasNext();
        cached = false;
        return cache;
    }
    
    bool hasNext() {
        if (cached == true) {
            return true;
        }
        
        while (!mystack.empty()) {
            NestedInteger* ni = mystack.top();
            mystack.pop();

            if (ni->isInteger()) {
                cached = true;
                cache = ni->getInteger();
                return true;
            }
            
            for (int i = ni->getList().size() - 1; i >= 0; i--) {
                mystack.push(&ni->getList()[i]);
            }
        }
        
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
