#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PITUUS 48

// SUBPROGRAM FOR MENU
void nayta_valikko() {
    printf("Choose one option in below\n");
    printf("1) Add name to file\n");
    printf("2) Print file\n");
    printf("0) Quit\n");
    printf("Provide your choice: ");
}

// SUBPROGRAM FOR WRITING IN FILE

void kirjoita_tiedostoon(char tiedostoNimi[100], char *nimi){

    FILE *tiedosto;
    tiedosto=fopen(tiedostoNimi,"a");
    if (tiedosto == NULL){
        printf("Opening file failed, quitting: No such file or directory\n");
        exit(0);
    }
    else {
        fprintf(tiedosto, "%s\n", nimi);
        printf("Name added to file.\n");
    }    
        fclose(tiedosto);

}

//  SUBPROGRAM FOR READING AND PRINTING FILE
void lue_tiedosto(char *tiedostoNimi){
    FILE *tiedosto;
    tiedosto = fopen(tiedostoNimi, "r");
    if (tiedosto == NULL){
       // printf("Tiedoston avaaminen epäonnistui, lopetetaan: No such file or directory\n");
        exit(0);
    }
    else{
        char nimi[MAX_PITUUS];
        printf("File content:\n");

        while(fgets(nimi, sizeof(nimi), tiedosto)){
        printf("%s", nimi);
        }
        printf("File read and printed.\n");
    }
    fclose(tiedosto);
}

int main(){

    int valinta;
    char tiedostoNimi[100];
    char nimi[MAX_PITUUS];

    printf("This program adds names to file and reads it.");
    printf("\nProvide the name of the file to be processed:");
    scanf(" %s", tiedostoNimi);
    

        while(1){
        nayta_valikko();
        scanf("%d", &valinta);
        
        if(valinta == 1){
            printf("Provide name to add: ");
            scanf("%s", nimi); 
            kirjoita_tiedostoon(tiedostoNimi, nimi);
        }
        else if(valinta == 2){
            lue_tiedosto(tiedostoNimi);
        }
        else if(valinta == 0){
            printf("Thank you for using this program.\n");
            break;
        }
        else{
            printf("Error occured. Try again.\n");
        }
    }

    return 0;
}
