#ifndef TODOAPP_H
#define TODOAPP_H

#include <string>
#include <vector>

class ToDoItem {
public:
  ToDoItem(const std::string &description);

  void markAsCompleted();
  void print() const;

private:
  std::string description;
  bool completed;
};

class ToDoList {
public:
  void addItem(const std::string &description);
  void markItemAsCompleted(int index);
  void printList() const;

private:
  std::vector<ToDoItem> items;
};

#endif
