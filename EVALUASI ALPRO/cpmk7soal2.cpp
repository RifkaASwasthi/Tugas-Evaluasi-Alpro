#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Struktur untuk menyimpan informasi hewan (kucing atau anjing) beserta waktu masuk ke selter
struct Animal {
    string type; // "cat" atau "dog"
    int order; // Waktu masuk ke selter (semakin kecil, semakin tua)
};

class AnimalShelter {
private:
    int order; // Variabel untuk menentukan waktu masuk hewan ke selter
    queue<Animal> catQueue; // Queue untuk kucing
    queue<Animal> dogQueue; // Queue untuk anjing

public:
    AnimalShelter() : order(0) {}

    // Menambahkan hewan ke selter
    void enqueue(string type) {
        Animal animal;
        animal.type = type;
        animal.order = order++;
        
        if (type == "cat") {
            catQueue.push(animal);
        } else if (type == "dog") {
            dogQueue.push(animal);
        }
    }

    // Menghapus hewan tertua dari selter
    Animal dequeueAny() {
        if (catQueue.empty()) {
            return dequeueDog();
        } else if (dogQueue.empty()) {
            return dequeueCat();
        } else {
            if (catQueue.front().order < dogQueue.front().order) {
                return dequeueCat();
            } else {
                return dequeueDog();
            }
        }
    }

    // Menghapus kucing tertua dari selter
    Animal dequeueCat() {
        if (!catQueue.empty()) {
            Animal cat = catQueue.front();
            catQueue.pop();
            return cat;
        }
        // Jika tidak ada kucing, kembalikan hewan dengan order yang sangat besar agar tidak dipilih
        return {"", INT_MAX};
    }

    // Menghapus anjing tertua dari selter
    Animal dequeueDog() {
        if (!dogQueue.empty()) {
            Animal dog = dogQueue.front();
            dogQueue.pop();
            return dog;
        }
        // Jika tidak ada anjing, kembalikan hewan dengan order yang sangat besar agar tidak dipilih
        return {"", INT_MAX};
    }
};

int main() {
    AnimalShelter shelter;

    shelter.enqueue("cat");
    shelter.enqueue("dog");
    shelter.enqueue("cat");
    shelter.enqueue("dog");

    Animal adoptedAnimal = shelter.dequeueAny();
    cout << "Hewan yang diadopsi: " << adoptedAnimal.type << endl;

    return 0;
}
