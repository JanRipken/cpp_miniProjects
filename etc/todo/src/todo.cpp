#include "../header/todo.hpp"
#include <iostream>

ToDoItem::ToDoItem(const std::string &description)
    : description(description), completed(false) {}

void ToDoItem::markAsCompleted() { completed = true; }

void ToDoItem::print() const {
  std::cout << "[" << (completed ? "X" : " ") << "] " << description
            << std::endl;
}

void ToDoList::addItem(const std::string &description) {
  ToDoItem newItem(description);
  items.push_back(newItem);
}

void ToDoList::markItemAsCompleted(int index) {
  if (index >= 0 && index < items.size()) {
    items[index].markAsCompleted();
  }
}

void ToDoList::printList() const {
  for (const auto &item : items) {
    item.print();
  }
}
