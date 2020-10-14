#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct Node { 
   int maticni;
   //string ime;
   char ime[20];
   //string prezime;
    char prezime[30];
   double bodovi;
   struct Node *prev; 
   struct Node *next; 
}; 
struct Node* head = NULL; 
void insert(int mat, double bod, const char* im, const char* pr) { 
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); 

   
   newnode->bodovi = bod;
   newnode->maticni = mat;
   

   strcpy(newnode->ime,im);
     strcpy(newnode->prezime,pr);

   newnode->prev = NULL; 
   newnode->next = head;    
   

    struct Node* current; 
  
    if (head == NULL) 
        head = newnode; 
  
 
    else if (head->maticni >= newnode->maticni) { 
        newnode->next = head; 
        newnode->next->prev = newnode; 
        head = newnode; 
    } 
  
    else { 
        current = head; 
  
        
        while (current->next != NULL &&  
               current->next->maticni < newnode->maticni) 
            current = current->next; 
  
        
  
        newnode->next = current->next; 
  
    
        if (current->next != NULL) 
            newnode->next->prev = newnode; 
  
        current->next = newnode; 
        newnode->prev = current; 
    } 

 
  
}   
void display() { 
   struct Node* ptr;
   ptr = head;  
   int ukupno = 0;
   int zadovoljili = 0;
   while(ptr != NULL) { 
      cout<< ptr->maticni <<" "  <<ptr->ime <<" "<<ptr->prezime<<" "<<ptr->bodovi<<"  \n"; 
      ukupno++;
      if(ptr->bodovi >= 40) zadovoljili++;
      ptr = ptr->next; 
   
  } 
  while( head != NULL){
      ptr = head->next;
      free(head);
      }
  double postotak = ((double)zadovoljili/ukupno) * 100;
  cout << " Zadovoljilo je! " << postotak <<"%";
  
} 

int main() { 
   
 //  insert(1, 35, "mario", "maric");
   insert(123, 35, "mario", "maric");
   insert(13, 35, "mario", "maric");
   insert(1423, 35, "mario", "maric");
   insert(3, 45, "mario", "maric");
   insert(13, 35, "mario", "maric");

  
   cout<<"Dvostruko povezana lista ";
  
   display(); 
   return 0; 
}
