#include <iostream>
using namespace std;

int n = 5;
void dash(){
    cout<<"  ";
    for (int i = 0; i < 18; i++)
    {
        cout<<"-";
    }
    cout<<endl;
    
}
void print_array(int arr1[], int arr2[]){
    dash();
    for (int i = 0; i<n; i++){
        cout<<" | "<<arr1[i]<<"\t-->\t"<<arr2[i]<<" | "<<endl;
    }
    dash();
    cout<<"\n";
}

void swap(int id[], int sal[], int i, int j){
    int temp1 = id[i];
    int temp2 = sal[i];
    id[i] = id[j];
    sal[i] = sal[j];
    id[j] = temp1;
    sal[j] = temp2;
}

/*Quick Sort Begin*/
int partition (int empId[], int salary[], int low, int high){
    int pivot = salary[low];
    int i = low;
    int j = high;

    while (i<j)
    {
        do
        {
            i++;
        } while (salary[i]>=pivot);
        
        do
        {
            j--;
        } while (salary[j]<pivot);

        if (i<j){
            swap(empId,salary, i, j);
        }
        
    }
    swap(empId,salary, low, j);
    return j;
}

void quick(int empId[], int salary[], int low, int high){
    int j;

    if(low<high){
        j = partition(empId, salary, low, high);
        quick(empId, salary, low, j);
        quick(empId, salary, j+1, high);
    }
}

/*Quick Sort End*/
/***************************************************************/
/*Merge Sort Begins*/
void merge(int empId[], int salary[], int m, int n, int mid){
    int i = 0;
    int j = mid+1;
    int k= 0;
    int temp_sal[6];
    int temp_id[6];
    while (i<=mid && j<=n)
    {
        if (salary[i]>salary[j])
        {
            temp_sal[k] = salary[i];
            temp_id[k] = empId[i];
            k++;
            i++;
        }

        else{
            temp_sal[k] = salary[j];
            temp_id[k] = empId[j];
            k++;
            j++;
        }
    }
    for(; i<=mid; i++){
        temp_sal[k] = salary[i];
        temp_id[k] = empId[i];
        k++;
    }
    for(; j<=n; j++){
        temp_sal[k] = salary[j];
        temp_id[k] = empId[j];
        k++;
    }
    for (i = 0; i < k; i++)  {
    // cout<<"k - "<<k<<endl;
        salary[i] = temp_sal[i];
        temp_id[i] = empId[i];
    }
}

void merge_sort(int empId[], int salary[], int l, int h){
    int mid;
    if(l<h){
        mid = (l+h)/2;
        merge_sort(empId, salary, l, mid);
        merge_sort(empId, salary, mid+1, h);
        merge(empId, salary, l, h, mid);
    }
}
/*Merge Sort Ends*/

/*Selection Sort Begins*/
void Selection(int empId[], int salary[]){
    int min;
    for (int i = 0; i<n-1; i++){
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if(salary[j]>salary[min]){
                min = j;
            }
        }
        swap(empId,salary, i, min);
    }
    print_array(empId, salary);
}
/*Selection Sort Ends*/


/*Bubble Sort Begins*/
void Bubble(int empId[], int salary[]){
    for (int i = 0; i<n-1; i++){
        for (int j = 0; j < n-1-i; j++)
        {
            if(salary[j]<salary[j+1]){
                swap(empId, salary, j, j+1);
            }
        }
        if(salary[i-1]==salary[i]){
                swap(empId, salary, i, i-1);
            }
    }
    print_array(empId, salary);
}
/*Bubble Sort Ends*/

int main(){
    cout<<"Enter the size of your array you want to sort - "<<endl;
    cin>>n;
    int empId[n];
    int Salary[n];
    int id, sal, j= 0;
    int low = 0;
    int high = n;

    while (true){
        cout<<"Enter Employee Id \n{Press 0 and enter when Finish up adding the elements} \n --> ";
        cin>>id;
        cout<<"\nEnter salary of Employee \n --> ";
        cin>>id;
        cout<<endl;

        empId[j] = id;
        Salary[j] = sal;
        j++;
        if(id == 0 || j == n){
            break;
        }
    }

    cout<<"Normal Array"<<endl;
    print_array(empId, Salary);

    quick(empId, Salary, low, high);
    cout<<"Quick Sort"<<endl;
    print_array(empId, Salary);

    cout<<"Selection Sort"<<endl;
    Selection(empId, Salary);

    cout<<"Bubble Sort"<<endl;
    Bubble(empId, Salary);

    cout<<"Merge Sort"<<endl;
    merge_sort(empId, Salary, 0, 4);
    print_array(empId, Salary);
}