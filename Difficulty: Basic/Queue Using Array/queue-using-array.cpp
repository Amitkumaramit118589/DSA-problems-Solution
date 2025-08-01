/*

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

// Function to push an element x in a queue.
void MyQueue ::push(int x) {
    arr[rear++] = x; // insert at rear, then increment rear
}

int MyQueue ::pop() {
    if (front == rear) return -1; // queue is empty
    return arr[front++];          // return front element and increment front
}

