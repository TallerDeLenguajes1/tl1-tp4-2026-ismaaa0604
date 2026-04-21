#include<stdio.h>
struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
};
struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
};
int main(){
    struct Cliente cliente;
    struct Producto producto;
    int clientes;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    printf("Ingrese la cantidad de clientes(hasta 5): \n");
    scanf("%d", &clientes);
    for (int i = 0; i< clientes; i++){
        cliente.ClienteID = i;
        gets(cliente.NombreCliente[i]);
        cliente.CantidadProductosAPedir = 1 + rand() % (5-1+1);
        cliente.Productos = (struct Producto*) malloc (sizeof(struct Producto)* cliente.CantidadProductosAPedir);
    }
    return 0;
}