#include    <iostream>
using namespace std;

//man sortere et array ved at bruge bubble sort algoritmen
//bubble sort fungere ved at gentagne gange at bytte tilstødende elementer hvis de er i forkert rækkefølge


 void sort (int array[], int size);

int main () {
    
    int array[] = {10, 15, 2, 8, 7, 4};
    int size = sizeof(array) / sizeof(array[0]);

    sort(array, size);

    for (int element : array) {
        cout << element << " ";
    }
    
    return 0;
}

void sort (int array[], int size) {
    int temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(array[j] > array [j + 1]) {
                //bytte elementer
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}