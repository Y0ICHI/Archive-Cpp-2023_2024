#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    vector<int> vet_int;
    srand(time(NULL));

    int num;
    do {
        num = rand() % 9 + 1; // Numeri casuali tra 1 e 9
        vet_int.push_back(num);
    } while(num != 5);

    for(int x = 0; x < vet_int.size(); x++) {
        cout << vet_int[x] << " ";
    }

    return 0;
}

