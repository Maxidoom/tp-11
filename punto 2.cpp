#include <iostresam>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

class Mesa {
private:
    int numero;
    int capacidad;
    bool ocupada;

public:
    Mesa(int num, int cap) : numero(num), capacidad(cap), ocupada(false) {}

    int getNumero() const { return numero; }
    int getCapacidad() const { return capacidad; }
    bool estaOcupada() const { return ocupada; }

    void ocupar() { ocupada = true; }
    void liberar() { ocupada = false; }

    void mostrarInfo() const {
        cout << "Mesa #" << numero 
             << " | Capacidad: " << capacidad << " comensales"
             << " | Estado: " << (ocupada ? "Ocupada" : "Libre") << endl;
    }
};

class Restaurante {
private:
    vector mesas;

public:
  
    void agregarMesa(const Mesa& mesa) {
        mesas.push_back(mesa);
    }

    
    bool reservarMesa(int comensales) {
        for (auto& mesa : mesas) {
            
            if (!mesa.estaOcupada() && mesa.getCapacidad() >= comensales) {
                mesa.ocupar();
                cout << "Mesa #" << mesa.getNumero() 
                     << " reservada con éxito para " << comensales << " personas."<<endl;
                return true;
            }
        }
        cout << "No hay mesas libres con capacidad suficiente para " << comensales << " personas."<<endl;
        return false;
    }

    
    bool liberarMesa(int numeroMesa) {
        for (auto& mesa : mesas) {
            if (mesa.getNumero() == numeroMesa) {
                if (mesa.estaOcupada()) {
                    mesa.liberar();
                    cout << "Mesa #" << numeroMesa << " liberada con éxito."<<endl;
                    return true;
                } else {
                    cout << "La mesa #" << numeroMesa << " ya estaba libre."<<endl;
                    return false;
                }
            }
        }
        cout << "La mesa #" << numeroMesa << " no existe en el restaurante."<<endl;
        return false;
    }

   
    int obtenerMesasLibres() const {
        int contador = 0;
        for (const auto& mesa : mesas) {
            if (!mesa.estaOcupada()) {
                contador++;
            }
        }
        return contador;
    }

    
    void mostrarEstado() const {
        cout << "Estado del restaurante"<<endl;
        for (const auto& mesa : mesas) {
            mesa.mostrarInfo();
        }
        cout << "Total de mesas libres: " << obtenerMesasLibres() << endl;
    }
};

int main() {
    Restaurante miRestaurante;

    
    miRestaurante.agregarMesa(Mesa(1, 2));
    miRestaurante.agregarMesa(Mesa(2, 4));
    miRestaurante.agregarMesa(Mesa(3, 4));
    miRestaurante.agregarMesa(Mesa(4, 6));

    
    miRestaurante.mostrarEstado();

    cout << "Realizando reservas";
    miRestaurante.reservarMesa(3);
    miRestaurante.reservarMesa(5);
    miRestaurante.reservarMesa(4);
    miRestaurante.mostrarEstado();
    miRestaurante.reservarMesa(4);
    cout << "Liberando mesa"<<endl;
    miRestaurante.liberarMesa(2);

    miRestaurante.mostrarEstado();

    return 0;
}
