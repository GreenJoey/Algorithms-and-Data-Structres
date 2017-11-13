#include <stdio.h>


int main() {
    int x_row, x_col, y_row, y_col;
    printf("Number of rows and column in X: ");
    scanf("%d %d", &x_row, &x_col);
    printf("Number of rows and column in Y: ");
    scanf("%d %d", &y_row, &y_col);

    int x[x_row][x_col], y[y_row][y_col], ans[x_row][y_col];

    printf("%d\n", x_col == y_row);

    printf("X's data\n");
    for(int i=0; i<x_row; ++i) {
        for(int j=0; j<x_col; ++j) {
            scanf("%d", &x[i][j]);
        }
    }

    printf("Y's data\n");
    for(int i=0; i<y_row; ++i) {
        for(int j=0; j<y_col; ++j) {
            scanf("%d", &y[i][j]);
        }
    }


    for(int xrow=0; xrow<x_row; ++xrow) {
        for(int ycol=0; ycol<y_col; ++ycol) {
            int xcol = 0;
            int yrow = 0;
            int sum = 0;

            while(yrow < y_row && xcol < x_col) {
                sum += x[xrow][xcol]*y[yrow][ycol];
                xcol++;
                yrow++;
            }

            ans[xrow][ycol] = sum;
        }
    }

    for(int xrow=0; xrow<x_row; ++xrow) {
        for(int ycol=0; ycol<y_col; ++ycol) {
            printf("%d ", ans[xrow][ycol]);
        }
        printf("\n");
    }

    return 0;
}
