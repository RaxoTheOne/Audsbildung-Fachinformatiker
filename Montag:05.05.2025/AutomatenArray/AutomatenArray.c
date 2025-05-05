#include <stdio.h>
#include <stdlib.h>

//Funktion Deklanarieren
void menu_ausgaben();
int auswahl_einlesen();
int preis_erfragen(int);
int geld_einwerfen (int);
void ruckgeld_ausgeben(int);


//Variables
int auswahl;
int zuzahlen;
int einwurf;
int gezahlt;
int preis;

char gliste[][20] = {"Cola", "Fanta", "Sprite", "Eistee", "Koffee"};
int glistegrosse = sizeof(gliste)/sizeof(gliste[0]);//4

int gpreis[] = {120, 130, 150, 100, 120};
int gpreisgrosse = sizeof(gpreis)/sizeof(int);//4

int muenzen [] = {200, 100, 50, 20, 10};
int m_grosse = sizeof(muenzen)/sizeof(int);

int main()
{

    //rufen menu_ausgaben() auf
        menu_ausgaben();

    //auswahl einlesen
        auswahl = auswahl_einlesen();

    //rufen preis_erfragen auf
        preis= preis_erfragen(auswahl);

    //rufen geld_einwerfen auf
        int bezahltbetrag =  geld_einwerfen(preis);

    //rufen ruckgeld_ausgeben auf
        int zurueckgeld = bezahltbetrag-preis;
    //uberpruefen fuer das Ruckgeld
        if( zurueckgeld > 0){

            ruckgeld_ausgeben(zurueckgeld);

        }

        printf("Entnehmen Sie Ihr Getraenk.");

}

//
void menu_ausgaben (){
    //gliste, gpreis , glistegrosse
    //Menue
    for(int i = 0; i<glistegrosse; i++){

        printf("%d %-10s %d Cent \n", i+1, gliste[i], gpreis[i]);

    }

}

int auswahl_einlesen(){

 // Auswahl einlesen
    do
    {
        printf("Ihre Auswahl: ");
        scanf("%d", &auswahl);
    } while( auswahl < 1 || auswahl > glistegrosse);


    return auswahl;

}

int preis_erfragen(int auswahl){

     // Geldanforderung
    printf("Zahlen Sie ");
    zuzahlen = gpreis[auswahl-1];

    return zuzahlen;

}

int geld_einwerfen(int betrag){

 // Geldeingabe
    gezahlt = 0;

    do
    {

        printf("Einwurf (%d Cent): ", betrag - gezahlt);
        scanf("%d", &einwurf );
        gezahlt += einwurf;
    } while( gezahlt < zuzahlen);

    return gezahlt;

}

void ruckgeld_ausgeben (int gezahltgeld){

 // Geldr�ckgabe

        printf("Sie erhalten %d zurueck.\n", gezahltgeld);

        //muenzen, m_grosee

        for (int i = 0; i<m_grosse; i++){

            int anzahl = gezahltgeld/muenzen[i];

            if(anzahl>0){
                printf("%d mal %d Cent\n", anzahl, muenzen[i] );
                gezahltgeld%=muenzen[i];
            }
        }
}