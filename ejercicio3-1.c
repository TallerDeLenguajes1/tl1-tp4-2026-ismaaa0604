#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}Tarea;
typedef struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
}Nodo;
Nodo * CrearListaVacia();
Nodo * CrearTarea(int id, char descripcion[50]);
void InsertarNodo(Nodo ** Start , Nodo *Nodos);
Nodo * QuitarNodo(Nodo **Start, int id);
int main(){
    srand(time(NULL));
    Nodo *Start;
    Nodo *Start1;
    int bandera = 1;
    int ID = 1000, id;
    char descripc[50];
    Start = CrearListaVacia();
    Start = CrearListaVacia();
    while(bandera == 1){
        fflush(stdin);
        printf("Agregue la descripcion de la tarea: \n");

        fgets(descripc, 50, stdin);
        descripc[strcspn(descripc, "\n")] = '\0';
        InsertarNodo(&Start ,CrearTarea(ID,descripc));
        ID++;
        printf("Quiere seguir agregando tareas(1) o finalizar la carga(0)? \n");
        scanf("%d", &bandera);
    }
    bandera = 1;
    while(bandera==1){
        printf("Introduzca el Id de la traea que quiere marcar como realizada: \n");
        scanf("%d",id);
        Nodo *pendiente = QuitarNodo(&Start, id); //retorno del nodo que esta libre, 
        InsertarNodo(&Start1, pendiente);
        printf("Quiere seguir agregando tareas(1) o finalizar la carga(0)? \n");
        scanf("%d", &bandera);
    }
    return 0;
}
Nodo * CrearListaVacia()
{
    return NULL;
}
Nodo * CrearTarea(int id, char descripcion[50]){
    Nodo * tarea = (Nodo *)malloc(sizeof(Nodo));
    tarea->T.TareaID = id;
    int cantidadDeCaracteres = strlen(descripcion);
    tarea->T.Descripcion = (char *)malloc(sizeof(char)*(cantidadDeCaracteres+1));
    strcpy(tarea->T.Descripcion,descripcion);
    tarea->T.Duracion = 10 + rand()%(100-10+1);
    tarea->Siguiente = NULL;
    return tarea;
}
void InsertarNodo(Nodo ** Start , Nodo *Nodos)
{
    Nodos->Siguiente = *Start;
    *Start = Nodos ;
}
Nodo * buscarNodo(Nodo * Start, int IdBuscado){
    Nodo * Aux = Start;
    while(Aux && Aux->T.TareaID != IdBuscado)
    {
    Aux = Aux->Siguiente;
    }
    return Aux;
}
Nodo * QuitarNodo(Nodo **Start, int id){
    Nodo *nodoAux = (*Start);
    Nodo *nodoAnt = NULL;
    while (nodoAux != NULL && nodoAux->T.TareaID != id){
        nodoAnt = nodoAux;
        nodoAux = nodoAux->Siguiente;
    }
    if (nodoAux != NULL){
        if (nodoAux == (*Start)){
            (*Start) = nodoAux->Siguiente;
        }
        else{
            nodoAnt->Siguiente = nodoAux->Siguiente;
        }
        nodoAux->Siguiente = NULL;
    }
    return (nodoAux);
}
