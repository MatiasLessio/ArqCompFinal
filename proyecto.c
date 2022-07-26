#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <curl/curl.h>
#ifndef MAX  
#define MAX 10000
#endif
char* Interaction(char*,int);

char* urlStart = {"https://api.telegram.org/bot5582079897:AAFZe2_lC268Djh6YzsAR-XJgt66--zNxDY/getUpdates"};
char* urlEscuchar = {"https://api.telegram.org/bot5582079897:AAFZe2_lC268Djh6YzsAR-XJgt66--zNxDY/getUpdates?offset="};
char* urlHablar = {"https://api.telegram.org/bot5582079897:AAFZe2_lC268Djh6YzsAR-XJgt66--zNxDY/sendMessage?chat_id=1664067026&text="};
char cadena[MAX];

extern void Semaforo();
extern void Bateria();
extern void OlaHumana();
extern void Piedrita();
extern void AutoFantastico();
extern void Carrera();
extern void Choque();

char cadenaRemove[MAX];
char cadenaRescri[MAX];
char primera[MAX];
char segunda[MAX];

int pines[]={14,15,18,23,24,25,8,7};
long int GlobalID = 0;

int bits[8];

void IntToBinario(int n){
    int i=7;
    while(i !=-1){
        bits[i]=n%2;  
        n=n/2; 
        i=i-1;
    }
    for (int x = 0; x<8; x++){
        EncenderLuces(pines[x], bits[x]);
    }
}

char* removerCaracteres(char* caracteres){
    for (int i=2; i<strlen(caracteres) ; i++){
        cadenaRemove[i-2]=caracteres[i];
    }
    return cadenaRemove;
}

void EncenderLuces(int pin, int estado){
    memset(cadenaRescri,0,MAX);
    sprintf(cadenaRescri, "%u", pin);
    memccpy(memccpy(primera, "gpio -g write ", '\0', MAX) - 1, cadenaRescri, '\0', MAX);
	if (estado==1){
        memccpy(memccpy(segunda, primera, '\0', MAX) - 1, " 1", '\0', MAX);
    }
	else{
        memccpy(memccpy(segunda, primera, '\0', MAX) - 1, " 0", '\0', MAX);
		}
	system(segunda);
	memset(primera,0,MAX);
	memset(segunda,0,MAX);
	memset(cadenaRescri,0,MAX);
	}

typedef struct string_buffer_s{
    char * ptr;
    size_t len;
} 
string_buffer_t;

static void string_buffer_initialize( string_buffer_t * sb ){
    sb->len = 0;
    sb->ptr = malloc(sb->len+1);
    sb->ptr[0] = '\0';
}

static void string_buffer_finish( string_buffer_t * sb ){
    free(sb->ptr);
    sb->len = 0;
    sb->ptr = NULL;
}

static size_t string_buffer_callback( void * buf, size_t size, size_t nmemb, void * data ){
    string_buffer_t * sb = data;
    size_t new_len = sb->len + size * nmemb;
    sb->ptr = realloc( sb->ptr, new_len + 1 );
    memcpy( sb->ptr + sb->len, buf, size * nmemb );
    sb->ptr[ new_len ] = '\0';
    sb->len = new_len;
    return size * nmemb;
}

static size_t header_callback(char * buf, size_t size, size_t nmemb, void * data ){
 return string_buffer_callback( buf, size, nmemb, data );
}

static size_t write_callback( void * buf, size_t size, size_t nmemb, void * data ){
 return string_buffer_callback( buf, size, nmemb, data );
}

char* comandos(const char *s){
    const char *DESDE_DONDE = "text";
    const char *HASTA_DONDE1 = ","; //el DESDE y HASTA donde representan parte del objeto json que se forma

    char *target = NULL;
    char *start, *end;

    if ( start = strstr( s, DESDE_DONDE ) )//busca palabras en el texto
    {
        start += strlen( DESDE_DONDE );//da la longitud de la palabra
        if ( end = strstr( start, HASTA_DONDE1 ))
        {
            target=malloc( end - start + 1 ); //reserva en memoria
            memcpy( target, start, end - start );
            target[end - start] = '\0';
        }
    }
    else{
        return NULL;
}
	removerCaracteres(target); 
    return target;
}

