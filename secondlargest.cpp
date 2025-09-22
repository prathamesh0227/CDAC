#include <iostream>

using namespace std;

int main(){
    int n;
    cout <<"Enter size of Array: ";
    cin>>n;

    if (n<2)
    {
        cout<<"Invalid size of array:"<< endl;
        return 1;
    }
    
    int elements[n];
    cout<<"Enter "<<n<<" elements to find the second largest number: \n";
    for (int i = 0; i < n; ++i)
    {
        cin>>elements[i];
    }
// Initialize 2 elements to compare largest and secondLargest
    int largest , secondLargest;
    if (elements[0]>elements[1])
    {
        largest = elements[0];
        secondLargest = elements[1];
    }
//Process to run loop for 'n' number of elements
    for (int i = 2; i < n; i++)
    {
        if (elements[i]>largest){
            secondLargest=largest;
            largest=elements[i];
        } else if (elements[i] > secondLargest && elements[i] != largest)
        {
        secondLargest = elements[i];
        }
    }
    if (largest == secondLargest) 
    {
        cout<< "Error: All elements same /No second largest element found"<< endl;
    }
    else {
        cout << "The second largest number is: "<<secondLargest<<endl;
    }
    
    return 0;
}