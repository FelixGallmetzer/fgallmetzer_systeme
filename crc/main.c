#include<stdio.h>
#include<string.h>
char generator[10];
#define N strlen(generator)
char eingabe[28];
char checksum[28];
int eingabe_length,i,j;

// überprüft über das XOR Verfahren ob die Eingabe 1 oder 0 ist.
void XOR(void){
    for(j = 1; j < N; j++)
    checksum[j] = (( checksum[j] == generator[j])?'0':'1');   
}

void crc(void){
    for(i = 0; i < N; i++)
        checksum[i] = eingabe[i];
    do{
        if(checksum[0] == '1') {
            XOR();
        }
// Die Bits werden für die nächste Berechnung um 1 verschoben.
        for(j = 0; j < N - 1; j++)
            checksum[j] = checksum[j + 1];
        checksum[j] = eingabe[i++];
    }while(i <= eingabe_length + N - 1);
}

int main(int argc, char *argv[])
{
    if (argc > 3) {
        printf("Zu viele Argumente");
        return -1;
    } 
    if (argc < 3) {
        printf("Zu wenig Argumente");
        return -1;
    }
    for (i = 0; i < strlen(argv[1]); i++) {
        eingabe[i] = argv[1][i];
    }   
    eingabe_length = strlen(eingabe);

    for (i = 0; i < strlen(argv[2]); i++) {
        generator[i] = argv[2][i];
    }

    // n-1 nullen zur Eingabe hinzufügen
    for(i = eingabe_length; i < eingabe_length + N - 1; i++) {
        eingabe[i] = '0';
    }
    //crc wird berechnet
    crc();

    printf("Checksum: %s\n",checksum); 

    for(i = eingabe_length; i < eingabe_length + N - 1; i++) {
        eingabe[i] = checksum[i - eingabe_length];
    }
    printf("Daten (um auf Fehler zu überprüfen): %s\n",eingabe);

    printf("Geben sie die Daten ein: ");
    if (fgets(eingabe,sizeof(eingabe)-1,stdin) == 0) {
        perror("0");
        return -1;
    }
    printf("Daten: %s", eingabe);

    crc();

    for(i = 0;(i < N - 1) && (checksum[i] != '1'); i++);
        if(i < N - 1)
            printf("\nFehler\n\n");
        else
            printf("\nKein Fehler\n\n");

    return 0;
}