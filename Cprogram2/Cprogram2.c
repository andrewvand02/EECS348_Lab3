 #include <stdio.h>

void find_combinations(int score, int combinations[5], int index, int count[5]) {
    if (score < 0) {
        return;
    }
    if (score == 0) {
        printf("%d Safeties, %d Field Goals, %d TD, %d TD+1 point, %d TD+2 point\n",
               count[0], count[1], count[2], count[3], count[4]);
        return;
    }
    count[0]++;
    combinations[index] = 2;
    find_combinations(score - 2, combinations, index + 1, count);
    count[0]--;
    count[1]++;
    combinations[index] = 3;
    find_combinations(score - 3, combinations, index + 1, count);
    count[1]--;
    count[2]++;
    combinations[index] = 6;
    find_combinations(score - 6, combinations, index + 1, count);
    count[2]--;
    count[3]++;
    combinations[index] = 7;
    find_combinations(score - 7, combinations, index + 1, count);
    count[3]--;
    count[4]++;
    combinations[index] = 8;
    find_combinations(score - 8, combinations, index + 1, count);
    count[4]--;
}

int main() {
    int score;
    while (1) {
        printf("Enter the score (1 or 0 to quit): ");
        scanf("%d", &score);
        if (score == 1 || score == 0) {
            break;
        }
        int combinations[score];
        int count[5] = {0, 0, 0, 0, 0};
        find_combinations(score, combinations, 0, count);
    }
    return 0;
}

