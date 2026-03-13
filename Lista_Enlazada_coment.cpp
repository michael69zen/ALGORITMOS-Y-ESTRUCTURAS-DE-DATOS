#include <iostream> // Biblioteca para entrada y salida
#include <conio.h>  // Biblioteca para usar getch()
using namespace std;

// Definición de la estructura Nodo
struct Nodo{
    int dato; // Valor que guarda el nodo
    Nodo *siguiente; // Puntero al siguiente nodo
};

// Declaración de funciones
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void eliminarNodo(Nodo *&, int);

int main(){
    
    Nodo *lista = NULL; // Puntero que representa el inicio de la lista
    
    int dato; // Variable para guardar números
    char rpt;
    
    // Insertar elementos en la lista
    do{
        cout<<"Digite un numero: ";
        cin>>dato;
       
        insertarLista(lista,dato); // Insertar en la lista
        
        cout<<"\nDesea agregar otro elemento (s/n): ";
        cin>>rpt;
        
    }while((rpt=='s')||(rpt=='S'));
    
    
    // Mostrar lista
    cout<<"\nLista actual:\n";
    mostrarLista(lista);
    
    // Eliminar elemento
    cout<<"\n\nDigite el elemento que desea eliminar: ";
    cin>>dato;
    
    eliminarNodo(lista,dato);
    
    
    // Mostrar lista nuevamente
    cout<<"\nLista despues de eliminar:\n";
    mostrarLista(lista);
    
    
    getch();
    return 0;
}



// Función para insertar un nodo en la lista
void insertarLista(Nodo *&lista, int n){
    
    Nodo *nuevo_nodo = new Nodo(); // Crear nuevo nodo
    nuevo_nodo->dato = n; // Asignar dato
    Nodo *aux1 = lista; // Puntero para recorrer lista
    Nodo *aux2; // Puntero para guardar nodo anterior
    
    // Buscar posición en la lista
    while((aux1 != NULL) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    
    
    // Insertar al inicio
    if(lista == aux1){
        lista = nuevo_nodo;
    }else{
        aux2->siguiente = nuevo_nodo;
    }
    
    nuevo_nodo->siguiente = aux1;
    
    cout<<"Elemento "<<n<<" insertado correctamente\n";
}



// Función para mostrar la lista
void mostrarLista(Nodo *lista){
    
    Nodo *actual = lista;
    
    while(actual != NULL){
        cout<<actual->dato<<" -> ";
        actual = actual->siguiente;
    }
    
    cout<<"NULL\n";
}



// Función para eliminar un nodo
void eliminarNodo(Nodo *&lista, int n){
    
    Nodo *aux_borrar;
    Nodo *anterior = NULL;

    aux_borrar = lista;
    
    // Buscar nodo
    while((aux_borrar != NULL) && (aux_borrar->dato != n)){
        
        anterior = aux_borrar;
        aux_borrar = aux_borrar->siguiente;
        
    }
    
    // Nodo no encontrado
    if(aux_borrar == NULL){
        cout<<"Elemento no encontrado\n";
        return;
    }
    
    // Nodo es el primero
    if(anterior == NULL){
        lista = lista->siguiente;
    }else{
        anterior->siguiente = aux_borrar->siguiente;
    }
    
    delete aux_borrar; // Liberar memoria
    cout<<"Elemento eliminado correctamente\n";
}
