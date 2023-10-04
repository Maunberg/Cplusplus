#include <iostream>
#include <limits>
using namespace std;

int mistake_int() {
  int value;
  cin >> value;
    while (cin.fail()) {
      cout << "Ошибка. Введите число ещё раз: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin >> value;
    }
  return value;
}

int* createArray(int size) {
  int* massiv = new int[size];
  int element;
  cout << "Введите элементы массива через Enter:" << endl;
  for (int i=0; i<size; i++){
      element = mistake_int();
      massiv[i] = element;
    }
  cout << "Массив создан: ";
  for (int i = 0; i < size; i++) {
        cout << massiv[i] << " ";
    }
  cout << endl;
  return massiv;
}

int check_for(int* massiv, int size) {
  int maxim = -2147483648;
  for (int i = 0; i < size; i++) {
    if (maxim < massiv[i]) {
      maxim = massiv[i];
    }
  }
  return maxim;
}

int check_do_while(int* massiv, int size) {
  int maxim = -2147483648;
  int i = 0;
  if(size > 0) {
    do {
      if (maxim < massiv[i]) {
        maxim = massiv[i];
      }
      i++;
    } while (i < size);
  }  
  return maxim;
}

int check_while(int* massiv, int size) {
  int maxim = -2147483648;
  int i = 0;
  while (i < size) {
    if (maxim < massiv[i]) {
      maxim = massiv[i];
    }
    i++;
  }
  return maxim;
}

int main() {
  int process = 1;
  while (process) {
    int size;
    cout << "Введите количество элементов в массиве: ";
    size = mistake_int();
    int* massiv = createArray(size);
    int way;
    cout << "Выберите, какой способ выделения максимального числа вы хотите выбрать\n1. Do\n2. While\n3. For\n4. Закончить программу\n";
    way = mistake_int();
    int maxim;
    switch (way) {
      case 1:  
        maxim = check_do_while(massiv, size); 
        cout << "Максимальное число: " << maxim << endl;
        break; 
      case 2:  
        maxim = check_while(massiv, size); 
        cout << "Максимальное число: " << maxim << endl;
        break;
      case 3: maxim = check_for(massiv, size); 
        cout << "Максимальное число: " << maxim << endl;
        break;
      case 4: 
        process = 0; 
        break;
    }
  }
}