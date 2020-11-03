
// forest queries
// 0 1 0 0
// 1 2 3 4
// 2 4 0 0
// 0 0 0 0

//preprocessing
//x[i][j] = input[i][j] + x[i-1][j] + x[i][j-1] - x[i-1][j-1]
// ans
// x[y2][x2] - x[y2][x1-1] - x[y1-1][x2]