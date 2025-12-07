#include <iostream>
using namespace std;

// ------------------ Singly Linked List ------------------

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(NULL) {}

    void insertHead(int v) {
        cout << "\n[INSERT HEAD] Creating node " << v << "\n";
        Node* n = new Node(v);
        n->next = head;
        head = n;
        cout << "Head updated to " << v << "\n";
    }

    void insertTail(int v) {
        cout << "\n[INSERT TAIL] Creating node " << v << "\n";
        Node* n = new Node(v);
        if (!head) {
            head = n;
            cout << "List empty, head = " << v << "\n";
            return;
        }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        cout << "Inserted at tail: " << v << "\n";
    }

    void deleteValue(int v) {
        cout << "\n[DELETE] Trying to delete " << v << "\n";
        if (!head) { cout << "List empty\n"; return; }
        if (head->data == v) {
            Node* t = head;
            head = head->next;
            delete t;
            cout << "Head deleted\n";
            return;
        }
        Node* c = head;
        while (c->next && c->next->data != v) c = c->next;
        if (!c->next) { cout << "Value not found\n"; return; }
        Node* t = c->next;
        c->next = t->next;
        delete t;
        cout << "Node deleted\n";
    }

    void search(int v) {
        cout << "\n[SEARCH] Searching " << v << "\n";
        Node* t = head;
        int pos = 1;
        while (t) {
            if (t->data == v) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            t = t->next;
            pos++;
        }
        cout << "Not found\n";
    }

    void display() {
        cout << "\n[DISPLAY] ";
        Node* t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
};

// ------------------ Doubly Linked List ------------------

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d) : data(d), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() : head(NULL) {}

    void insertTail(int v) {
        cout << "\n[DLL INSERT] Creating node " << v << "\n";
        DNode* n = new DNode(v);
        if (!head) {
            head = n;
            cout << "List empty, head = " << v << "\n";
            return;
        }
        DNode* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
        cout << "Inserted at DLL tail: " << v << "\n";
    }

    void displayForward() {
        cout << "\n[DLL FORWARD] ";
        DNode* t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }

    void displayBackward() {
        cout << "\n[DLL BACKWARD] ";
        if (!head) { cout << "EMPTY\n"; return; }
        DNode* t = head;
        while (t->next) t = t->next;
        while (t) {
            cout << t->data << " ";
            t = t->prev;
        }
        cout << "\n";
    }
};

// ------------------ MAIN PROGRAM ------------------

int main() {
    LinkedList L;
    DoublyLinkedList D;

    int ch, val;

    while (true) {
        cout << "\n--- Linked List Simulation Menu ---\n";
        cout << "1. Singly: Insert at head\n";
        cout << "2. Singly: Insert at tail\n";
        cout << "3. Singly: Delete a value\n";
        cout << "4. Singly: Search a value\n";
        cout << "5. Singly: Display list\n";
        cout << "6. Doubly: Insert at tail\n";
        cout << "7. Doubly: Display forward\n";
        cout << "8. Doubly: Display backward\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                L.insertHead(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                L.insertTail(val);
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                L.deleteValue(val);
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> val;
                L.search(val);
                break;

            case 5:
                L.display();
                break;

            case 6:
                cout << "Enter value: ";
                cin >> val;
                D.insertTail(val);
                break;

            case 7:
                D.displayForward();
                break;

            case 8:
                D.displayBackward();
                break;

            case 9:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
