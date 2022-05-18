#include <climits>

int minoszlop(int **mtx, int s, int o) {
    int minsum = INT_MAX, mini = -1;
    for (int i=0; i<o; i++) {
        int sum = 0;
        for(int j=0; j<s; j++) {
            sum += mtx[j][i];
        }
        if (sum < minsum) {
            minsum = sum;
            mini = i;
        }
    }
    return mini;
}
