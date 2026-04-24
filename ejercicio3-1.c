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
void Mostrar(Nodo * Start);
int main(){
    srand(time(NULL));
    Nodo *Start;
    Nodo *Start1;
    int bandera = 1;
    int ID = 1000, id;
    char descripc[50];
    Start = CrearListaVacia();
    Start1 = CrearListaVacia();
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
    printf("----Lista de tareas pendientes: -------\n\n");
    Mostrar(Start);
    bandera = 1;
    while(bandera==1){
        printf("Introduzca el Id de la tarea que quiere marcar como realizada: \n");
        scanf("%d",&id);
        Nodo *pendiente = QuitarNodo(&Start, id); //retorno del nodo que esta libre, que es apuntado por el puntero que devuelve quitarnodo y este nodo apunta al nulo
        InsertarNodo(&Start1, pendiente); //inserto el nodo libre
        printf("Quiere seguir agregando tareas(1) o finalizar la carga(0)? \n");
        scanf("%d", &bandera);
    }
    printf("----Lista de tareas realizadas: -------\n\n");
    Mostrar(Start1);
    return 0;
}
void Mostrar(Nodo * Start){
    Nodo *aux = Start;
    while(aux != NULL){
        printf("El Id de la tarea es: %d \n",aux->T.TareaID);
        printf("La descripcion de esta tarea es: %s \n",aux->T.Descripcion);
        printf("La duracion de esta tarea es: %d \n",aux->T.Duracion);
        print("\n\n");
        aux = aux->Siguiente;
    }
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
    Nodo *nodoAux = (*Start); //(*Start): Porque (*Start) contiene la dirección de memoria del primerísimo nodo de la lista. 
    //Al igualarlos, estás colocando a tu explorador en la casilla de salida, listo para empezar a caminar
    Nodo *nodoAnt = NULL; //el nodo anterior apunta al nulo
    while (nodoAux != NULL && nodoAux->T.TareaID != id){ //mientras el nodoaux no llegue al final de la lista y no se encuentre el dato
        nodoAnt = nodoAux; // el ant apunta al primer nodo ahora
        nodoAux = nodoAux->Siguiente; // el aux ahora pasa a apuntar al siguiente nodo, osea al segundo o al nulo
    }
    if (nodoAux != NULL){
        if (nodoAux == (*Start)){ // si el nodo buscado es el primer nodo
            (*Start) = nodoAux->Siguiente; //hacemos que el puntero principal apunte al siguiente nod y dej libre al primero
        }
        else{
            nodoAnt->Siguiente = nodoAux->Siguiente; // si esta en el medio o al ultimo hacemos que el anterior apunte al siguiente
        }
        nodoAux->Siguiente = NULL; //hacemos que el nodo apunte al nulo para evitar traer lo que seguia despues de el
    }
    return (nodoAux);
}
