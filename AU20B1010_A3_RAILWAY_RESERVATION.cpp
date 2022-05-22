#include <iostream>
using namespace std;

int n = 9;
int arr[10];
int waiting[10];

int supportive_hash(int value)
{
    int prime = 7;
    int result = prime - (value % prime);
    return result;
}

int mod(int value)
{
    int result = value % n;
    return result;
}

int hashtag(int key)
{
    /*--> A function to maintain the seats of new pessenger */
    int result = 0;
    int j = 0;
    bool temp = false;
    bool done = false;
    for (int i = 0; i < n; i++)
    {
        result = (mod(key) + (i * supportive_hash(key))) % n;
        if (arr[result] == 0)
        {
            arr[result] = key;
            break;
        }
        else
        {
            for (int k = 0; k <= n; k++)
            {
                if (arr[k] == 0)
                {
                    break;
                }
                else
                {
                    temp = true;
                }
                if (arr[i] != 0 && temp == true && waiting[k] == 0)
                {
                    waiting[k] = key;
                    done = true;
                    break;
                }
                if (done == true)
                {
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "seat_no --> " << i << "\t";
        cout << "Passenger Seat No --> " << arr[i] << " " << endl;
    }
    return result;
}

void search_seat_no(int seat_no)
{
    /*A function to search user using his seat no */
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == seat_no)
        {
            cout << "Seat No --> " << i << endl;
            cout << "Your aadhar no is **** **** **" << arr[i] << endl;
            break;
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (waiting[j] == seat_no)
                {
                    cout << "you are in waiting list WL" << j;
                }
            }
        }
    }
}

void waiting_list()
{
    /*A function to print the waiting list of the user*/
    cout << "Below is the waiting list\n kindly find your adhar id here --> " << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << "**** **** **" << waiting[i] << endl;
    }
}

void search_passenger(string p_name)
{
    /*Searching the user using his name*/

    // for(int i=0; i<n; i++){
    //     if (arr[i] == p_name){
    //         cout<<arr[i];
    //         break;
    //     }
    // }
}

void cancel_ticket(int seat_no)
{
    /*A function to cancel the seat of the user using his seat no*/
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == seat_no)
        {
            if (waiting != 0)
            {
                arr[i] = waiting[0];
            }
            else
            {
                arr[i] = 0;
            }
            cout << "Your ticket is cancelled" << endl;
        }
    }
}

int main()
{
    int option = 0;
    int sub_option = 0;
    bool done = false;
    cout << "\n\n\t\t\t\tWelcome To Indian Railway\n\n\n";
    while (done == false)
    {
        cout << "\nKindly enter your desired option \n\n";
        cout << "1. Book Ticket\n";
        cout << "2. Search your Seat\n";
        cout << "3. Cancel Your Reservation\n";
        cout << "4. To Exit\n";
        cout << "You are pressing option no. - ";
        cin >> option;
        cout << "\n\n";

        if (option == 1)
        {
            int data = 0;
            cout << "Enter your last 2 digit of your aadhar card --> ";
            cin >> data;
            int a = hashtag(data);
        }

        else if (option == 2)
        {
            cout << "How do you want to search your seat" << endl;
            cout << "\t1. Via Seat No." << endl;
            cout << "\t2. Via Passenger Name" << endl;
            cin >> sub_option;
            if (sub_option == 1)
            {
                int search = 0;
                cout << "Enter your Seat No. --> ";
                cin >> search;
                search_seat_no(search);
            }
            else if (sub_option == 2)
            {
                string search;
                cout << "Enter Passenger No. --> ";
                cin >> search;
                search_passenger(search);
            }
            else
            {
                cout << "\nkindly enter an appropriate option";
            }
        }
        else if (option == 3)
        {
            int cancel = 0;
            cout << "Enter your Seat No. --> ";
            cin >> cancel;
            cancel_ticket(cancel);
        }
        else if (option == 4)
        {
            break;
        }
        else if (option == 5)
        {
            waiting_list();
        }
        else if (option == 6)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "seat_no --> " << i << "\t";
                cout << "Passenger Seat No --> " << arr[i] << " " << endl;
            }
        }
    }
    return 0;
}
