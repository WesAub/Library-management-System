#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


// Book class structure

class Book {
    private: //attribute definitions 
        string bookName;
        string author_first;
        string author_last;
        string publisher;
        int year;
        string isbn;
        Book* next;
    
    public: //Behaviors Protoytype
        void addBook(Book*&, Book*&);
        void print_list(Book*);
        void delete_last(Book*&, Book*&);
        void deleteSpecific(Book*&, int position); 

};



// function to add new node to the link list
void Book::addBook(Book*& head, Book*& last) {
    // check empty link list
    if (head == NULL) {
        Book* temp = new Book;
        cout << "Enter Book Title : " << endl;
        cin >> temp->bookName;
        cout << "Enter Book Author First Name : " << endl;
        cin >> temp->author_first;
        cout << "Enter Book Author Last Name : " << endl;
        cin >> temp->author_last;
        cout << "Enter Publisher : "<< endl;
        cin >> temp-> publisher;
        cout << "Enter Book Published Year : " << endl;
        cin >> temp->year;
        cout << "Enter book ISBN"<< endl;
        cin>> temp-> isbn;
        temp->next = NULL;
        head = temp;
        last = temp;
    }
    else
        // continue link list
    {
        Book* temp1 = new Book;
        cout << "Enter Book Title : "<<endl;
        cin >> temp1->bookName;
        cout << "Enter Book Author First Name : " << endl;
        cin >> temp1->author_first;
        cout << "Enter Book Author Last Name : " << endl;
        cin >> temp1->author_last;
        cout << "Enter Publisher : "<<endl;
        cin >> temp1 ->publisher;
        cout << "Enter Book Published Year"<<endl;
        cin >> temp1->year;
        cout << "Enter ISBN: "<< endl;
        cin>> temp1 ->isbn;
        temp1->next = NULL;
        last->next = temp1;
        last = temp1;
    }
}


void Book::delete_last(Book*& head, Book*& last)
// delete head node
{
    if (head == NULL)
    {
        cout << " Empty List" << endl;
    }
    else if (head == last) {
        delete last;
        head = NULL;
        last = NULL;
    }
    else
    {
        Book* temp = last;
        last = last->next;
        delete temp;
    }
    
}


void Book::deleteSpecific(Book*& head, int position){
 Book* temp;
 Book* prev;
 temp = head;
 prev = head;

 for (int i =0; i < position; i++){
     if (i == 0 && position ==1){
         head = head-> next;
         free(temp);
     }else{
        if (i == position -1 && temp){
            prev->next = temp-> next;
        }else{
            prev = temp;
            //granted given position exceeds nuber of recods in the list
            //break out of loop
            if (prev == NULL){
                break;}
            temp = temp-> next;
         }
     }
 }
}

 
void Book::print_list(Book* in_root){
// Run through all nodes in the list and print

    Book* next_ptr;
    next_ptr = in_root;
    if (next_ptr == NULL)
    {
        cout << " Empty List" << endl;
    }
    else {
        while (next_ptr != NULL) {
            cout << next_ptr->bookName << endl;
            cout << next_ptr->author_first << endl;
            cout << next_ptr->author_last << endl;
            cout << next_ptr->publisher << endl;
            cout << next_ptr->year << endl;
            cout << next_ptr->isbn << endl;
            next_ptr = next_ptr->next;
        }
    }
    
}


int main() {
    Book* head = NULL;
    Book* last = NULL;

    char choice;
    // Menu Selection
    do {
        
        cout << "\nPress required option: " << endl;
        cout << "To Add Book detail" << '\t' << "[A]" << endl;
        cout << "To Print Book details" << '\t' << "[P]" << endl;
        cout << "To Delete Book details" << '\t' << "[D]" << endl;
        cout << "Quit Q" << '\t' << "[Q]" << endl;
        cin >> choice;

        choice = toupper(choice);

        switch (choice) {
            case 'A':
                head -> addBook(head, last);
                break;
            case 'P':
                head -> print_list(head);
                break;
            case 'D':
                int delOption;
                int nodePosition;
                cout<< "Enter 1 to delete the last node\n";
                cout<< "Enter 2 to delete a specific node\n";
                cin>> delOption;
                if (delOption == 1){
                    head -> delete_last(head, last);
                }else if (delOption == 2){
                    cout<< "Enter node position number\n";
                    cin>> nodePosition;
                    head -> deleteSpecific(head, nodePosition );
                }
                
                break;
            case 'Q':
                break;
            default:
                cout << "invalid choice" << endl;
        }
    } while (choice != 'Q');
    
    return 0;

}

