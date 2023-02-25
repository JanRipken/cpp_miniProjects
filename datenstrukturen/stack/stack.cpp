#include <iostream>

template <typename T> class Stack {
private:
  int top;
  T data[100];

public:
  Stack() { top = -1; }

  void push(T value) {
    if (top >= 99) {
      std::cout << "Stack Overflow!" << std::endl;
      return;
    }
    data[++top] = value;
  }

  void pop() {
    if (top < 0) {
      std::cout << "Stack Underflow!" << std::endl;
      return;
    }
    top--;
  }

  T peek() {
    if (top < 0) {
      std::cout << "Stack Underflow!" << std::endl;
      return T();
    }
    return data[top];
  }

  bool isEmpty() { return top < 0; }

  bool isFull() { return top >= 99; }
};

int main() {
  Stack<int> myIntStack;
  myIntStack.push(10);
  myIntStack.push(20);
  myIntStack.push(30);
  std::cout << "Top Element: " << myIntStack.peek() << std::endl;
  myIntStack.pop();
  myIntStack.pop();
  std::cout << "Top Element: " << myIntStack.peek() << std::endl;
  myIntStack.pop();
  if (myIntStack.isEmpty()) {
    std::cout << "Einfach keine Zahl da!" << std::endl;
  } else {
    std::cout << "Eins Zahl ist hier drin " << std::endl;
  }

  Stack<std::string> myStringStack;
  myStringStack.push("Hallo");
  myStringStack.push("Keine");
  myStringStack.push("Welt");
  std::cout << "Top Element: " << myStringStack.peek() << std::endl;
  myStringStack.pop();
  std::cout << "Top Element: " << myStringStack.peek() << std::endl;
  myStringStack.pop();
  if (myStringStack.isEmpty()) {
    std::cout << "Ich sag dir garnichts!" << std::endl;
  } else {
    std::cout << "Ich könnte dir was sagen!" << std::endl;
  }

  return 0;
}
