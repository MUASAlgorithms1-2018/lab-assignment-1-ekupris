#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

int main() {

    // functions
    int cubicSum(vector<int> array);
    int quadraticSum(vector<int> array);
    int linearSum(vector<int> array);

    // arrays/vectors
    static const vector<int> array1 = {5, -17, 12, 5, -10, 6, 4, 8, -5, -10, -17, 22, 1};
    static const vector<int> array2 = {7, 5, -11, 2, -15, 10};
    static const vector<int> array3 = {5, 8, -11, 6, -9, 2};
    static const vector<int> array4 = {10, -8, 9};
    static const vector<int> array5 = {5, -5, 5, -5, 5, -5};

    // tests
    assert(cubicSum(array1) == 25);
    assert(cubicSum(array2) == 12);
    assert(cubicSum(array3) == 13);
    assert(cubicSum(array4) == 11);
    assert(cubicSum(array5) == 5);
    assert(quadraticSum(array1) == 25);
    assert(quadraticSum(array2) == 12);
    assert(quadraticSum(array3) == 13);
    assert(quadraticSum(array4) == 11);
    assert(quadraticSum(array5) == 5);
    assert(linearSum(array1) == 25);
    assert(linearSum(array2) == 12);
    assert(linearSum(array3) == 13);
    assert(linearSum(array4) == 11);
    assert(linearSum(array5) == 5);
    cout << "All tests completed!" << endl;
    return 0;
}

int cubicSum(vector<int> array) {
    int maxSum = 0;
    for(int i = 0; i < array.size(); i++) {
        for(int j = i; j < array.size(); j++) {
            int thisSum = 0;
            for(int k = i; k <= j; k++) {
                thisSum += array[k];
                if(thisSum > maxSum)
                    maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

int quadraticSum(vector<int> array) {
    int maxSum = 0;
    for(int i = 0; i < array.size(); i++) {
        int thisSum = 0;
        for(int j = i; j < array.size(); j++) {
            thisSum += array[j];
            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

int linearSum(vector<int> array) {
    int maxSum = 0;
    int thisSum = 0;
    for(int i = 0; i < array.size(); i++) {
        thisSum += array[i];
        if(thisSum > maxSum)
            maxSum = thisSum;
        else if(thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}
