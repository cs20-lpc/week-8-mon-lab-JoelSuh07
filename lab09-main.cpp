#include <iostream>
#include <string>
#include "ArrayStack.hpp"

using namespace std;

// Helper function template to handle the Direction enum
template <typename T>
void testRotate(ArrayStack<T>& s, typename Stack<T>::Direction dir) {
    s.rotate(dir);
}

int main() {
    try {
        // 1. Create a stack of integers with a max size of 5
        ArrayStack<int> myStack(5);

        // 2. Push some data
        cout << "Pushing 10, 20, 30, 40..." << endl;
        myStack.push(10);
        myStack.push(20);
        myStack.push(30);
        myStack.push(40);

        // 3. Display the initial stack
        cout << "\nInitial Stack:" << endl;
        cout << myStack;

        // 4. Test RIGHT Rotation (Top to Bottom)
        cout << "\nRotating RIGHT (Top moves to Bottom):" << endl;
        testRotate(myStack, Stack<int>::RIGHT);
        cout << myStack;

        // 5. Test LEFT Rotation (Bottom to Top)
        cout << "\nRotating LEFT (Bottom moves to Top):" << endl;
        testRotate(myStack, Stack<int>::LEFT);
        cout << myStack;

        // 6. Test Exceptions (Pop until empty, then one more)
        cout << "\nTesting Pop and Exceptions:" << endl;
        while (!myStack.isEmpty()) {
            cout << "Popping: " << myStack.peek() << endl;
            myStack.pop();
        }
        
        // This should trigger the string exception you wrote
        myStack.pop(); 

    } catch (string e) {
        cout << "Caught Error: " << e << endl;
    }

    return 0;
}