char* getUpdateID(const char *s){   	
    const char *DESDE_DONDE = "update_id";
    const char *HASTA_DONDE = ",";
    char *target = NULL;
    char *start, *end;

    if ( start = strstr( s, DESDE_DONDE ) )
    {
        start += strlen( DESDE_DONDE );
        if ( end = strstr( start, HASTA_DONDE ) )
        {
            target = ( char * )malloc( end - start + 1 );
            memcpy( target, start, end - start );
            target[end - start] = '\0';
        }
    }
    removerCaracteres(target);
    char* TextGlobalID;
    
    GlobalID = atoi(cadenaRemove);
    GlobalID=GlobalID+1;
    memset(cadenaRemove,0,MAX);
    sprintf(cadenaRescri, "%u", GlobalID);
    TextGlobalID=cadenaRescri;
    memset(cadena,0,MAX);
    memccpy(memccpy(cadena, urlEscuchar, '\0', MAX) - 1, TextGlobalID, '\0', MAX); //concatena
    char* comando = Interaction(cadena, 3);
    while (comando!=NULL)
    {
        memset(cadenaRescri,0,MAX);
        memset(cadena,0,MAX);
        GlobalID=GlobalID+1;
        sprintf(cadenaRescri, "%u", GlobalID);
        TextGlobalID=cadenaRescri;
        memccpy(memccpy(cadena, urlEscuchar, '\0', MAX) - 1, TextGlobalID, '\0', MAX);
        memset(cadenaRemove,0,MAX);
         comando = Interaction(cadena, 3);
         printf(" comando  --> %s\n", comando );
    }
    memccpy(memccpy(cadena, urlHablar, '\0', MAX) - 1, "Hola, Seleccione uno de los comandos disponibles", '\0', MAX);

    Interaction(cadena, 2);   
    while(comando != "/sa" || comando == NULL){
            memset(cadena,0,MAX);
            memccpy(memccpy(cadena, urlEscuchar, '\0', MAX) - 1, TextGlobalID, '\0', MAX);
			comando = Interaction(cadena, 3);
            printf(" comando  --> %s\n", comando );
			if (comando != NULL){
                GlobalID=GlobalID+1;
                    if(comando[3]=='/' && comando[4]=='s' && comando[5]=='a'){
                    exit(0);}
				if (comando[3]=='/' && comando[4]=='s' && comando[5]=='c'){
                        printf("comando /sc se ejecuto\n\n");
                        memccpy(memccpy(cadena, urlHablar, '\0', MAX) - 1, "Usted ha seleccionado el Semaforo de Carrera", '\0', MAX);
                        Interaction(cadena, 2);
                        Semaforo();
                        IntToBinario(0);
					}
                if (comando[3]=='/' && comando[4]=='b' && comando[5]=='c'){
                        printf("comando /bc se ejecuto \n\n");
                        memccpy(memccpy(cadena, urlHablar, '\0', MAX) - 1, "Usted ha selecionado la Bateria Cargando", '\0', MAX);
                        Interaction(cadena, 2);
						Bateria();
                        IntToBinario(0);
					}
                if (comando[3]=='/' && comando[4]=='a' && comando[5]=='f'){
                        printf("comando /af se ejecuto \n\n");
                        memccpy(memccpy(cadena, urlHablar, '\0', MAX) - 1, "Usted ha selecionado el Auto Fantástico", '\0', MAX);
                        Interaction(cadena, 2);
                        AutoFantastico();
                        IntToBinario(0);
					}
                if (comando[3]=='/' && comando[4]=='c' && comando[5]=='h'){
                        printf("comando /ch se ejecuto \n\n");
                        memccpy(memccpy(cadena, urlHablar, '\0', MAX) - 1, "Usted ha selecionado el Choque", '\0', MAX);
                        Interaction(cadena, 2);
                        Choque();
                        IntToBinario(0);
					}
                if (comando[3]=='/' && comando[4]=='o' && comando[5]=='h'){
                        printf("comando /oh se ejecuto \n\n");
                        memccpy(memccpy(cadena, urlHablar, '\0', MAX) - 1, "Usted ha selecionado la Ola Humana", '\0', MAX);
                        Interaction(cadena, 2);
                        OlaHumana();
                        IntToBinario(0);
					}
                if (comando[3]=='/' && comando[4]=='c' && comando[5]=='a'){
                        printf("comando /ca se ejecuto \n\n");
                        memccpy(memccpy(cadena, urlHablar, '\0', MAX) - 1, "Usted ha selecionado la Carrera", '\0', MAX);
                        Interaction(cadena, 2);
                        Carrera();
                        IntToBinario(0);
					}
                if (comando[3]=='/' && comando[4]=='p' && comando[5]=='i'){
                        printf("comando /pi se ejecuto \n\n");
                        memccpy(memccpy(cadena, urlHablar, '\0', MAX) - 1, "Usted ha selecionado la Piedrita", '\0', MAX);
                        Interaction(cadena, 2);
                        Piedrita();
                        IntToBinario(0);
					}
                memset(cadena,0,MAX);
                memset(cadenaRescri,0,MAX);
                sprintf(cadenaRescri, "%u", GlobalID);
                TextGlobalID=cadenaRescri;
			}
		}
    return target;
}

char* Interaction(char* myurl, int var ){
    CURL * curl;
    CURLcode res;
    string_buffer_t strbuf;

    string_buffer_initialize( &strbuf );
    curl = curl_easy_init();
	
    if(!curl){
        fprintf(stderr, "Fatal: curl_easy_init() error.\n");
        string_buffer_finish( &strbuf );
        return "EXIT_FAILURE";
    }
    curl_easy_setopt(curl, CURLOPT_URL, myurl );
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L );
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback );
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_callback );
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &strbuf );
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &strbuf );
    res = curl_easy_perform(curl);
    
    if( res != CURLE_OK ){
        fprintf( stderr, "Request failed: curl_easy_perform(): %s\n", curl_easy_strerror(res) );
        curl_easy_cleanup( curl );
        string_buffer_finish( &strbuf );
        return "EXIT_FAILURE";
    }
	switch(var){
		case 1: 
                getUpdateID(strbuf.ptr);
				return " ";
				break;
		case 2: 
                return " ";
				break;
		case 3: 
                return comandos(strbuf.ptr);
				break; 
		}
    curl_easy_cleanup( curl );
    string_buffer_finish( &strbuf );
    return "EXIT_SUCCESS";
}

int main(){
    system("gpio -g mode 14 output");
	system("gpio -g mode 15 output");
	system("gpio -g mode 18 output");
	system("gpio -g mode 23 output");
	system("gpio -g mode 24 output");
	system("gpio -g mode 25 output");
	system("gpio -g mode 8 output");
	system("gpio -g mode 7 output");
	Interaction(urlStart, 1);
    return 0;
}