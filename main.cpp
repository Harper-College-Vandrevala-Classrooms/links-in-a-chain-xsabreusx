#include <iostream>
#include <string>
using namespace std;

// This is the Provided ChainLink class
class ChainLink {
private:
    string color;

public:
    ChainLink(string color) {
        this->color = color;
    }

    string get_color() {
        return this->color;
    }
};

// The nodes point to the data and the next node
class Node {
private:
    ChainLink* data;
    Node* next;

public:
    Node(ChainLink* data) : data(data), next(nullptr) {}

    ChainLink* get_data() {
        return data;
    }

    Node* get_next() {
        return next;
    }

    void set_next(Node* next_node) {
        next = next_node;
    }
};

// LinkedList class to manage the chain of nodes
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current->get_next();
            delete current->get_data();
            delete current;
            current = temp;
        }
    }

    void append(ChainLink* link) {
        Node* new_node = new Node(link);

        if (head == nullptr) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->get_next() != nullptr) {
                current = current->get_next();
            }
            current->set_next(new_node);
        }
    }

    ChainLink* get(int index) {
        Node* current = head;
        int count = 0;

        while (current != nullptr) {
            if (count == index) {
                return current->get_data();
            }
            current = current->get_next();
            count++;
        }

        throw out_of_range("Index out of range");
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->get_data()->get_color() << " -> ";
            current = current->get_next();
        }
        cout << "nullptr" << endl;
    }
};

//////////////--- Driver ---//////////////
int main() {
    LinkedList list;

    // Adding ChainLink objects to the linked list
    cout << "\nAdding links: red, blue, green." << endl;
    list.append(new ChainLink("red"));
    list.append(new ChainLink("blue"));
    list.append(new ChainLink("green"));

    cout << "Contents of the linked list:" << endl;
    list.display();

    // Accessing elements by index
    try {
        cout << "Color at index 0: " << list.get(0)->get_color() << endl;
        cout << "Color at index 1: " << list.get(1)->get_color() << endl;
        cout << "Color at index 2: " << list.get(2)->get_color() << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    cout << "\nDemonstration completed. Good bye!";

    return 0;
}