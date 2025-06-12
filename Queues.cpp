#include <iostream>
using namespace std;

class Queues{
    private:
        static const int max = 5;
        int FRONT, REAR;
        int queue_array[5];
    public:
        Queues(){
            FRONT = -1;
            REAR = -1;
        }
        void insert(){
            int num;
            cout << "Enter a Number: ";
            cin >> num;
            cout << endl;

            //1. Cek apakah antrian penuh
            if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)){
                cout << "\nQueue Overflow\n"; //1.a
                return;                         //1.b
            }

            //2. Cek apakah antrian kosong
            if (FRONT == 0){
                FRONT = 0;  //2.a
                REAR = 0;   //2.b
            }
            else {
                //Jika REAR berada di posisi terakhir array, kembali ke awal array
                if (REAR == max - 1)
                    REAR = 0;
                else
                    REAR + 1;
            }
            queue_array[REAR] = num;
        }

        void remove(){
            //Cek apakah antrian kosong
            if (FRONT == -1){
                cout << "Queues Underflow\n"; 
                return;
            }
            cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

            //Cek jika antrian hanya memeiliki satu elemen
            if (FRONT == REAR)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }

        void display(){
            int FRONT_position = FRONT;
            int REAR_position = REAR;

            //Cek apakah Antrian kosong
            if (FRONT == -1){
                cout << "Queue is Empty\n";
                return;
            }

            cout << "\nELement in the queue are...\n";

            //Jika Front_position <= REAR_position, iterasi dari FRONT hingga REAR
            if (FRONT_position <= REAR_position){
                while (FRONT_position <= REAR_position){
                    cout << queue_array[FRONT_position] << "  ";
                    FRONT_position++;
                }
                cout << endl;
            }
            else{
                //Jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
                while(FRONT_position <= max -1){
                    cout << queue_array[FRONT_position] << "  ";
                    FRONT_position++;
                }

                FRONT_position = 0;
                while (FRONT_position <= REAR_position){
                    cout << queue_array[FRONT_position] << "  ";
                    FRONT_position++;
                }
                cout << endl;
            }
        }
};

int main(){
    Queues q;
    char ch;

    while (true){
        try{
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display Values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter Your Choice (1 - 4): " << endl;
            cin >> ch;
            cout << endl;

            switch (ch){
                case '1':{
                    q.insert();
                    break;
                }
                case '2':{
                    q.remove();
                    break;
                }
                case '3':{
                    q.display();
                    break;
                }
                case '4':{
                    return 0;
                }
                default:{
                    cout << "Invalid Option!!" << endl;
                    break;
                }
            }
        }
        catch(exception &e){
            cout << "Check for the values entered." << endl;
        }
    }
}