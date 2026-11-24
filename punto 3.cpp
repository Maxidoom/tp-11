#include <iostresam>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

class Empleado {
private:
    string nombre;
    double salario;
    string departamento;

public:
    Empleado(string n, double s, string d) : nombre(n), salario(s), departamento(d) {}

    string getNombre() const { return nombre; }
    double getSalario() const { return salario; }
    string getDepartamento() const { return departamento; }

    void mostrarInfo() const {
        cout << "Nombre: " << nombre 
             << " | Departamento: " << departamento 
             << " | Salario: $" << salario << endl;
    }
};

class Empresa {
private:
    vector empleados;

public:
    
    void agregarEmpleado(const Empleado& emp) {
        empleados.push_back(emp);
        cout << "Empleado '" << emp.getNombre() << "' registrado correctamente."<<endl;
    }

   
    double calcularNominaTotal() const {
        double total = 0.0;
        for (const auto& emp : empleados) {
            total += emp.getSalario();
        }
        return total;
    }

    const Empleado* encontrarMayorSalario() const {
        if (empleados.empty()) {
            return nullptr;
        }

        const Empleado* mayor = &empleados[0];
        for (size_t i = 1; i < empleados.size(); ++i) {
            if (empleados[i].getSalario() > mayor->getSalario()) {
                mayor = &empleados[i];
            }
        }
        return mayor;
    }

    
    void listarPorDepartamento(const string& depto) const {
        cout << "Empleados del departamento de '" << depto <<endl;
        bool encontrado = false;
        for (const auto& emp : empleados) {
            if (emp.getDepartamento() == depto) {
                emp.mostrarInfo();
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "No se encontraron empleados en el departamento de " << depto <<endl;
        }
    }

    void mostrarTodos() const {
        if (empleados.empty()) {
            cout << "No hay empleados registrados en la empresa."<<endl;
            return;
        }
        cout << "lista de empleados";
        for (const auto& emp : empleados) {
            emp.mostrarInfo();
        }
    }
};

int main() {
    Empresa miEmpresa;

    
    miEmpresa.agregarEmpleado(Empleado("Maximo Bianco", 500000.0, "Sistemas"));
    miEmpresa.agregarEmpleado(Empleado("Joaquin Cejas Molina", 380000.0, "Sistemas"));
    miEmpresa.agregarEmpleado(Empleado("Augusto Arjona", 450000.0, "Ventas"));
    miEmpresa.agregarEmpleado(Empleado("Gonzalo Fonseca", 410000.0, "Recursos Humanos"));
  
    miEmpresa.mostrarTodos();

    cout << "Nómina total de la empresa: $" << miEmpresa.calcularNominaTotal() << endl;

    const Empleado* mejorPagado = miEmpresa.encontrarMayorSalario();
    if (mejorPagado != nullptr) {
        cout << "Empleado con mejor salario";
        mejorPagado->mostrarInfo();
    }

   
    miEmpresa.listarPorDepartamento("Sistemas");
    miEmpresa.listarPorDepartamento("Marketing");

    return 0;
}
