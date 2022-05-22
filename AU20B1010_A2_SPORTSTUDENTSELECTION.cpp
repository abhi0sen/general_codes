#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>

using namespace std;
int n = 20;
class test_search
{
    char name[100];
    float height = 0;
    char id[10];
    int ar_size;

public:
    void stu_height(float h){
        height = h;
    }

    void student_name(char *n){
        strcpy(name, n);
    }
    void stu_id(char *m){
        strcpy(id, m);
        // ar_size++;
    }
    float ret_height(){
        return height;
    }
    int ret_ar_size(){
        return ar_size;
    }
    string ret_name(){
        return name;
    }
    string ret_id(){
        return id;
    }
    void GetRecord()
    {
        cout << " Student Enroll - \t\t" << id;
        cout << " Student Name - \t\t" << name;
        cout << " Student Height - \t\t" << height << endl;
    }
};

void data_storage(){
    char name[100];
    char id[20];
    float height;

    test_search ts;

    cout << "Enter your enrollment id: " << endl;
    cin >> id;
    cout << "Enter your name: " << endl;
    cin >> name;
    cout << "Enter your exact height " << endl;
    cin >> height;
    
    ts.student_name(name);
    ts.stu_id(id);
    ts.stu_height(height);

    ofstream out("data.txt", ios:: out | ios::app);
    out.write((char *)&ts, sizeof(test_search));
    out.close();
}

void display(string names[], float heights[], string ids[])
{
    int j = 0;
    test_search ts;
    ifstream inf("data.txt", ios::in);
    cout << "\n\nDisplaying record\n";
    while (!inf.eof())
    {
        inf.read((char *)&ts, sizeof(test_search));
        if (ts.ret_height() >= 5)
        {
            names[j] = ts.ret_name();
            heights[j] = ts.ret_height();
            ids[j] = ts.ret_id();
            j++;
        }
    }
    inf.close();
    for(int i = 0; i<20; i++){
        cout<<"Student's Id -> "<<ids[i]<<" "<<endl;
        cout<<"Name of the student -> "<<names[i]<<" "<<endl;
        cout<<"Height of the student -> "<<heights[i]<<" "<<endl<<endl;
    }
}

void selected_height_sorting(string names[], float heights[], string ids[]){
        int key, i;
        string id;
        string na;
    for (int j = 1; j<n; j++){
        key = heights[j];
        id = ids[j];
        na = names[j];
        i = j-1;
        while (i>=0 && heights[i] > key)
        {
            heights[i+1] = heights[i];
            names[i+1] = names[i];
            ids[i+1] = ids[i];
            i=i-1;
        }
        heights[i+1] = key;
        ids[i+1] = id;
        names[i+1] = na;
    }
}

int get_user(string ids[], string names[], float heights[], string i){
    /*Searching the particular user with */
    selected_height_sorting(names, heights, ids);
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if (i == ids[mid]){
            cout<<"Student's Id -> "<<ids[mid]<<" "<<endl;
            cout<<"Name of the student -> "<<names[mid]<<" "<<endl;
            cout<<"Height of the student -> "<<heights[mid]<<" "<<endl<<endl;
            return mid;
        }
        else if (i<ids[mid]){
            high = mid-1;
        }
        else if (i>ids[mid]){
            low = mid+1;
        }
    }
}

int main(){
    int option = 0;
    string names[n];
    float heights[n];
    string ids[n];

    while (true)
    {
    cout<<"Choose From The Following The Options - "<<endl;
    cout<<"1. Register new Student"<<endl;
    cout<<"2. Display List of All the members with required height"<<endl;
    cout<<"3. Search for a student using his id "<<endl;
    cout<<"4. Exit "<<endl;

    cout<<"Press 1,2,3"<<endl;
    cin>>option;

    if (option == 1)
    {
        data_storage();
    }
    
    else if (option == 2)
    {
        display(names, heights, ids);
    }
    else if(option == 3){
        string i;
        cout<<"Please enter the id of the student - ";
        cin>>i;
        get_user(ids, names, heights, i);
    }
    else if(option == 4){
        break;
    }
    else{
        cout<<"!!Please Enter the appropriate Option!!";
    }
    }
}
