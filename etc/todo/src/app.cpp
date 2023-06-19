#include "todo.cpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  ToDoList myList;

  myList.addItem("Buy groceries");
  myList.addItem("Do laundry");
  myList.addItem("Clean the house");

  myList.markItemAsCompleted(0);
  myList.printList();
  return 0;
}
