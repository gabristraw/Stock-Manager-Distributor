// @Gabristraw

//     Stock distributor - Program that self-distributes the stock of a where house and facilitates the search for available material.

// All the code of main.c belongs to the creator gabristraw and can be denounced if it is copied.

#include <stdio.h>
#include <string.h>

#define MAX_CADENA 500
#define MAX_RESERVA 15

typedef struct {

    char dni[40];
    int dni_int;
    char edat[100];
    int edat_int;
    char nombre[70];
    
} Reserva;

void prompt () {
    printf("\n> "); 
}


int AtoiPersonalitzat(char* cadena)
{

    int signe = 1;
    int numero = 0;
    int i = 0;

    if (cadena[0] == '-') {
        
        signe = -1;

        i++;
    }

    for (; cadena[i] != '\0'; ++i)
        numero = numero * 10 + cadena[i] - '0';

    return signe * numero;
}


char errorMenuFuncio(char cadena, int i) {

    printf("ERROR: Invalid command. Available commands are: add, remove, show, exit.\n");
    cadena = '\0';

    return cadena;
}

void errorsAllMissing() {
    printf("ERROR: DNI field is missing.\n");
    printf("ERROR: age field is missing.\n");
    printf("ERROR: name field is missing.\n");
}


void errorDniNotValid(int error_dni_valid, int digitos_dni) {

    if (error_dni_valid == 1 || (digitos_dni > 8 || digitos_dni < 8)) {

        printf("ERROR: DNI is not valid\n");
    }
}

