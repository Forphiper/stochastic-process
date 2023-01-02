#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    int n; // goal amount
    int k; // starting amount
    int p; // winning probability
    
    int SIMULATIONS = 1000000;
    n = 100;
    k = 50;
    
    int reach_n_num;
    int reach_zero_num;
	
	srand(time(0));
	
	int curr_money;
    int rand_num;
    
    for(int i = 50; i <= 60; i += 5) {
		p = i; // 50 for p = 0.5
		reach_n_num = 0;
		reach_zero_num = 0;
		for(int j = 0; j < SIMULATIONS; j++) {
			curr_money = k;
			while(curr_money != 0 && curr_money != n) {
				rand_num = ((rand() % 100) < p);
				if(rand_num) {
					curr_money++;
				}
				else if(!rand_num) {
					curr_money--;
				}
			}
			if(curr_money == 0) {
				reach_zero_num++;
			}
			else if(curr_money == n) {
				reach_n_num++;
			}
		}
		cout << "p: " << (float)p / 100 << '\n';
		cout << "reach zero num: " << reach_zero_num << '\n';
		cout << "reach n num: " << reach_n_num << '\n' << '\n'; 
	}
    
    
    
    
    

    return 0;
}
