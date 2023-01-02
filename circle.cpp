#include <iostream>
#include <vector>
#include <stdbool.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    int n;
    
    n = 10;
    int SIMULATIONS = 1000000;
    
    srand(time(0));
    vector<int> count(n + 1);
    vector<int> visited(n + 1);
    int point;
    int direction;
    
    for(int k = 0; k < SIMULATIONS; k++) {
		// to see progress
		if(k % (SIMULATIONS / 10) == 0) {
			cout << (int)(1.0 * k / SIMULATIONS * 100) << "%" << '\n';
		}
		
		int visited_num = 0;
        fill(visited.begin(), visited.end(), 0);
        visited[0] = 1;
        point = 0; // start at point 0
        
        while(visited_num != n) {
            // 0 for clockwise, 1 for counterclockwise
            direction = rand() % 2;
            if(direction == 0) { // clockwise
                point++;
            }
            else if(direction == 1) { // counterclockwise
                point--;
            }
            point = (point + n + 1) % (n + 1);
            if(visited[point] == 0) {
				visited[point] = 1;
				visited_num++;
			}
        }
        count[point]++;
    }
    
    cout << "completed" << '\n' << '\n';
    cout << "number of times" << '\n';
    for(int i = 0; i < (n + 1); i++) {
        cout << "last point " << i << ": " << count[i] << '\n';
    }
    

    return 0;
}
