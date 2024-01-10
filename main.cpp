#include <iostream>
#include <string>
#include <vector>

// Clasa Student
class Student {
private:
    std::string nume;
    int varsta;
    std::string nivel;

public:
    // Constructor de inițializare
    Student(const std::string& nume, int varsta, const std::string& nivel) : nume(nume), varsta(varsta), nivel(nivel) {
        //std::cout<<"Con de init!";
    }

    // Constructor de copiere
    Student(const Student& other) : nume(other.nume), varsta(other.varsta), nivel(other.nivel) {
        //std::cout<<"con de copi!";
    }

    // Operator= de copiere
    Student& operator=(const Student& other) {
        //std::cout<<"oper = de copi!";
        if (this != &other) {
            nume = other.nume;
            varsta = other.varsta;
            nivel = other.nivel;
        }
        return *this;
    }

    // Destructor
    ~Student() {}

    // Operator<< pentru afișare
    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << "Nume Student: " << student.nume << ", Varsta Student: " << student.varsta << ", Nivel Student: " << student.nivel << "\n";
        return os;
    }


    void promovareNivel(const std::string& nivelNou) {
        nivel = nivelNou;
    }

    std::string getNume() const {
        return nume;
    }

    int getVarsta() const {
        return varsta;
    }
};

// Clasa Antrenor
class Antrenor {
private:
    std::string nume;
    int aniExperienta;

public:
    // Constructor de inițializare
    Antrenor(const std::string& nume, int aniExperienta) : nume(nume), aniExperienta(aniExperienta) {
        //std::cout<<"Con de init!";
    }

    // Constructor de copiere
    Antrenor(const Antrenor& other) : nume(other.nume), aniExperienta(other.aniExperienta) {
        //std::cout<<"con de copi!";
    }

    // Operator= de copiere
    Antrenor& operator=(const Antrenor& other) {
        //std::cout<<"oper = de copi!";
        if (this != &other) {
            nume = other.nume;
            aniExperienta = other.aniExperienta;
        }
        return *this;
    }

    // Destructor
    ~Antrenor() {}

    // Operator<< pentru afișare
    friend std::ostream& operator<<(std::ostream& os, const Antrenor& antrenor) {
        os << "Nume: " << antrenor.nume << ", Ani de experienta: " << antrenor.aniExperienta << "\n";
        return os;
    }


    void schimbaExperienta(int aniNou) {
        aniExperienta = aniNou;
    }

    std::string getNume() const {
        return nume;
    }
};

// Clasa Programare
class Programare {
private:
    Antrenor antrenor;
    std::vector<Student> studenti;
    std::string data;
    std::string ora;

public:
    // Constructor de inițializare
    Programare(const Antrenor& antrenor, const std::vector<Student>& studenti, const std::string& data, const std::string& ora)
            : antrenor(antrenor), studenti(studenti), data(data), ora(ora) {
        //std::cout<<"Con de init!";
    }

    // Constructor de copiere
    Programare(const Programare& other)
            : antrenor(other.antrenor), studenti(other.studenti), data(other.data), ora(other.ora) {
        //std::cout<<"con de copi!";
    }

    // Operator= de copiere
    Programare& operator=(const Programare& other) {
        //std::cout<<"oper = de copi!";
        if (this != &other) {
            antrenor = other.antrenor;
            studenti = other.studenti;
            data = other.data;
            ora = other.ora;
        }
        return *this;
    }

    // Destructor
    ~Programare() {}

    // Operator<< pentru afișare
    friend std::ostream& operator<<(std::ostream& os, const Programare& programare) {
        os << "Antrenor: " << programare.antrenor.getNume() << ", Data: " << programare.data << ", Ora: " << programare.ora << "\nStudenti: ";
        for (const auto& student : programare.studenti) {
            os << student.getNume() << "\n";
        }

        return os;
    }


    void adaugaStudent(const Student& student) {
        studenti.push_back(student);
    }

    void schimbaData(const std::string& dataNoua) {
        data = dataNoua;
    }

    void schimbaOra(const std::string& oraNoua) {
        ora = oraNoua;
    }
};

// Clasa Antrenament
class Antrenament {
private:
    Programare programare;
    std::string tipAntrenament;
    int durata; // în minute

public:
    // Constructor de inițializare
    Antrenament(const Programare& programare, const std::string& tipAntrenament, int durata)
            : programare(programare), tipAntrenament(tipAntrenament), durata(durata) {
        //std::cout<<"Con de init!";
    }

    // Constructor de copiere
    Antrenament(const Antrenament& other)
            : programare(other.programare), tipAntrenament(other.tipAntrenament), durata(other.durata) {
       // std::cout<<"con de copi!";
    }

    // Operator= de copiere
    Antrenament& operator=(const Antrenament& other) {
        //std::cout<<"oper = de copi!";
        if (this != &other) {
            programare = other.programare;
            tipAntrenament = other.tipAntrenament;
            durata = other.durata;
        }
        return *this;
    }

    // Destructor
    ~Antrenament() {}

    // Operator<< pentru afișare
    friend std::ostream& operator<<(std::ostream& os, const Antrenament& antrenament) {
        os << "Programare: " << antrenament.programare << "Tip Antrenament: " << antrenament.tipAntrenament << ", Durata: " << antrenament.durata << " minute" << "\n";
        return os;
    }


    void schimbaTip(const std::string& tipNou) {
        tipAntrenament = tipNou;
    }

    void schimbaDurata(int durataNoua) {
        durata = durataNoua;
    }
};

// Funcția main
int main() {
    
    Student student1("Ion Popescu", 20, "Incepator");
    Student student2("Maria Ionescu", 25, "Intermediar");
    Antrenor antrenor1("Mihai Ionescu", 5);

    std::vector<Student> studenti;
    studenti.push_back(student1);
    studenti.push_back(student2);

    Programare programare1(antrenor1, studenti, "2024-01-15", "10:00");
    Antrenament antrenament1(programare1, "Judo", 60);

    std::cout << student1 << std::endl;
    std::cout << antrenor1 << std::endl;
    std::cout << programare1 << std::endl;
    std::cout << antrenament1 << std::endl;

    
    student1.promovareNivel("Avansat");
    antrenor1.schimbaExperienta(6);
    programare1.adaugaStudent(Student("George Vasile", 22, "Incepator"));
    antrenament1.schimbaTip("Karate");

    std::cout << student1 << std::endl;

    return 0;
}
