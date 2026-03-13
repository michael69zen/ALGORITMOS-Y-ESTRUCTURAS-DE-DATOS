#include <iostream> // Biblioteca estándar para entrada y salida (cin, cout)

#include <conio.h> // Biblioteca usada para funciones de consola como getch() (pausar el programa)

using namespace std; // Permite usar cout y cin sin escribir std::

// Definición de una estructura llamada Nodo
struct Nodo{
    int dato; // Variable que almacenará el valor del nodo
    Nodo *siguiente; // Puntero que guarda la dirección del siguiente nodo en la pila
                     // El símbolo * indica que es un puntero
};

// Declaración de la función agregarPila
// Nodo *& significa referencia a un puntero de tipo Nodo
// Permite modificar directamente la pila original
void agregarPila(Nodo *&, int);

// Declaración de la función sacarPila
// Nodo *& referencia al puntero pila
// int & referencia para devolver el dato eliminado
void sacarPila(Nodo *&, int &);


int main(){ // Función principal donde inicia el programa
    
    Nodo *pila = NULL; // Se crea un puntero llamado pila y se inicializa en NULL (pila vacía)
    int dato; // Variable donde se guardará el número que ingrese el usuario
    char rpt; // Variable para guardar la respuesta del usuario (si desea continuar)
    
    
    do{ // Inicio del ciclo do-while (se ejecuta al menos una vez)
        cout<<"Digite un numero: "; // Muestra un mensaje solicitando un número
        cin>>dato; // Lee el número ingresado por el usuario
        agregarPila(pila,dato); // Llama a la función que agrega el número a la pila
        cout<<"\n Desea agregar otro elemento a PILA (s/n): "; // Pregunta si desea agregar otro elemento
        cin>>rpt; // Lee la respuesta del usuario
    }while((rpt=='S')||(rpt=='s')); // El ciclo continúa si el usuario escribe S o s
    
    
    cout<<"\n Sacando todos los elementos de Pila: "; // Mensaje indicando que se vaciará la pila
    
    
    while(pila != NULL){ // Mientras la pila no esté vacía
        
        sacarPila(pila,dato); // Se llama a la función que elimina el nodo superior
        
        if(pila != NULL){ // Si todavía quedan elementos en la pila
            cout<<dato<<" , "; // Imprime el dato seguido de una coma
        }else{ // Si es el último elemento
            cout<<dato<<"."; // Imprime el dato seguido de un punto
        }
    }
    
    getch(); // Espera que el usuario presione una tecla antes de cerrar el programa
    return 0; // Indica que el programa terminó correctamente
}


// Función que agrega un nuevo elemento a la pila
void agregarPila(Nodo *&pila, int n){
    
    Nodo *nuevo_nodo = new Nodo(); // Se reserva memoria para crear un nuevo nodo
    nuevo_nodo -> dato=n; // Se guarda el valor n dentro del nodo
    nuevo_nodo -> siguiente=pila; // El nuevo nodo apunta al nodo que antes era la cima de la pila
    pila = nuevo_nodo; // La pila ahora apunta al nuevo nodo (se convierte en la nueva cima)
    cout<<"\tElemento "<<n<<" ha sido agregado a PILA correctamente"; // Mensaje confirmando la inserción
}


// Función que elimina el elemento superior de la pila
void sacarPila(Nodo *&pila, int &n){
    
    Nodo *aux = pila; // Se crea un puntero auxiliar que apunta al nodo superior
    n = aux -> dato; // Se guarda el dato del nodo que se eliminará
    pila = aux -> siguiente; // La pila ahora apunta al siguiente nodo
    delete aux; // Se libera la memoria del nodo eliminado
    
}
