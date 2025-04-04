#include <bits/stdc++.h>
using namespace std;

// Array Implementation
#define MAX 1000

class Stack {
  int top;

 public:
  int a[MAX];
  Stack() { top = -1; }
  bool push(int x);
  int pop();
  int peek();
  bool isEmpty();
};

bool Stack::push(int x) {
  if (top >= (MAX - 1)) {
    cout << "Stack Overflow";
    return false;
  } 
  else {
    a[top++] = x;
    cout << x << " pushed into stack\n";
    return true;
  }
}

int Stack::pop() {
  if (top < 0) {
    cout << "Stack Underflow";
    return 0;
  } 
  else {
    int x = a[top--];
    return x;
  }
}

int Stack::peek() {
  if (top < 0) {
    cout << "Stack is Empty";
    return 0;
  } 
  else {
    int x = a[top];
    return x;
  }
}

bool Stack::isEmpty() { 
    return (top < 0); 
}