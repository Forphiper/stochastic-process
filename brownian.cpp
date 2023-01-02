#include <iostream>
#include <random>
#include <time.h>
#include <chrono>

using namespace std;

int main()
{
    int A; // up A
    int B; // down B
    double delta_t;
    double delta_x_mean;
    double delta_x_variance;
    
    const int SIMULATIONS = 1000000;
    A = 1;
    B = 2;
    delta_x_mean = 0;
    
    srand(time(0));
    
    int up_A_num;
    int down_B_num;
    
    double current_value;
    double normal_delta_x;
    
    double u;
    double v;
    double standard_normal_number;
    
    for(int i = 0; i < 4; i++) {
		delta_t = pow(0.1, i);
		delta_x_variance = 1.0 * delta_t;
    
		up_A_num = 0;
		down_B_num = 0;

		for(int j = 0; j < SIMULATIONS; j++) {
			current_value = 0;

			while(current_value < A && current_value > -B) {
				// Box–Muller transform to generate standard normal number
				u = (double)rand() / (double)RAND_MAX; // number uniformly in [0, 1]
				v = (double)rand() / (double)RAND_MAX;
				standard_normal_number = sqrt(-2.0 * log(u)) * cos(2.0 * M_PI * v);
				
				normal_delta_x = sqrt(delta_x_variance) * standard_normal_number + delta_x_mean;
				current_value += normal_delta_x;
			}
			if(current_value >= A) {
				up_A_num++;
			}
			else if(current_value <= -B) {
				down_B_num++;
			}
		}
		
		cout << "delta t: " << delta_t << '\n';
		cout << "up A number: " << up_A_num << '\n';
		cout << "down B number: " << down_B_num << '\n';
		cout << "ratio of up A: " << 1.0 * up_A_num / \
			(up_A_num + down_B_num) << '\n';
    }
    
    return 0;
}
