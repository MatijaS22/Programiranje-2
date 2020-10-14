#include <iostream>
using namespace std;

struct cvor // sadr?i podatak i vezu
{
    int podatak;
    cvor *veza;
};

void ispis (cvor *glava)
{
    while(glava != NULL)
    {
        cout<<glava->podatak<<endl;
        glava = glava->veza;
    }
}

//Prilikom dodavanja novog elementa u listu potrebno je alocirati
//memorijski prostor za taj element

void unos (cvor *&glava, int x)
{
    cvor *novi = new cvor; //alokacija memorije za novi ?vor
    novi->podatak = x; //Zapis podatkovnog djela
    novi->veza = glava; //povezivanje novog ?vora sa zadnje dodanim ?vorom
    glava = novi; //povezivanje pokaziva?a (glave) s novim ?vorom
}

//FUNKCIJA ZA DRUGI I TRE?I ZADATAK
void unos2 (cvor *&glava, int x)
{
    cvor *novi = new cvor;
    novi->podatak = x;
    novi->veza = NULL;

    if(glava==NULL)
        glava=novi;
    else
    {
        cvor *tmp = glava;
        while(tmp->veza)
           tmp = tmp->veza;

        tmp->veza = novi;
    }

}

int main()
{
    int x;
    cvor *glava = NULL, *tekuci;

    do
    {
        cout<<"Unesi x: ";
        cin>>x;

        unos2(glava,x); //unos(glava,x); za prvi zadatak

    }while(x!=0);

    ispis(glava);
    //DEALOKACIJA;

    while(glava)
    {
        tekuci = glava;
        glava = glava->veza;
        delete tekuci;
    }
    //PROVJERA: glava mora bit 0
    cout<<glava;


    return 0;
}
