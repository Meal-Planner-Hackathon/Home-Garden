#include <iostream>
#include <string>
using namespace std;

class fruitsandvegetables
{
public:
    void tomato();
    void avocado();
    void almond();
    void potato();
};

class meatsandnuts
{

};
void introduction(){
    cout << "Welcome to our holistic health application: " << endl;
    cout << "Please enter your name:" << std::endl;

    string name;
    cin >> name;
    cout << "Welcome: " << name << endl;
    cout << "Select an item to learn more about it: " << endl;
    cout << "1. Tomatoes " << endl << "2. Avocadoes" << endl << "3. Almonds" << endl << "4. Potatoes" << endl;
    int vegetables;
    cin >> vegetables;
    switch(vegetables) {
        case 1:
            cout << "You selected tomatoes!";
            break;
        case 2:
            cout << "You selected avocadoes!";
            break;
        case 3:
            cout << "You selected almonds!";
            break;
        case 4:
            cout << "You selected potatoes!";
            break;

    }
}


int main() {
    introduction();

    }
