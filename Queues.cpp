#include <iostream>
using namespace std;

class Queues{
    private:
        static const int max = 5;   //nilai tidak akan pernah berubah//
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
                cout << "\nQueue Overflow\n";   //1.a
                return;                         //1.b
            }

            //2. Cek apakah antrian kosong
            if (FRONT == -1){
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
            if (FRONT == REAR){
                FRONT = -1;
                REAR = -1;
            }
            else{
                //Jika elemen yang dihapus di posisi terakhir array kembali ke awal array
                if (FRONT == max -1)
                    FRONT = 0;
                else
                    FRONT = FRONT + 1;
            }
        }

        void display(){
            int FRONT_position = FRONT; //sebetulnya ga perlu, sebagai penanda posisi front atau rear
            int REAR_position = REAR;

            //Cek apakah Antrian kosong
            if (FRONT == -1){
                cout << "Queue is Empty\n";
                return;
            }

            cout << "\nELement in the queue are...\n";

            //Jika Front_position <= REAR_position, iterasi dari FRONT hingga REAR
            //kondisi belum terjadinya circular. FRONT lebih kecil daripada REAR. Tinggal baca dari front ke rear
            if (FRONT_position <= REAR_position){
                while (FRONT_position <= REAR_position){
                    cout << queue_array[FRONT_position] << "  ";
                    FRONT_position++;
                }
                cout << endl;
            }
            else{
                //Jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
                //sudah terjadi circular queues. JIka Front lebih besar dari REAR
                //dibaca dulu dari front sampai n-1. lalu si front dijadikan = 0. 
                //lalu dibiaca sampai rear.
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
        //sebetulnya sama fungsinya di default
        //ketika ada hal-hal yang tidak diketahui errornya kenapa
        catch(exception &e){
            cout << "Check for the values entered." << endl;
            //cout << e.what() << endl; //membaca error yang tidak terbaca di default
        }
    }
    return 0;
}