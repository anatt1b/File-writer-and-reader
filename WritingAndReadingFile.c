/*Tee ohjelma, jossa on pääohjelman lisäksi kolme aliohjelmaa – 
yksi valikkoa varten, toinen tiedoston kirjoittamiseen ja kolmas lukemiseen. 
Tiedostoa kirjoittava aliohjelma kysyy käyttäjältä nimiä 
ja lisää ne tiedostoon siellä aiemmin olevien nimien jatkoksi. 
Tiedostoa lukeva aliohjelma avaa tiedoston, lukee nimet ja tulostaa ne näytölle riveittäin. 
Tee valikko ohjelman pyörittämiseen 
ja käytä valikon toteuttamiseen if, else-if, else -rakennetta. 
Ohjelma kysyy alussa käsiteltävän tiedoston nimen ja välitä sen parametrina aliohjelmiin. 
Käyttäjältä kysyttävien nimien maksimipituus on 48 merkkiä, 
tee sitä varten ohjelmaan oma vakio. 
Muista laittaa tiedostonkäsittelyihin virheenkäsittely.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PITUUS 48

// ALIOHJELMA VALIKON NÄYTTÄMISEEN
void nayta_valikko() {
    printf("Valitse alla olevista valinnoista\n");
    printf("1) Lisää uusi nimi\n");
    printf("2) Tulosta nimet\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
}

// ALIOHJELMA TIEDOSTON KIRJOITTAMISEEN.

void kirjoita_tiedostoon(char tiedostoNimi[100], char *nimi){

    FILE *tiedosto;
    tiedosto=fopen(tiedostoNimi,"a");
    if (tiedosto == NULL){
        printf("Tiedoston avaaminen epäonnistui, lopetetaan: No such file or directory\n");
        exit(0);
    }
    else {
        fprintf(tiedosto, "%s\n", nimi);
        printf("Nimi lisätty tiedostoon.\n");
    }    
        fclose(tiedosto);

}

//  ALIOHJELMA TIEDOSTON LUKEMISEEN JA TULOSTAMISEEN.
void lue_tiedosto(char *tiedostoNimi){
    FILE *tiedosto;
    tiedosto = fopen(tiedostoNimi, "r");
    if (tiedosto == NULL){
       // printf("Tiedoston avaaminen epäonnistui, lopetetaan: No such file or directory\n");
        exit(0);
    }
    else{
        char nimi[MAX_PITUUS];
        printf("Tiedostossa olevat nimet:\n");

        while(fgets(nimi, sizeof(nimi), tiedosto)){
        printf("%s", nimi);
        }
        printf("Tiedosto luettu ja tulostettu.\n");
    }
    fclose(tiedosto);
}

int main(){

    int valinta;
    char tiedostoNimi[100];
    char nimi[MAX_PITUUS];

    printf("Tämä ohjelma lisää nimiä tiedostoon ja lukee ne.");
    printf("\nAnna käsiteltävän tiedoston nimi:");
    scanf(" %s", tiedostoNimi);
    

        while(1){
        nayta_valikko();
        scanf("%d", &valinta);
        
        if(valinta == 1){
            printf("Anna lisättävä nimi: ");
            scanf("%s", nimi); 
            kirjoita_tiedostoon(tiedostoNimi, nimi);
        }
        else if(valinta == 2){
            lue_tiedosto(tiedostoNimi);
        }
        else if(valinta == 0){
            printf("Kiitos ohjelman käytöstä.\n");
            break;
        }
        else{
            printf("Virheellinen valinta. Yritä uudestaan.\n");
        }
    }

    return 0;
}
