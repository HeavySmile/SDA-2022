#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

struct Apple
{
    bool isRotten;
    Apple() : isRotten(false) {}
};

struct Position
{
    int row, column;
    Position() : row(-1), column(-1) {}
    Position(int row, int column) : row(row), column(column) {}
};

bool isValid(int row, int column, int rowCount, int columnCount)
{
    return row >= 0 && column >= 0 && row < rowCount && column < columnCount;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int rowCount, columnCount, dayCount;
    cin >> rowCount >> columnCount >> dayCount;
    cin.ignore();

    int applesCount = rowCount * columnCount;
    int rottenApplesCount = 0;
    queue<Position> rottenApples;
    Apple apples[rowCount][columnCount];

    int row, column;
    for (size_t i = 0; i < 2; i++)
    {
        row = INT_MAX;
        column = INT_MAX;
        
        cin >> row >> column; 
        
        if (row != INT_MAX && column != INT_MAX)
        {
            row = rowCount - row;
            column--;
            rottenApplesCount++; 
            rottenApples.push(Position(row, column)); 
            apples[row][column].isRotten = true;
        } 
    }
    // string input;
    // for (size_t i = 0; i < 2; i++)
    // {
    //     getline(cin, input);

    //     if(input.compare("\n") != 0)
    //     {
    //         int row = rowCount - (input[0] - '0');
    //         int column = input[2] - '0' - 1;
    //         rottenApplesCount++;
    //         rottenApples.push(Position(row, column));
    //         apples[row][column].isRotten = true;
    //     }
    // }
    
    Position delimiter(-1, -1);
    rottenApples.push(delimiter);
    
    for (size_t i = 0; i < rowCount; i++)
        {
            for (size_t j = 0; j < columnCount; j++)
            {
                cout << apples[i][j].isRotten << " ";
            }
            cout << endl;
        }
        cout << endl;
    
    int daysPassed = 0;
    while (!rottenApples.empty() && daysPassed < dayCount && (applesCount - rottenApplesCount) > 0) 
    {
        bool flag = false;
        Position temp;

        while (rottenApples.front().row != -1 && rottenApples.front().column != -1) 
        {

            temp = rottenApples.front();
 
            if (isValid(temp.row, temp.column + 1, rowCount, columnCount) && 
               !apples[temp.row][temp.column + 1].isRotten)
            {
                rottenApplesCount++;

                apples[temp.row][temp.column + 1].isRotten = true;
 
                temp.column++;
                rottenApples.push(temp);
 
                temp.column--;
            }
 
            if (isValid(temp.row, temp.column - 1, rowCount, columnCount) && 
                !apples[temp.row][temp.column - 1].isRotten) 
            {
                rottenApplesCount++;

                apples[temp.row][temp.column - 1].isRotten = true;
 
                temp.column--;
                rottenApples.push(temp);
 
                temp.column++;
            }
 
            if (isValid(temp.row - 1, temp.column, rowCount, columnCount) && 
                !apples[temp.row - 1][temp.column].isRotten) 
            {
                rottenApplesCount++;

                apples[temp.row - 1][temp.column].isRotten = true;
 
                temp.row--;
                rottenApples.push(temp);
 
                temp.row++;
            }
 
            if (isValid(temp.row + 1, temp.column, rowCount, columnCount) && 
                !apples[temp.row + 1][temp.column].isRotten) 
            {
                rottenApplesCount++;

                apples[temp.row + 1][temp.column].isRotten = true;
 
                temp.row++;
                rottenApples.push(temp);
 
                temp.row--;
            }
 
            rottenApples.pop();
        }

        for (size_t i = 0; i < rowCount; i++)
        {
            for (size_t j = 0; j < columnCount; j++)
            {
                cout << apples[i][j].isRotten << " ";
            }
            cout << endl;
        }
        cout << endl;

        rottenApples.pop();
 
        if (!rottenApples.empty()) 
        {
            daysPassed++;
            temp.row = -1;
            temp.column = -1;
            rottenApples.push(temp);
        }
 
    }
    
    cout << applesCount - rottenApplesCount;

    return 0;
}

// queue