#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    void SetAsNew(double plateArray[][10], double newValArray[][10]);
    void SingleNewTemp(double plateArray[][10], double newValArray[][10], int rowNum, int colNum);
    void PrintNewPlate(double newValArray[][10]);
    void CalcDifference(double plateArray[][10], double newValArray[][10], int& maxDiff);
    int PLATE_SIZE = 5;
    double plateArray[10][10];
    double newValArray[10][10];
    int rowNum;
    int colNum;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            plateArray[i][j] = 0;
        }
    }
    for (int i = 1; i < 9; ++i) {
        plateArray[0][i] = 100;
    }
    for (int i = 1; i < 9; ++i) {
        plateArray[9][i] = 100;
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            newValArray[i][j] = 0;
        }
    }
    for (int i = 1; i < 9; ++i) {
        newValArray[0][i] = 100;
    }
    for (int i = 1; i < 9; ++i) {
        newValArray[9][i] = 100;
    }

    cout << "Hotplate simulator" << endl;
    cout << "\n";
    cout << "Printing the initial plate values..." << endl;


    cout << fixed << setprecision(3);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << setw(9) << plateArray[i][j];
            if (j < 9) {
                cout << ",";
            }
        }
        cout << endl;
    }
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            rowNum = i;
            colNum = j;
            SingleNewTemp(plateArray, newValArray, rowNum, colNum);
        }
    }
    cout << endl;
    cout << "Printing plate after one iteration..." << endl;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << setw(9) << newValArray[i][j];
            if (j < 9) {
                cout << ",";
            }
        }
        cout << endl;
    }

    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            if (newValArray[i][j] - plateArray[i][j] >= 0.1) {
                SetAsNew(plateArray, newValArray);
                for (int k = 1; k < 9; ++k) {
                    for (int l = 1; l < 9; ++l) {
                        rowNum = k;
                        colNum = l;
                        SingleNewTemp(plateArray, newValArray, rowNum, colNum);
                    }
                }
            }
        }
    }
    /*int maxDiff = 0;
    CalcDifference(plateArray, newValArray, maxDiff);
    while (maxDiff > 0.1) {
        SetAsNew(plateArray, newValArray);
 cout << maxDiff << endl;
        for (int i = 1; i < 9; ++i) {
            for (int j = 1; j < 9; ++j) {
                rowNum = i;
                colNum = 1;
                SingleNewTemp(plateArray, newValArray, rowNum, colNum);
 cout << "temp has been changed" << endl;
            }
        }
        CalcDifference(plateArray, newValArray, maxDiff);
  cout << "diff has been calced again" << endl;
    }*/



    cout << "Printing final plate..." << endl;
    PrintNewPlate(newValArray);


    return 0;
}

/*void CalcDifference(double plateArray[][10], double newValArray[][10], int& maxDiff) {
    maxDiff = 0;
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            if (newValArray[i][j] - plateArray[i][j] > maxDiff) {
                maxDiff = newValArray[i][j] - plateArray[i][j];
                cout << maxDiff << endl;
            }
        }
    }
}*/



void SetAsNew(double plateArray[][10], double newValArray[][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            plateArray[i][j] = newValArray[i][j];
        }
    }
}

void SingleNewTemp(double plateArray[][10], double newValArray[][10], int rowNum, int colNum) {
    double newTemp = (plateArray[rowNum][colNum - 1] + plateArray[rowNum][colNum + 1] + plateArray[rowNum - 1][colNum] + plateArray[rowNum + 1][colNum]) / 4;
    newValArray[rowNum][colNum] = newTemp;
}

void PrintNewPlate(double newValArray[][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << setw(9) << newValArray[i][j];
            if (j < 9) {
                cout << ",";
            }
        }
        cout << endl;
    }
}