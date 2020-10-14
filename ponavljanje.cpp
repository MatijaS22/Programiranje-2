/*mplementiraj povezanu listu koja ce kao podatak sadrzavati cijeli broj, maticni broj i prezime studenta.
Napisati funkciju koja ce dodavati na kraj liste novi element, napisati funkciju koja ispisuje onaj element koji ima zadani maticni broj
(unosi ga korisnik u glavnom programu).
U glavnom programu omogucava se dodavanje elementa u listu, ucitava se dok zeli korisnik i ispis onog elementa s maticnim brojem kojeg unosi korisnik.
Na kraju dealokacija*/

#include <iostream>

using namespace std;

struct student

{

int mbr;
string prezime;
student* veza;

};

void unos_nakraj(student* &glava, int mbr, string prezime)

{

    student *novi = new student; //novi element liste
    novi->mbr=mbr;
    novi->prezime=prezime;
    novi->veza=NULL; //prije nego se unese novi veza je NULL

    if (glava==NULL) //slucaj kada je lista prazna, unosimo prvi element liste

    {

        glava=novi;

    }

      else

      {

      student *trenutni = glava; //neki trenutni koji prolazi listom

      while (trenutni->veza != NULL) //ide do kraja liste

        {

          trenutni=trenutni->veza; //prelazi na vakog sljedeceg clana liste

        }

            trenutni->veza=novi; //iza while zagrada jer se ovo odvija nakon što trenutni do?e do kraja liste
                                 //trenutni koji je onda bio zadnj se mora povezati s novim koji postaje zadnji u listi
            trenutni=novi; //trenutni je sad taj novi koji je ušao u listu

      }

}

void ispis_prema_mbr(student* glava, int br)

{

    student *trenutni = glava; // za ispis je potreban trenutni koji prolazi listom
                               // na pocetku je postavljen na pocetak liste - glava

    while (trenutni != NULL )

       {

       if(br==trenutni->mbr)   //provjerava je li broj kojeg unosi korisnik u glavnom programu jednat mat. broju studenta iz liste
                               //ako je, onda se ispisuju podatci studenta

          {

          cout<<"Maticni broj: "<<trenutni->mbr<<endl;
          cout<<"Prezime studenta: "<<trenutni->prezime<<endl;

          }

        trenutni=trenutni->veza; //prelazak na sljedeai element u listi
                                 //mora biti u while petlji

       }

}



int main()

{

    student* glava=NULL;

    cout<<"Opcije: \nA- dodavanje studenata \nB - ispis podataka prema mbr \nC - izlaz "<<endl;

    char odg;

    do
    {

    cout<<"Izaberite jednu od opcija: "<<endl;
    cin>>odg;

    if (odg=='A')

       {

        int mbr;
        string prezime;
        cout<<"Unesite maticni broj: "<<endl;
        cin>>mbr;
        cout<<"Unesite prezime: "<<endl;
        cin>>prezime;
        unos_nakraj(glava, mbr, prezime);

       }


    if (odg=='B')

      {

      cout<<"Ispis: "<<endl;
      cout<<"Unesite maticni broj studenta za ispis: "<<endl;
      int br;
      cin>>br;
      ispis_prema_mbr(glava,br);


      }

    }

    while(odg!='C');

    student *temp=NULL;
    while (glava)

    {

        temp=glava->veza;
        delete temp;
        glava=temp;

    }

    return 0;

}
