// Constructor
template <typename T>
ArrayList<T>::ArrayList(int i) {
    if (i <= 0) throw string("constructor: size must be positive");
    this->length = 0;
    this->maxSize = i;
    this->buffer = new T[this->maxSize];
}

// Copy constructor
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other) {
    this->copy(other);
}

// Assignment operator
template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other) {
    if (this != &other) {
        delete[] this->buffer;
        this->copy(other);
    }
    return *this;
}

// Destructor
template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] this->buffer;
}

// Copy helper
template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& other) {
    this->maxSize = other.maxSize;
    this->length = other.length;
    this->buffer = new T[this->maxSize];
    for (int i = 0; i < this->length; i++)
        this->buffer[i] = other.buffer[i];
}

// Clear
template <typename T>
void ArrayList<T>::clear() {
    delete[] this->buffer;
    this->buffer = new T[this->maxSize];
    this->length = 0;
}

// Append
template <typename T>
void ArrayList<T>::append(const T& elem) {
    if (isFull()) throw string("append: list is full");
    this->buffer[this->length++] = elem;
}

// Get element
template <typename T>
T ArrayList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length)
        throw string("getElement: out of bounds");
    return this->buffer[position];
}

// Insert
template <typename T>
void ArrayList<T>::insert(int position, const T& elem) {
    if (isFull()) throw string("insert: list is full");
    if (position < 0 || position > this->length)
        throw string("insert: out of bounds");
    for (int i = this->length; i > position; i--)
        this->buffer[i] = this->buffer[i - 1];
    this->buffer[position] = elem;
    this->length++;
}

// Remove
template <typename T>
void ArrayList<T>::remove(int position) {
    if (position < 0 || position >= this->length)
        throw string("remove: out of bounds");
    for (int i = position; i < this->length - 1; i++)
        this->buffer[i] = this->buffer[i + 1];
    this->length--;
}

// Replace
template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length)
        throw string("replace: out of bounds");
    this->buffer[position] = elem;
}

// Getters
template <typename T>
int ArrayList<T>::getLength() const { return this->length; }

template <typename T>
int ArrayList<T>::getMaxSize() const { return this->maxSize; }

// Check empty/full
template <typename T>
bool ArrayList<T>::isEmpty() const { return this->length == 0; }

template <typename T>
bool ArrayList<T>::isFull() const { return this->length == this->maxSize; }

// Stream operator
template <typename U>
ostream& operator<<(ostream& os, const ArrayList<U>& list) {
    os << "[";
    for (int i = 0; i < list.length; i++) {
        os << list.buffer[i];
        if (i < list.length - 1) os << ", ";
    }
    os << "]\n";
    return os;
}
