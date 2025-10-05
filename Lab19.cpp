#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

// seperate line by commas to get each value
#include <sstream>


using namespace std;

struct review
{
    double rating;
    string comment;
    review* next;

};


// store everything in a class to make multiple movie objects
class Movie
{
    private:
        string title;
        review* head;

    public:
        // constructor
        Movie (const string& t) :  title(t), head(nullptr) {}

        ~Movie()
        {
            review* curr = head;
            while (curr)
            {
                review* temp = curr;
                curr = curr->next;
                delete temp; // free mem
            }// free mem
        }

        string getTitle() const {return title;}

        void addHead(review*& head, double rating, const string& comment)
        {
            review* newNode = new review{rating, comment, head}; // create new head node
            head = newNode; // update head
        }

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








};



int main()
{
    vector<Movie> movies;

    ifstream fin("movies.txt");
    if (!fin)
    {
        cerr << "Error" << endl;
        return 0;
    }

    string movie;
    while (getline(fin, movie))
    {
        if (movie.empty()) {continue;}
        string title, comment;
        double rating;

        


    }


}

