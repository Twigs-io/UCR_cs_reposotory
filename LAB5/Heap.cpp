#include "Heap.h"

using namespace std;

Heap::Heap() {
    numItems = 0;
}

void Heap::enqueue(PrintJob* J) {
    if (MAX_HEAP_SIZE > numItems) {
        arr[numItems] = J;
        int nI = numItems;
        while (nI > 0) {
            int pI = (nI - 1) / 2;
            if (arr[nI]->getPriority() <= arr[pI]->getPriority()) {
                numItems++;
                return;
            }
            else {
                swap(arr[nI], arr[pI]);
                nI = pI;
            }   
        }
        numItems++;
    }
}

void Heap::dequeue() {
    if (numItems > 1) {
        arr[0] = arr[numItems - 1];
        numItems--;
        trickleDown(0);
    }
    else if (numItems == 1) {
        numItems--;
    }
    else {
        return;
    }
}

void Heap::trickleDown(int d) /*x will initially be 0*/ {
    int cI = 2 * d + 1;
    int val = arr[d]->getPriority();
    int maxVal;
    int maxI;
    while (cI < numItems) {
        maxVal = val;
        maxI = -1;
        for (int i = 0; i < 2 && i + cI < numItems; ++i) {
            if (arr[i + cI]->getPriority() > maxVal) {
                maxVal = arr[i + cI]->getPriority();
                maxI = i + cI;
            }
        }
        if (maxVal == val) {
            return;
        }
        else {
            swap(arr[d], arr[maxI]);
            d = maxI;
            cI = 2 * d + 1;
        }
    }
}

PrintJob* Heap::highest() {
    if (numItems > 0) {
        return arr[0];
    }
    else {
        return 0;
    }
}

void Heap::print() {
    if (numItems != 0) {
        cout << "Priority: " << this->highest()->getPriority() << ", Job Number: " << this->highest()->getJobNumber() << ", Number of Pages: " << this->highest()->getPages() << endl;
    }
    else {
        return;
    }
}