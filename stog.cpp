#include <iostream>
#include<iomanip>

using namespace std;

struct cvor{
	int podatak;
	cvor *veza;
};

void push(cvor *&glava, int elt) {
    cvor *novi = new cvor;
    novi->podatak = elt;
    novi->veza = glava;
    glava = novi;
}





bool stackEmpty(cvor *glava) {
    if(glava == NULL)
        return true;
    else
        return false;
}

int pop(cvor *&glava) {
    int elt = glava->podatak;
    cvor *tmp = glava;
    glava = glava->veza;
    delete tmp;

    return elt;
}

void write(cvor *glava) {
    while(glava){
        cout<<setw(5)<<glava->podatak;
        glava = glava->veza;
    }
    cout<<endl;
}

void deleteStack(cvor *&glava) {
    cvor *tmp;
    while(glava) {
        tmp = glava;
        glava = glava->veza;
        delete tmp;
    }
    glava = NULL;
}

int main(){
	cvor *stog = NULL;
	int elt=1;
	char odabir;
	do{
		cout<<"\n\nI-Z-B-O-R-N-I-K"<<endl;
		cout<<"\n1 - Unos novog primjerka";
		cout<<"\n2 - Preuzimanje artikla";
		cout<<"\n3 - Ispis trenutnog stanja skladista";
		cout<<"\n0 - Kraj";
		cout<<"\n\nUnesite Vas odabir...\n";
		cin>>odabir;
		switch(odabir) {
		case '1':
			push(stog,elt);
			elt++;
			cin.get();
			break;
		case '2':
			if(!stackEmpty(stog)) {
				cout<<"Preuzet je artikl pod rednim brojem..."<<pop(stog)<<endl;
				elt--;
			}
			else cout<<"Skladiste je prazno. Nemate sto preuzeti"<<endl;
			cin.get();
			break;
		case '3':
			if(!stackEmpty(stog)) write(stog);
			else cout<<"Skladiste je prazno."<<endl;
			cin.get();
			break;
		case '0':
			cout<<"Kraj programa.\n";
		}

	} while(odabir!='0');
	//DEALOKACIJA
	deleteStack(stog);

	return 0;
}


