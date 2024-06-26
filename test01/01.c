#include <stdio.h>
#include <stdlib.h>

void calculate_scores() {
    int scores[100]; // スコアの保存用配列
    int score_count = 0; // スコアの数

    while (1) {
        int n;
        scanf("%d", &n); // 審判の数を読み取る
        if (n == 0) {
            break;
        }

        int points[100]; // 各審判の点数保存用配列
        for (int i = 0; i < n; i++) {
            scanf("%d", &points[i]); // 各審判の点数を読み取る
        }

        // 点数リストをソート
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (points[i] > points[j]) {
                    int temp = points[i];
                    points[i] = points[j];
                    points[j] = temp;
                }
            }
        }

        // 最高点と最低点を除外して平均を計算
        int sum = 0;
        for (int i = 1; i < n - 1; i++) {
            sum += points[i];
        }
        int average_score = sum / (n - 2);
        scores[score_count++] = average_score;
    }

    // 結果を出力
    for (int i = 0; i < score_count; i++) {
        printf("%d\n", scores[i]);
    }
}

int main() {
    calculate_scores();
    return 0;
}
