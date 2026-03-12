template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    // TODO
    this->maxSize = i;
    this->buffer = new T[maxSize]; 
    this->length = 0;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    // TODO
    delete[] buffer; //frees memory
    buffer = nullptr; //make sure buffer is not pointing to any stack/array
    this->length = 0; //reset length
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    // TODO
    this->maxSize = copyObj.maxSize; //assigning value
    this->length = copyObj.length; // assigning value

    this->buffer = new T[maxSize];
    int i;
    this->buffer[i] = copyObj.buffer[i];

    for(int newSize = 0; newSize < maxSize; ++newsize){
        buffer[newSize] = copyObj.buffer[newSize];
    }
    

}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    // TODO
    if (isEmpty()) throw string ("Stack is already empty. Nothing to peek at.");

    return buffer[this->length - 1];
}

template <typename T>
void ArrayStack<T>::pop() {
    // TODO
    if (isEmpty()) throw string("Stack is already empty. Nothing to pop.");

    --this->length; //just decrementing array size, don't actually need to delete

}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // TODO
    if (isFull()) throw string("Stack is full. Cannot push."); //if isFull() is true, throw error

    this->buffer[this->length] = elem;
    ++this->length;

}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO
    if (this->length < 2) return; // don't need to rotate if 0 or 1 elements

    if (dir == Stack<T>::RIGHT) {
    T temp = buffer[this->length - 1]; //saves top element into temp

    for (int i = this->length - 1; i > 0; --i){ //loop starts from top
        buffer[i] = buffer[i - 1];
    }
    buffer[0] = temp;
}

    if (dir == Stack<T>::LEFT) {
    T temp = buffer[0]; //saves bottom element

    for (int j = 0; j < this->length; ++j){ //loop starts from bottom
        buffer[j] = buffer[j+1];
    }
    buffer[this->length - 1] = temp; //puts temp at the top
}
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}
