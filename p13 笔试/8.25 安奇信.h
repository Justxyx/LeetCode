//
// Created by xm on 2022/8/25.
//

#ifndef P13__8_25_安奇信_H
#define P13__8_25_安奇信_H

// 先找最小点
int x_small = 0;
int x_value = vec[0] * vec[0];
for (int i = 1; i < vec.size(); ++i) {
if (vec[i] * vec[i] > x_value) {
x_small = i;
x_value = vec[i] * vec[i];
}
}
int sum = 0;
for (int i = 0; i < vec.size(); ++i) {
int are =abs((i-x_small) * (vec[x_small] - vec[i]));
sum = max(are, sum);
}
#endif //P13__8_25_安奇信_H
