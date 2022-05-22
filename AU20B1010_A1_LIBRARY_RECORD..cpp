#include <iostream>
using namespace std;

struct Node
{
    int unique_id;
    int category;
    Node *next;
};

Node *head = new Node();

bool record_existence(int x)
{
    if (head == NULL)
        return false;

    Node *t = new Node;
    t = head;

    while (t != NULL)
    {
        if (t->unique_id == x)
            return true;
        t = t->next;
    }

    return false;
}

void Insert_Record(int unique_id, int category)
{
    if (record_existence(unique_id))
    {
        cout << "Student with this "
             << "record Already Exists\n";
        return;
    }

    Node *t = new Node();
    t->unique_id = unique_id;
    t->category = category;
    t->next = NULL;

    if (head == NULL || (head->unique_id >= t->unique_id))
    {
        t->next = head;
        head = t;
    }

    else
    {
        Node *c = head;
        while (c->next != NULL && c->next->unique_id < t->unique_id)
        {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }

    cout << "Record Inserted Successfully\n";
}

void Search_Record()
{
    int id;
    int search_option;
    // if head is NULL
    if (!head)
    {
        cout << "The Library doesn't contain any book yet\n";
    }
    else
    {
        Node *temp = head;

        cout << "How do you want to Search \n 1.\tVia Book Id\n2.\tVia category\n";
        cin >> search_option;

        if (search_option == 1)
        {

            while (temp)
            {
                cout << "Enter Unique Id of book \n";
                cin >> id;
                if (temp->unique_id == id)
                {
                    cout << "Book Id\t" << temp->unique_id << endl;
                    cout << "Belongs to\t" << temp->category << endl;
                }
                temp = temp->next;
            }
        }

        else if (search_option == 2)
        {
            cout << "Enter Unique Id of book category \n";
            cin >> id;
            while (temp)
            {
                if (temp->category == id)
                {
                    cout << "Book Id\t" << temp->unique_id << endl;
                    cout << "Belongs to\t" << temp->category << endl;
                }
                temp = temp->next;
            }
        }
    }
}

int Delete_Record(int unique_id)
{
    Node *t = head;
    Node *temp = NULL;

    if (t != NULL && t->unique_id == unique_id)
    {
        head = t->next;
        delete t;

        cout << "Record Deleted Successfully\n";
        return 0;
    }

    while (t != NULL && t->unique_id != unique_id)
    {
        temp = t;
        t = t->next;
    }
    if (t == NULL)
    {
        cout << "Record does not Exist\n";
        return -1;
        temp->next = t->next;

        delete t;
        cout << "Record Deleted "
             << "Successfully\n";
        return 0;
    }
    return 0;
}

void Show_Record()
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "No Record "
             << "Available\n";
    }
    else
    {
        cout << "Book Id\tBook Category\n";

        while (temp != NULL)
        {
            cout << temp->unique_id << "\t";
            cout << temp->category << endl;
            temp = temp->next;
        }
    }
}

void Show_Category()
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "No Record Available\n";
    }
    else
    {
        cout << "\n\t\tBook Category\n\n";

        while (temp != NULL)
        {
            // cout << temp->unique_id << "\t";
            cout << temp->category << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    head = NULL;
    int unique_id;
    int category_id;
    bool done = true;
    while (done == true)
    {
        cout << "\n\t\tWelcome to Avantika Library\n\nPress\n1 to insert a new book\n2 to delete a Book \n3 to Search a Book Record\n4 to view all Books Record\n5 to view all Book Categories\n6 to Exit\n";
        cout << "\nEnter your Choice\n";
        int Choice;

        cin >> Choice;
        if (Choice == 1)
        {
            cout << "Enter Unique Id of new book \n";
            cin >> unique_id;
            cout << "Enter Unique Id for book category \n";
            cin >> category_id;
            Insert_Record(unique_id, category_id);
        }
        else if (Choice == 2)
        {
            cout << "Enter Unique Id of book to be deleted \n";
            cin >> unique_id;
            Delete_Record(unique_id);
        }
        else if (Choice == 3)
        {
            Search_Record();
        }
        else if (Choice == 4)
        {
            Show_Record();
        }
        else if (Choice == 5)
        {
            Show_Category();
        }
        else if (Choice == 6)
        {
            done = false;
        }
        else
        {
            cout << "Invalid Choice Try Again\n";
        }
    }
    return 0;
}