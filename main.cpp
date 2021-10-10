#include <iostream>
#include <utility>

using namespace std;

struct Node{
  string data;
  Node* next{};
};
struct List{
  Node* head = nullptr;
  Node* tail = nullptr;
};

void displayList(Node* head){
  while (head != nullptr){
    cout << head->data << endl;
    head = head->next;
  }
}

void createNode(List* list, const string& value){
  Node* temp = new Node;
  temp->data = value;
  temp->next = nullptr;

  if(list->head == nullptr){
    list->head = temp;
    list->tail = temp;
  }else{
    list->tail->next = temp;
    list->tail = temp;
  }

}

void insertFront(List* list, const string& value){
  Node* temp = new Node;
  temp->data = value;
  temp->next = list->head;
  list->head = temp;
}
void insertByPos(List* list, int position, const string& value){
  Node* previous = new Node;
  Node* current = new Node;
  Node* temp = new Node;
  current = list->head;
  for(int i=1; i < position; i++){
    previous = current;
    current = current->next;
  }
  temp->data = value;
  previous->next = temp;
  temp->next = current;
}

void deleteFront(List* list){
  Node* temp = new Node;
  temp = list->head;
  list->head = list->head->next;
  delete temp;
}
void deleteEnd(List* list){
  Node* current = new Node;
  Node* previous = new Node;
  current = list->head;
  while (current->next != nullptr){
    previous = current;
    current = current->next;
  }
  list->tail = previous;
  previous->next = nullptr;
  delete current;
}
void deleteByPos(List* list, int position){
  Node* current = new Node;
  Node* previous = new Node;
  current = list->head;
  for (int i = 1; i < position; i++) {
    previous = current;
    current = current->next;
  }
  previous->next = current->next;
}




int main() {

  List* list = new List;

  createNode(list, "Labas");
  createNode(list, "Krabas");
  createNode(list, "Visogero");
  insertFront(list, "As esu pirmas Elementas");
  insertFront(list, "As esu pirmesnis Elementas");
  insertByPos(list, 2, "Pagal pozicija : 2");


  deleteByPos(list, 6);

  deleteEnd(list);

  deleteFront(list);

  displayList(list->head);




  return 0;
}
