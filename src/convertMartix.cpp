#include "convertMartix.h"
#include "global.h"

void getMartix(int pairNum[2][2][2], int starNum[3][2][2][2], int triedNum[3][2][2][2], int martix[6][6])
{
    martix[5][4] = (pairNum[0][1][0] + pairNum[1][0][1]) / 2;
    martix[4][5] = (pairNum[0][1][1] + pairNum[1][0][0]) / 2;
    martix[4][4] = (pairNum[0][0][0] + pairNum[1][1][1]) / 2;
    martix[5][5] = (pairNum[0][0][1] + pairNum[1][1][0]) / 2;

    martix[3][1] = starNum[1][0][0][0];
    martix[3][0] = starNum[1][0][0][1];
    martix[2][1] = starNum[1][0][1][0];
    martix[2][0] = starNum[1][0][1][1];
    martix[3][2] = starNum[1][1][0][1];
    martix[3][3] = starNum[1][1][0][0];
    martix[2][2] = starNum[1][1][1][1];
    martix[2][3] = starNum[1][1][1][0];
    martix[1][0] = starNum[0][0][0][1];
    martix[1][1] = starNum[0][0][0][0];
    martix[1][2] = starNum[0][0][1][1];
    martix[1][3] = starNum[0][0][1][0];
    martix[0][0] = starNum[0][1][0][1];
    martix[0][1] = starNum[0][1][0][0];
    martix[0][2] = starNum[0][1][1][1];
    martix[0][3] = starNum[0][1][1][0];
    martix[4][3] = starNum[2][1][0][1];
    martix[5][3] = starNum[2][1][0][0];
    martix[4][2] = starNum[2][1][1][1];
    martix[5][2] = starNum[2][1][1][0];
    martix[4][0] = starNum[2][0][1][1];
    martix[5][0] = starNum[2][0][1][0];
    martix[4][1] = starNum[2][0][0][1];
    martix[5][1] = starNum[2][0][0][0];

    if(!ompFlag)
    {
        martix[2][5] = triedNum[2][0][0][0] + triedNum[0][1][0][1] + triedNum[1][1][1][1];
        martix[3][5] = triedNum[2][0][0][1] + triedNum[0][1][1][1] + triedNum[1][1][0][1];
        martix[0][5] = triedNum[2][0][1][0] + triedNum[0][0][0][1] + triedNum[1][1][1][0];
        martix[1][5] = triedNum[2][0][1][1] + triedNum[0][0][1][1] + triedNum[1][1][0][0];
        martix[1][4] = triedNum[1][0][1][1] + triedNum[0][1][0][0] + triedNum[2][1][0][0];
        martix[3][4] = triedNum[1][0][0][1] + triedNum[0][1][1][0] + triedNum[2][1][0][1];
        martix[0][4] = triedNum[1][0][1][0] + triedNum[0][0][0][0] + triedNum[2][1][1][0];
        martix[2][4] = triedNum[1][0][0][0] + triedNum[0][0][1][0] + triedNum[2][1][1][1];
    }
    else
    {
        martix[2][5] = (triedNum[2][0][0][0] + triedNum[0][1][0][1] + triedNum[1][1][1][1]) / 3;
        martix[3][5] = (triedNum[2][0][0][1] + triedNum[0][1][1][1] + triedNum[1][1][0][1]) / 3;
        martix[0][5] = (triedNum[2][0][1][0] + triedNum[0][0][0][1] + triedNum[1][1][1][0]) / 3;
        martix[1][5] = (triedNum[2][0][1][1] + triedNum[0][0][1][1] + triedNum[1][1][0][0]) / 3;
        martix[1][4] = (triedNum[1][0][1][1] + triedNum[0][1][0][0] + triedNum[2][1][0][0]) / 3;
        martix[3][4] = (triedNum[1][0][0][1] + triedNum[0][1][1][0] + triedNum[2][1][0][1]) / 3;
        martix[0][4] = (triedNum[1][0][1][0] + triedNum[0][0][0][0] + triedNum[2][1][1][0]) / 3;
        martix[2][4] = (triedNum[1][0][0][0] + triedNum[0][0][1][0] + triedNum[2][1][1][1]) / 3;
    }

}
