#include <iostream>
#include <string>
using namespace std;

class Pet {
   public:
      Pet(string petName = "NoName", int yearsOld = -1);
      void Print();

    private:
      string name;
      int age;
};

Pet::Pet(string petName, int yearsOld) {
   name = petName;
   age = yearsOld;
}

void Pet::Print() {
   cout << name << ", " << age << endl;
}

int main() {
   Pet dog;
   Pet cat("Leo");
   Pet bird("Coco", 9);

   cat.Print();
   dog.Print();
   bird.Print();

   return 0;
}