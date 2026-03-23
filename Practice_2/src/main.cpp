#include "survivor.h"
#include "tribe.h"

Survivor* readSurvivor( );
void readTribe( Tribe& t);

int main() {

   
   {
      Tribe t1(10), t2(20);

   
    cout << "Enter data for first tribe:\n";
    readTribe(t1);

    cout << "Enter data for second tribe:\n";
    readTribe(t2);

    t1.print();
    t2.print();
   
   }

      return 0;
};


Survivor* readSurvivor(){
    char name[20];
    cin.ignore();

    cout << "Enter your name: ";
    cin.getline(name, 20);

    int age;
    cout << "Enter your age: ";
    cin >> age;

    int statusNumber;
    cout << "Enter your status: \n 1.Single \n 2.Married \n 3.In a relationship \n";
    cin >> statusNumber;

    return new Survivor(name, age, (Survivor::eStatus) statusNumber);
}

void readTribe( Tribe& t){
    bool toContinue = true;
    int indicator;

    int maxSurvivors = t.getMaxSurvivors();

    for( int i =0; i<maxSurvivors && toContinue; i++){
        Survivor* s = readSurvivor();
        t.addSurvivor(*s);

        cout << "Continue? Press 1 for yes or 2 for no.\n";
        cin >> indicator;

        if(indicator==2){
            toContinue=false;
        }

    }
}