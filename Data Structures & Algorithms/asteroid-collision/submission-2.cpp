class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> objStack;
        vector<int> toReturn;
      
        for (const int& element : asteroids) 
        {
            bool bElementDestroyed = false;
            if (objStack.empty()) 
            {
                objStack.push_back(element);
                continue;
            }

            int stackTop = objStack.back();
            // The only conditions under which we can have a collision are when the top of the stack is going right (positive), and the current
            // element is going left (negative).  Anything going left can't collide with a right after it, and same signs don't collide
            if (stackTop > 0 && element < 0) 
            {
                while (!objStack.empty() && (objStack.back() > 0 && element < 0) && objStack.back() < abs(element)) 
                {
                    objStack.pop_back();
                }
                if (!objStack.empty() && (objStack.back() > 0 && element < 0)) 
                {
                    // otherwise we either destroyed it, but at the cost of our top element, or with no change
                    // either way, we don't add the element
                    bElementDestroyed = true;

                    if (objStack.back() == abs(element)) 
                    {
                        objStack.pop_back();
                    }
                }
            }
            if (!bElementDestroyed) 
            {
                objStack.push_back(element);
            }
        }
        while (!objStack.empty()) 
        {
            toReturn.push_back(objStack.front());
            objStack.pop_front();
        }
        return toReturn;
    }
};