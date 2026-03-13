#include <iostream> // Biblioteca para entrada y salida de datos (cin, cout)
#include <conio.h>  // Biblioteca para usar getch()
using namespace std; // Permite usar cout y cin sin escribir std::

// Definición de la estructura Nodo
struct Nodo{
    int dato; // Variable donde se guarda el valor del nodo
    Nodo *siguiente; // Puntero que guarda la dirección del siguiente nodo
};


// Declaración de funciones
void insertarLista(Nodo *&, int); // Inserta nodos en la lista
void mostrarLista(Nodo *); // Muestra todos los elementos


int main(){
    
    Nodo *lista = NULL; // Puntero que representa el inicio de la lista
    
    int dato; // Variable para guardar números ingresados
    char rpt; // Variable para repetir el proceso
    
    
    do{
        cout<<"Digite un numero: "; // Solicita un número al usuario
        cin>>dato; // Lee el número
        insertarLista(lista,dato); // Inserta el número en la lista
        cout<<"\nDesea agregar otro elemento (s/n): ";
        cin>>rpt; // Lee la respuesta
    }while((rpt=='s') || (rpt=='S')); // Repite mientras el usuario escriba s o S
    
    cout<<"\nMostrando elementos de la lista:\n";
    
    mostrarLista(lista); // Muestra todos los nodos de la lista
    
    getch(); // Pausa el programa
    return 0; // Finaliza el programa
    
}


// Función para insertar un nodo en la lista
void insertarLista(Nodo *&lista, int n){
    
    Nodo *nuevo_nodo = new Nodo(); // Se reserva memoria para un nuevo nodo
    
    nuevo_nodo->dato = n; // Se asigna el valor al nodo
    
    Nodo *aux1 = lista; // Puntero auxiliar para recorrer la lista
    Nodo *aux2; // Puntero que guardará la posición anterior
    
    // Recorrer la lista para encontrar la posición de inserción
    while((aux1 != NULL) && (aux1->dato < n)){
        aux2 = aux1; // aux2 sigue a aux1
        aux1 = aux1->siguiente; // Avanza al siguiente nodo
    }
    
    // Insertar al inicio de la lista
    if(lista == aux1){
        lista = nuevo_nodo; // El nuevo nodo se convierte en el primero
    }else{
        aux2->siguiente = nuevo_nodo; // El nodo anterior apunta al nuevo nodo
    }
    
    nuevo_nodo->siguiente = aux1; // El nuevo nodo apunta al nodo siguiente
    
    cout<<"Elemento "<<n<<" insertado correctamente\n";
}


// Función para mostrar los elementos de la lista
void mostrarLista(Nodo *lista){
    Nodo *actual = lista; // Puntero auxiliar que recorre la lista
    
    while(actual != NULL){ // Mientras no se llegue al final
        cout<<actual->dato<<" -> "; // Muestra el dato del nodo
        actual = actual->siguiente; // Avanza al siguiente nodo
    }
    
    cout<<"NULL"; // Indica el final de la lista
}