int main () {

    Reserva reserva[MAX_RESERVA];

    char cadena[MAX_CADENA];

    char menu[10];              //Varieables amb finalitat del menu
    char add[5] = "add"; char removed[10] = "remove"; char show[5]= "show"; char exitt[10]= "exit"; char dni_remove_char[100];

    int i= 0, j= 0, l= 1, b = 0; //Contadores 
    int errorMenu= 0,error_dni = 0, error_dni_valid = 0,digitos_dni = 0, error_edat = 0, dni_repetit= 0,  dni_remove_int;//variables indicadores de error

    char opcio_show[10];    //valor de la opcio show
    int opcio_show_int = 0;

    reserva[l].dni[0] = '\0';
    reserva[l].dni_int = '\0';
    reserva[l].edat[0] = '\0';
    reserva[l].edat_int = '\0';
    reserva[l].nombre[0] = '\0';
    reserva[0].dni[0] = '\0';
    reserva[0].dni_int = '\0';
    reserva[0].edat[0] = '\0';
    reserva[0].edat_int = '\0';
    reserva[0].nombre[0] = '\0';

    printf("Welcome to LS CINEMA!\n");

    do {
        error_dni = 0 ;error_dni_valid = 0 ;digitos_dni = 0; errorMenu = 0; error_edat = 0;dni_repetit = 0; dni_remove_int = 0; opcio_show_int = 0; 
        
        i = 0;
        j = 0;
        b = 0;

        prompt(); 
        fgets(cadena, MAX_CADENA, stdin);   
        
        cadena[strlen(cadena) - 1] = '\0'; 
     
        
            while(cadena[i] != ' ') {
                
                if(cadena[i] == '\0') {
                    cadena[i] = ' ';
                    errorMenu = 1;
                }
                else {
                    menu[j] = cadena[i];

                    i ++;
                    j ++;
                }
            }
            menu[j] = '\0';

            if(errorMenu == 1){
                cadena[i] = '\0';
            }


            if (strcmp(menu,add) == 0 ||strcmp(menu,removed) == 0||strcmp(menu,show) == 0||strcmp(menu,exitt) == 0 ){       


                switch (menu[0]) {

                    case 'a': 

                        if (l > 10) {                      
                            printf("ERROR: Cinema at full capacity, sorry.\n");

                            cadena[i] = '\0';

                            l = 11;
                        }
                        else {

                            if(cadena[i] == '\0') {

                                errorsAllMissing();       
                            }
                            else {

                                i ++;                    
                                j = 0;
                                while (cadena[i] != ' ') { 

                                    if (cadena[i] == '\0') {

                                        cadena[i] = ' ';
                                        error_dni = 1;
                                    }
                                    else {

                                        if(((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z')) || j > 7 ){
                                            error_dni_valid = 1;
                                            
                                            i ++;
                                            j ++;
                                        }
                                        else{
                                            reserva[l].dni[j] = cadena[i];
                                    
                                            j ++;
                                            i ++;
                                        }
                                    }
                                }

                                reserva[l].dni[j] = '\0';

                                digitos_dni = strlen(reserva[l].dni);          
                                
                                errorDniNotValid(error_dni_valid, digitos_dni);

                                if (error_dni == 1){
                                    cadena[i] = '\0';
                                    printf("ERROR: age field is missing.\n");
                                    printf("ERROR: name field is missing.\n");
                                }
                                else{


                                    reserva[l].dni[j] = '\0';

                                    reserva[l].dni_int = AtoiPersonalitzat(reserva[l].dni); 


                                    i ++;
                                    j = 0;

                                    while (cadena[i] != ' ') {                             

                                        if (cadena[i] == '\0') {
                                            cadena[i] = ' ';
                                            error_edat = 1;
                                        }
                                        reserva[l].edat[j] = cadena[i];
                                            
                                        j++;
                                                                        
                                        i ++;
                                    }

                                    reserva[l].edat[j] = '\0';
                                    

                                    if (error_edat == 1) {                               
                                        cadena[i]= '\0';
                                        printf("ERROR: name field is missing.\n");
                                    }
                                    else{
                                            
                                        reserva[l].edat_int = AtoiPersonalitzat(reserva[l].edat);
                                        j = 0;
                                        i ++;                                             

                                        while (cadena[i] != '\0') {

                                            reserva[l].nombre[j] = cadena[i];
                                            j ++;
                                            i ++;
                                        }

                                        reserva[l].nombre[j] = '\0';

                                        if(error_dni_valid != 1 && digitos_dni <= 8){     

                                            j = 0;

                                            if (l == 1) {
                                                l ++;                                      
                                            }
                                            else {
                                                j = 1;

                                                do {                                       
                                                    if(reserva[l].dni_int == reserva[j].dni_int) { 
                                                        dni_repetit = 1;
                                                    }

                                                    j ++;

                                                }while(j < l);


                                                if (dni_repetit == 1) {                   
                                                    printf("ERROR: There is another person with the same DNI.\n");
                                                }
                                                else { l ++ ;}                                                                             
                                                
                                            }  
                                        }
                                        else {
                                            reserva[l].dni[0] = '\0';
                                            reserva[l].dni_int = '\0';
                                            reserva[l].edat[0] = '\0';
                                            reserva[l].edat_int = '\0';
                                            reserva[l].nombre[0] = '\0';
                                        }
                                    }         
                                }
                            }
                        }

                        break;

                    case 'r': 

                        j = 0;

                        if(cadena[i] == '\0') {        
                                printf("ERROR: DNI is not valid.\n");
                        }
                        else{

                            i ++;                      

                            while (cadena[i] != '\0') {

                                if(((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z')) || j > 8){
                                            error_dni_valid = 1;
                                            
                                            i ++;
                                            j ++;
                                }
                                else {
                                    dni_remove_char[j] = cadena[i];

                                    j ++;
                                    i ++;
                                }
                            }

                            dni_remove_char[j] = '\0';

                            digitos_dni = strlen(dni_remove_char);

                            if (error_dni_valid == 1 || (digitos_dni > 8 || digitos_dni < 8)) { 
                                printf("ERROR: DNI is not valid\n");
                            }
                            else { //error free

                                 dni_remove_int = AtoiPersonalitzat(dni_remove_char); 

                                 if(error_dni_valid != 1 && digitos_dni <= 8){

                                            
                                        j = 1;

                                            do {

                                                
                                                 if(dni_remove_int == reserva[j].dni_int) {

                                                    b = j;

                                                    do {                           
                                                        strcpy(reserva[b].nombre, reserva[b+1].nombre);
                                                        reserva[b].dni_int = reserva[b + 1].dni_int;
                                                        reserva[b].edat_int = reserva[b + 1].edat_int;


                                                        b ++;

                                                    } while (b < l);

                                                    reserva[l].dni[0] = '\0';
                                                    reserva[l].dni_int = '\0';
                                                    reserva[l].edat[0] = '\0';
                                                    reserva[l].edat_int = '\0';
                                                    reserva[l].nombre[0] = '\0';

                                                    l --;


                                                    dni_repetit = 1;
                                                 }

                                                 j ++;

                                            }while(j < l);

                                            if (dni_repetit != 1) {                
                                                printf("ERROR: DNI not found. Not removed.\n");
                                                
                                            }
                                                                                                                                            
                                        }
                            }                            
                        }

                        break;

                    case 's': 

                         j = 0;

                        if ( cadena[i] == '\0') {              
                            printf("ERROR: Index starts at 1.\n");
                        }
                        else{

                            i ++ ;                             
                            while (cadena[i] != '\0') {         

                                opcio_show[j] =  cadena[i];

                                i ++;
                                j ++;
                            }

                            opcio_show[j] = '\0';

                            if (strcmp(opcio_show, "all") == 0) {
                                                                      
                                j = 0;

                                if (10 - (l-1) == 10) {              
                                    printf("ERROR: Nothing to show.\n");
                                }
                                else {

                                    if (reserva[1].nombre[0] == '\0') {
                                        printf("ERROR: Nothing to show.\n");
                                    }
                                    else{

                                        do {                          
                                            j ++;

                                            printf("<%s> <%d> <%d>\n", reserva[j].nombre, reserva[j].edat_int, reserva[j].dni_int);
                                                                               
                                        }while(j < l-1);
                                    }
                                }
                            }
                            else {

                                if (strcmp(opcio_show, "remaining") == 0) {     

                                    printf("Remaining capacity: %d\n", (10 - (l-1)));

                                }

                                else {

                                    if ((opcio_show[0] >= 'a' && opcio_show[0] <= 'z') || (opcio_show[0] >= 'A' && opcio_show[0] <= 'Z'))  {

                                        printf("ERROR: Invalid option.\n");     
                                    }
                                    else {
                                                                              
                                        opcio_show_int = AtoiPersonalitzat(opcio_show);

                                        if (opcio_show_int == 0) {              
                                            printf("ERROR: Index starts at 1.\n");
                                        }
                                        else {
                                                                               
                                            if (reserva[opcio_show_int].nombre[0] =='\0') {
                                                printf("ERROR: Nothing to show.\n");
                                            }
                                            else {
                                                                            
                                                if (10 - (l-1) == 10 || opcio_show_int > 10 ) {
                                                    printf("ERROR: Nothing to show.\n");
                                                }
                                                else {                         
                                                printf("<%s> <%d> <%d>\n", reserva[opcio_show_int].nombre, reserva[opcio_show_int].edat_int, reserva[opcio_show_int].dni_int);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        break;

                    case 'e':
                        printf("Have a nice day!");                            

                        break;
                }
            }

            else{

                cadena[i] = errorMenuFuncio(cadena[i], i);
                
            }      

    } while(menu[0] != 'e'  && cadena[i] == '\0' );

    return 0;
}