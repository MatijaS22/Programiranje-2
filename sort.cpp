#include <iostream>
#include <iomanip>

using namespace std;

void ispis(int p[], int n){
    for(int i=0;i<n;i++){
        cout<<setw(4)<<p[i];
    }
    cout<<endl;
}



void mergearray(int p[],int first, int last){
    int mid=(first+last)/2;
    int temp[50];
    int j=last;
    for(int i=0;i<=mid;i++)
        temp[i]=p[i];
    for(int i=mid+1;i<=last;i++)
        temp[j--]=p[i];
    j=last;
    for(int i=first,k=first;i<=last;i++){
        if(temp[k]<temp[j])
            p[i]=temp[k++];
        else
            p[i]=temp[j--];
    }
}

void mergesort(int p[],int first,int last){
    if(first>=last)
        return;
    int mid=(first+last)/2;
    mergesort(p,first,mid);
    mergesort(p,mid+1,last);
    mergearray(p,first,last);
}

int main(){
    const int vel=7;
    int polje[vel]={12, 21, 11, 30, 15, 17, 16};
    cout<<"Nesortirani niz: ";
    //int vel=sizeof(polje)/sizeof(int); - ili koristimo to, ili const int vel=7
    ispis(polje,vel);
    mergesort(polje,0,vel-1);
    cout<<"\nSortirani niz:";
    ispis(polje,vel);
    cout<<endl;
    return 0;
}
