#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
class Libro {
private:
    string titulo;
    string autor;
    int paginas;

public:
    Libro(string t, string a, int p) : titulo(t), autor(a), paginas(p) {}

    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    int getPaginas() const { return paginas; }

    void mostrarInfo() const {
        cout << "Titulo: " << titulo << " | Autor: " << autor << " | Paginas: " << paginas << endl;
    }
};

class Biblioteca {
private:
    vector<Libro> libros;

public:
    void agregarLibro(const Libro& libro) {
        libros.push_back(libro);
        cout << "Libro '" << libro.getTitulo() << "' agregado correctamente."<<endl;
    }

    bool eliminarLibro(const string& titulo) {
        for (auto it = libros.begin(); it != libros.end(); ++it) {
            if (it->getTitulo() == titulo) {
                libros.erase(it);
                cout << "Libro '" << titulo << "' eliminado correctamente."<<endl;
                return true;
            }
        }
        cout << "No se encontró el libro '" << titulo << "' para eliminar."<<endl;
        return false;
    }

    const Libro* buscarLibro(const string& titulo) const {
        for (const auto& libro : libros) {
            if (libro.getTitulo() == titulo) {
                return &libro;
            }
        }
        return nullptr;
    }

    int calcularTotalPaginas() const {
        int total = 0;
        for (const auto& libro : libros) {
            total += libro.getPaginas();
        }
        return total;
    }

    void mostrarCatalogo() const {
        if (libros.empty()) {
            cout << "La biblioteca esta vacia."<<endl;
            return;
        }
        cout << "Catalogo de biblioteca"<<endl;
        for (const auto& libro : libros) {
            libro.mostrarInfo();
        }
    }
};
int main() {
    Biblioteca miBiblioteca;

    miBiblioteca.agregarLibro(Libro("El Nombre del Viento", "Patrick Rothfuss", 880));
    miBiblioteca.agregarLibro(Libro("Kiki Entregas a Domicilio", "Eiko Kadono", 193));
    miBiblioteca.agregarLibro(Libro("El Temor de un Hombre Sabio", "Patrick Rothfuss", 1200));
    miBiblioteca.mostrarCatalogo();

    cout << "Total de paginas en la biblioteca: " << miBiblioteca.calcularTotalPaginas() << endl;

    cout << "Buscar Libro"<<endl;
    string tituloBuscar = "El Aleph";
    const Libro* hallado = miBiblioteca.buscarLibro(tituloBuscar);
    if (hallado != nullptr) {
        cout << "Libro encontrado";
        hallado->mostrarInfo();
    } else {
        cout << "El libro '" << tituloBuscar << "' no esta en la biblioteca."<<endl;
    }

    cout << "eliminar libro"<<endl;
    miBiblioteca.eliminarLibro("Cien años de soledad");

    miBiblioteca.mostrarCatalogo();
    cout << "Nuevo total de paginas: " << miBiblioteca.calcularTotalPaginas() << endl;

    return 0;
}
