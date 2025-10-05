#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct review
{
    double rating;
    string comment;
    review* next;

};

// protos
void addHead(review*& head, double rating, const string& comment);
void addTail(review*& head, double rating, const string& comment);
void displayReviews(review* head);
void deleteList(review* head);

int main()
{
    int choice;
    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list" << endl;
    cout << "\t[2] New nodes are added at the tail of the linked list" << endl;
    cout << "Choice: ";
    cin >> choice;

    review* head = nullptr; // start with empty list

    char again = 'y'; // for second review
    while (again == 'y' || again == 'Y')
    {
        double rating;
        string comment;

        cout << "Enter review rating 0-5: ";
        cin >> rating;

        cin.ignore(); // clear buffer

        cout << "Enter review comments: ";
        getline(cin, comment);

        if (choice == 1)
            addHead(head, rating, comment);
        else
            addTail(head, rating, comment);

        
        cout << "Enter another review? Y/N";
        cin >> again;

        cin.ignore(); // clear input buffer
    }

    displayReviews(head);

    deleteList(head); // free memory


}


// new head node
void addHead(review*& head, double rating, const string& comment)
{
    review* newNode = new review{rating, comment, head}; // create new head node
    head = newNode; // update head


}


// new tail node
void addTail(review*& head, double rating, const string& comment)
{
    review* newNode = new review{rating, comment, nullptr};


    if (!head)
    {
        // check if empty linked list
        head = newNode;
    }
    else
    {
        // walk to end and attach new node;
        review* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// find avg and display
void displayReviews(review* head)
{
    int count = 0;
    double sum = 0;

    cout << "Outputting all reviews:" << endl;

    for (review* cur = head; cur; cur = cur->next)
    {
        cout << "\tReview #" << count + 1 << ": " << cur->rating << ": " << cur->comment << endl;
        sum += cur->rating;
        count++;
    }

    if (count)
    {
        cout << "\tAverage: " << fixed << setprecision(5) << sum/count << "\n";
    }
    else
    {
        cout << "\tNo reviews." << endl;
    }
}

// free memory after finished
void deleteList(review* head)
{
    while (head)
    {
        review* temp = head;
        head = head->next;
        delete temp; // free mem
    }
}
