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
void insert();



int main() {

  List* list = new List;

  createNode(list, "Labas");
  createNode(list, "Krabas");
  createNode(list, "Visogero");
  insertFront(list, "As esu pirmas Elementas");
  insertFront(list, "As esu pirmesnis Elementas");
  displayList(list->head);

  delete list;


  return 0;
}
