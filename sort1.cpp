#include <iostream>
#include <iomanip>

using namespace std;

void ispis(int polje[], int n){
    for(int i=0;i<n;i++){
        cout<<setw(4)<<polje[i];
    }
    cout<<endl;
}

void quicksort(int polje[],int first, int last){
    if(first>last)
        return;
    int pivot=polje[first];
    int i=first+1,j=last;
    while(i<=j){
        while(polje[i]<pivot)
            ++i;
        while(polje[j]>pivot)
            --j;
        if(i<=j){
            swap(polje[i],polje[j]);
            ++i;
            --j;
        }
        ispis(polje,7);
    }
    swap(polje[j],polje[first]);
    quicksort(polje,first,j-1);
    quicksort(polje,j+1,last);
}

int main()
{
    const int vel=7;
    int polje[vel]={12, 21, 11, 30, 15, 17, 16};
    cout<<"Nesortirani niz: ";
    ispis(polje,vel);
    cout<<"\nKoraci sortiranja:\n";
    quicksort(polje,0,vel-1);
    cout<<"\nSortirani niz:";
    ispis(polje,vel);
    cout<<endl;
    return 0;
}
