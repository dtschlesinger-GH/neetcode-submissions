#include <algorithm>
class DynamicArray {
public:

    // Compiler handles allocation to the nearest Pow2, so I shouldn't have to manually track for that, but ask interviewer anyway
    const static int INDEX_NONE = -1;
    int ElementCount = 0;
    int ArrayCapacity = 0;
    int* CurrentArray = nullptr;

    DynamicArray(int capacity) {
        ArrayCapacity = capacity;
        if (CurrentArray != nullptr) 
        {
            delete CurrentArray;
        }
        CurrentArray = new int[capacity];
    }

    int get(int i) {
        if (i < 0 || i > ElementCount) 
        {
            return INDEX_NONE;
        }
        if (CurrentArray != nullptr) 
        {
            return CurrentArray[i];
        }
        return INDEX_NONE;
    }

    void set(int i, int n) {
        if (i < 0 || i > ElementCount) 
        {
            return;
        }
        if (CurrentArray != nullptr) 
        {
            CurrentArray[i] = n;
        }
    }

    void pushback(int n) {
        // Can cause resize
        if (ElementCount >= ArrayCapacity) 
        {
            resize();
        }
        CurrentArray[ElementCount] = n;
        ElementCount++;
    }

    int popback() {
        // Don't resize when we do this, we don't want to thrash unnecessarily
        if (ElementCount > 0) 
        {
            ElementCount--;
            const int& ToReturn = CurrentArray[ElementCount];
            return ToReturn;
        }
        return INDEX_NONE;
    }

    void resize() {
        const int* ToCopy = CurrentArray;
        ArrayCapacity *= 2;
        CurrentArray = new int[ArrayCapacity];
        std::copy(ToCopy, ToCopy + ElementCount, CurrentArray);
    }

    int getSize() {
        return ElementCount;
    }

    int getCapacity() {
        return ArrayCapacity;
    }
};
