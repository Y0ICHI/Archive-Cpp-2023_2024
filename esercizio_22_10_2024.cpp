#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	srand(time(NULL));
	vector<int> V1;
	vector<int> V2;
	vector<int> V3;
	int n;
	
	do{
		
		n = rand() % 999;
		
		if(n>0 && n<=9){
			V1.push_back(n);
		} else if (n>=10 && n<=99){
			V2.push_back(n);
		} else if (n>=100 && n<=999){
			V3.push_back(n);
		}
		
	} while(n!=0);
	
	cout << "\212 stato estratto 0." << endl;
	
	cout << "V1" << endl;
	for(int x = 0; x < V1.size(); x++) {
        cout << V1[x] << " ";
    }
    
    cout << endl << "V2" << endl;
    for(int x = 0; x < V2.size(); x++) {
        cout << V2[x] << " ";
    }
    
    cout << endl << "V3" << endl;
    for(int x = 0; x < V3.size(); x++) {
        cout << V3[x] << " ";
    }
    
    return 0;
}
