#include <iostream>
using namespace std;

struct cvor
{
	int podatak;
	cvor *veza;
};

void input(cvor *&glava, int x)
{
	//NADOPUNITI KOD za unos elementa liste tako da je lista u svakom trenu sortirana uzlazno (1-9)
	cvor *novi = new cvor;
	novi->podatak = x;
	novi->veza = NULL;

	cvor *tekuci=glava, *prethodni = NULL; //2 pokazivaca za kretanje kroz listu: prethodni i tekuci a izmedju smjestamo novi element

	while(tekuci && tekuci->podatak < x) //pronalazimo mjesto di spremamo novi cvor, obilazimo listu
    {
        prethodni = tekuci;
        tekuci = tekuci->veza;
    }

    if(prethodni) //DOdajemo novi cvor u sredinu ili na kraj liste
    {
        prethodni->veza = novi;
        novi->veza = tekuci;
    }
    else //Dodajemo novi cvor na pocetak liste
    {
        novi->veza = glava;
        glava = novi;
    }
}

void write(cvor *glava)
{
	cout<<"Ispis elemenata liste...\n";
	if (glava==0) cout<<"\nLista je prazna.\n";
	else
	{
		cvor *tekuci=glava;
		while(tekuci)
		{
			cout<<tekuci->podatak<<endl;
			tekuci=tekuci->veza;
		}
	}
}

void erase(cvor *&glava, int x)
{
	//NADOPUNITI KOD za brisanje elementa liste
	cvor *tekuci=glava, *prethodni = NULL;
	while(tekuci) //Prolazimo kroz listu dok ne nadjemo elt
    {
        if(tekuci->podatak == x)
            break;
        prethodni = tekuci;
        tekuci = tekuci->veza;
    }

    if(tekuci) // != NULL, odnosno lista nije prazna
    {
        if(prethodni == NULL) //1. CVOR JE NA POCETKU LISTE
            glava = glava->veza;
        else
            prethodni->veza = tekuci->veza; //2. CVOR JE U SREDINI LISTE ILI NA KRAJU

        delete tekuci;
        tekuci = NULL;
    }
}

int main(){
	int elt;
	char odabir;
	//kreiranje liste
	cvor *glava=0;
	//izbornik poziva tek nakon sto je kreirana lista...mo?e i u izborniku, ali onda treba provjera...
	do{
		cout<<"\n\n- IZBORNIK -\n";

		cout<<"1 - Unos novog elementa liste\n";
		cout<<"2 - Ispis liste\n";
		cout<<"3 - Brisanje elementa liste\n";
		cout<<"0 - KRAJ";
		cout<<"\n--------------------------------\n";
		cout<<"Unesite vas odabir: ";
		cin>>odabir;
		switch(odabir)
		{
			case '1':
				cout<<"Unesite element koji zelite dodati u listu: "; //mo?e se prebaciti i u funkciju
				cin>>elt; //mo?e se prebaciti i u funkciju
				input(glava,elt);
				break;
			case '2':
				write(glava);
				break;
			case '3':
				cout<<"Unesite element koji zelite brisati: "; //mo?e se prebaciti i u funkciju
				cin>>elt; //mo?e se prebaciti i u funkciju
				erase(glava, elt);
				break;
			case '0':
				cout<<"\nKRAJ!\n";
		}
	}
	while(odabir!='0');

	/*
	DEALOKACIJA
	*/
	cvor *tekuci=glava;
	cvor *temp;
	while(tekuci)
	{
		temp=tekuci;
		tekuci=tekuci->veza;
		delete temp;
	}
	glava=tekuci; //bit ce NULL (0)


	return 0;
}
