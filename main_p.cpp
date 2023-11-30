#include<iostream>
#include<queue>
#include<vector>
#include<fstream>

using namespace std;
// g++ main_p.cpp -o main_p
//./main_p
struct contacto {
    string num;
    string name;
    string rs;
    string direccion;
    string icon;
};
void ingresarContacto(queue<contacto>& cola) {
    vector<string> iconos {"☢", "❆", "🎵", "☀", "☁", "♞", "♕", "❤", "✈"};
    
    contacto persona;

    cout << "Numero: ";
    cin >> persona.num;
    cout << "Nombre: ";
    cin >> persona.name;
    for (int i = 0; i < persona.name.length(); i++) {
    
    persona.name[i] = tolower(persona.name[i]);
    }
    cout << "Redes sociales: ";
    cin >> persona.rs;
    cout << "Direccion: ";
    cin >> persona.direccion;

    cout << "Selecciona una opción:" << endl;
    for (int i = 0; i < iconos.size(); ++i) {
        std::cout << i + 1 << ". " << iconos[i] << std::endl;
    }
    int opcion;
    cin >> opcion;
    
    persona.icon=iconos[opcion-1];

    cola.push(persona);
}

void imprimirtodo(queue<contacto>& cola) {
    queue<contacto> copiac; 
    while (!cola.empty()) {
        cout << cola.front().icon << endl;
        cout << "Numero: " << cola.front().num << endl;
        cout << "Nombre: " << cola.front().name << endl;
        cout << "Redes Sociales: " << cola.front().rs << endl;
        cout << "Direccion: " << cola.front().direccion << endl;
        cout <<endl;
        copiac.push(cola.front()); 
        cola.pop();
    }
    cola = copiac;   
}

void eliminarContacto(queue<contacto>& cola, const string& nombre) {
    queue<contacto> copiac;  

    while (!cola.empty()) {
        if (cola.front().name != nombre) {
            copiac.push(cola.front());  
        }
        cola.pop(); 
    }

    cola = copiac;  
}

void buscarNombre(queue<contacto>& cola, const string& nombre, queue<contacto>& frecuentes) {
    queue<contacto> copiac;
    bool n = false;

    while (!cola.empty()) {
        if (cola.front().name == nombre) {
            frecuentes.push(cola.front());

            cout << cola.front().icon << endl;
            cout << "Numero: " << cola.front().num << endl;
            cout << "Nombre: " << cola.front().name << endl;
            cout << "Redes Sociales: " << cola.front().rs << endl;
            cout << "Direccion: " << cola.front().direccion << endl;
            n = true;
        }

        copiac.push(cola.front());
        cola.pop();
    }

    cola = copiac;

    if (!n) {
        cout << "No existe" << nombre << endl;
    }
}
/*void buscarLetra(queue<contacto>& cola, char letra) {
    queue<contacto> copiac;
    bool n = false;

    while (!cola.empty()) {
        if (cola.front().name[0] == letra) {
            cout << cola.front().icon << endl;
            cout << "Numero: " << cola.front().num << endl;
            cout << "Nombre: " << cola.front().name << endl;
            cout << "Redes Sociales: " << cola.front().rs << endl;
            cout << "Direccion: " << cola.front().direccion << endl;
            n = true;
        }

        copiac.push(cola.front());
        cola.pop();
    }

    cola = copiac;

    if (!n) {
        cout << "No existe contactos" << letra << endl;
    }
}*/
void buscarLetra(queue<contacto>& cola, char letra) {
    queue<contacto> copiac;
    bool encontrado = false;

    while (!cola.empty()) {
        
        string nombreEnMinusculas = cola.front().name;
        for (char& caracter : nombreEnMinusculas) {
            caracter = tolower(caracter);
        }

        if (nombreEnMinusculas.find(tolower(letra)) != string::npos) {
            
            cout << cola.front().icon << endl;
            cout << "Numero: " << cola.front().num << endl;
            cout << "Nombre: " << cola.front().name << endl;
            cout << "Redes Sociales: " << cola.front().rs << endl;
            cout << "Direccion: " << cola.front().direccion << endl;
            encontrado = true;
        }

        copiac.push(cola.front());
        cola.pop();
    }

    cola = copiac;

    if (!encontrado) {
        cout << "No se encontraron contactos con la letra: " << letra << endl;
    }
}
void escribirEnArchivo(queue<contacto> cola, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);



    if (archivo.is_open()) {
        while (!cola.empty()) {
            archivo << "Icono: " << cola.front().icon << endl;
            archivo << "Numero: " << cola.front().num << endl;
            archivo << "Nombre: " << cola.front().name << endl;
            archivo << "Redes Sociales: " << cola.front().rs << endl;
            archivo << "Direccion: " << cola.front().direccion << endl;
            archivo << endl;

            cola.pop();
        }

        archivo.close();
        cout << "Contactos escritos en el archivo " << nombreArchivo << endl;
    } else {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }
}

void imprimirFrecuentes(queue<contacto>& frecuentes) {
    if (frecuentes.empty()) {
        cout << "No hay contactos frecuentes." << endl;
        return;
    }

    cout << "Contactos Frecuentes:" << endl;
    while (!frecuentes.empty()) {
        cout << frecuentes.front().icon << endl;
        cout << "Numero: " << frecuentes.front().num << endl;
        cout << "Nombre: " << frecuentes.front().name << endl;
        cout << "Redes Sociales: " << frecuentes.front().rs << endl;
        cout << "Direccion: " << frecuentes.front().direccion << endl;
        cout << endl;

        frecuentes.pop();
    }
}



int main() {
    queue<contacto> cola1; //cola contactos
    int eleccion; //eleccion en la interfaz
    string contacto_dlt; //contacto para eliminar
    string contacto_busc; //contacto para buscar
    queue<contacto> frecuentes;//frecuentes
    char letra_busc; //letra para buscar contacto
    int cont=0; //contador de contactos
    

    while(eleccion!=8){
    std::cout << "-------------------------libreta contactos-------------------------" << std::endl;
    std::cout << "\n1 Agregar contacto\t\t   5 Buscar por letra\n";
    std::cout << "2 Eliminar contacto\t\t   6 Realizar copia de seguridad\n";
    std::cout << "3 Buscar por nombre\t\t   7 frecuentes\n";
    std::cout << "4 Todos los contactos\t\t  8 salir\n";
    std::cout << "contactos totales: "<< cont <<endl;
    std::cout << "\n-------------------------------------------------------------------" << std::endl;
    

    cout << "Selecciona una opción: ";
    cin >> eleccion;
    
    switch(eleccion) {
        case 1:
            ingresarContacto(cola1);
            cont++;
            break;
        case 2:
            cout<<"Nombre del contacto a eliminar:";
            cin>>contacto_dlt;
            eliminarContacto(cola1,contacto_dlt);
            cont--;
            break;
        case 3:
            cout << "Ingrese el nombre del contacto a buscar: ";
            cin >> contacto_busc;
            buscarNombre(cola1, contacto_busc, frecuentes);
            break;
        case 4:
            imprimirtodo(cola1);
            break;
        case 5:
            cout << "Ingrese la letra del contacto a buscar: ";
            cin >> letra_busc;
            buscarLetra(cola1,letra_busc);
            break;
        case 6:
            escribirEnArchivo(cola1, "contactos.txt");
            break;
        case 7:
            imprimirFrecuentes(frecuentes);
            break;  
            
        case 8:
            cout<<"adios"<<endl;
            break;    
        default:
            cout << "Opción no válida." << endl;
    }//switch
    }//while
    return 0;
}
