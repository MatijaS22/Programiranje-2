#include<iostream>
#include <stdlib.h>
using namespace std;

struct cvor {
    int podatak;
    cvor *veza;
};

int waitingNum(cvor *glava) {
    int br=0;
    while(glava) {
        br++;
        glava = glava->veza;
    }
    return br;
}

void entry(cvor *&glava, cvor *&rep, int elt) {
    cvor *novi = new cvor;
    novi->podatak = elt;
    novi->veza=NULL;

    if(glava==NULL)
        glava = novi;
    else
        rep->veza = novi;
    rep = novi;

    cout<<"Preuzeli ste listic s rednim brojem cekanja u redu: "<<elt<<endl;
    cout<<"Broj osoba koje cekaju u redu ispred vas je "<<waitingNum(glava)-1<<endl;
}


bool queueEmpty(cvor *glava) {
    if(glava == NULL)
        return true;
    else
        return false;
}

int process(cvor *&glava, cvor *&rep) {
    int elt = glava->podatak;
    cvor *tmp = glava;
    if(glava==rep)
        rep=0;
    glava = glava->veza;
    delete tmp;
    return elt;
}



void deleteQueue(cvor *&glava, cvor *&rep) {
    cvor *tmp;
    while(glava) {
        tmp = glava;
        glava = glava->veza;
        delete tmp;
    }
    rep = NULL;
}





int main() {
	cvor *glava=NULL, *rep=NULL;
	int elt=1;
	char odabir;
	do {
		system("cls");
		cout<<"\n\nBANKA d.d. Glavni izbornik...I-Z-B-O-R-N-I-K"<<endl;
		cout<<"\n1 - Ulaz nove stranke";
		cout<<"\n2 - Obrada stranke";
		cout<<"\n3 - Ispis trenutnog stanja";
		cout<<"\n0 - Kraj";
		cout<<"\n\nUnesite Vas odabir...";
		cin>>odabir;
		cin.ignore(1,'\n');
		switch(odabir) {
		case '1':
			cout<<"Klikom na gumb preuzmite listic s brojem cekanja u redu.\n";
			cin.get();
			entry(glava,rep,elt);
			elt++;
			cin.get();
			break;
		case '2':
			if(!queueEmpty(glava))
                cout<<"Salter je slobodan. Molimo stranku s rednim brojem: "<<process(glava,rep)<<" da dodje na salter"<<endl;
			else cout<<"Red je prazan, nema kandidata za nove transkacije."<<endl;
			cin.get();
			break;
		case '3':
			cout<<"U redu na salteru ceka "<<waitingNum(glava)<<" ljudi.\n";
			cin.get();
			break;
		case '0':
			cout<<"Kraj programa.\n";
		}
	}
	while(odabir!='0');
	//DEALOKACIJA!!!
	deleteQueue(glava,rep);
	return 0;
}

