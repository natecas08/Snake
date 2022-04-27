#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>

#include "cxxTestSuite.h"
#include "player.h"

#define mapSize 20

using namespace std;

void startGame();
void listHighScores();
//void saveScore(int);


int main()
{
    srand(time(0));
    bool mainMenu = true;
    while(mainMenu)
    {
        system("cls");
        cout << "Snake" << endl;
        cout << "Created by Nathan Gomez" << endl;
        cout << endl;
        cout << endl;
        cout << "a) Start" << endl;
        cout << "b) view high scores" << endl;
        cout << "c) Exit" << endl;

        char choice;
        cin >> choice;

        switch(choice)
        {
            case 'a':
                startGame();
                break;
            case 'b':
                listHighScores();
                break;
            default:
                cout << "Exiting game" << endl;
                system("pause");
                mainMenu = false;
                break;
        }
    }
    return 0;
}


void startGame()
{
    PLAYER player(mapSize/2, mapSize/2);
    MAP gameMap;

    int gameDelay = 1000;
    int speedMultiplier = 1;
    bool walls = false;

    system("cls");
    cout << "Please choose your speed:" << endl;
    cout << "a) Crawl     " << endl;
    cout << "b) Leisurely (2X Points)" << endl;
    cout << "c) Normal    (3X Points)" << endl;
    cout << "d) Stride    (4X Points)" << endl;
    cout << "e) Sprint    (5X Points)" << endl;
    cout << endl;

    char choice;
    cin >> choice;

    switch(choice)
    {
        case 'a':
            speedMultiplier = 1;
            break;
        case 'b':
            gameDelay -= 250;
            speedMultiplier = 2;
            break;
        case 'c':
            gameDelay -= 500;
            speedMultiplier = 3;
            break;
        case 'd':
            speedMultiplier = 4;
            gameDelay -= 750;
            break;
        case 'e':
            speedMultiplier = 5;
            gameDelay -= 825;
            break;
        default:
            speedMultiplier = 1;
            break;
    }

    system("cls");
    cout << "Select a border option: " << endl;
    cout << "a) No Walls " << endl;
    cout << "b) Walls (2X Points)" << endl;
    char wChoice;
    cin >> wChoice;
    if(wChoice == 'a')
    {
        walls = false;
    }
    else
    {
        walls = true;
    }

    system("cls");
    gameMap.initializeMap(walls);

    cout << "Game Starting in 3" << endl;
    gameMap.displayMap();
    Sleep(1000);
    system("cls");
    cout << "Game Starting in 2" << endl;
    gameMap.displayMap();
    Sleep(1000);
    system("cls");
    cout << "Game Starting in 1" << endl;
    gameMap.displayMap();
    Sleep(1000);
    system("cls");
    cout << "START" << endl;
    gameMap.displayMap();
    Sleep(1000);
    system("cls");

    bool running = true;
    bool foodExists = false;

    int fX;
    int fY;

    while(running)
    {
        bool ateFood = false;
        bool gameOver = false;
        int cX = player.getHeadX();
        int cY = player.getHeadY();

        if(gameMap.m_Grid[cX][cY].getLabel() == 4 || gameMap.m_Grid[cX][cY].getLabel() == 2)
        {
            //End Game
            gameMap.displayMap();
            cout << "Game Over" << endl;
            cout << "Score: " << player.getScore() << endl;
            Sleep(2000);
            system("pause");
            running = false;
            gameOver = true;
            //saveScore(player.getScore());
        }
        else if(gameMap.m_Grid[cX][cY].getLabel() == 3)
        {
            int calcScore = speedMultiplier;
            if(walls)
            {
                calcScore *= 2;
            }
            player.setScore(calcScore);
            ateFood = true;
        }

        if(!gameOver)
        {
            //place food
            if(!foodExists)
            {
                bool validLocation = false;
                while(!validLocation)
                {
                    validLocation = true;
                    int x = (rand()%mapSize-1)+1;
                    int y = (rand()%mapSize-1)+1;

                    if(gameMap.m_Grid[x][y].getLabel()==0)
                    {
                        gameMap.m_Grid[x][y].setLabel(3);
                        fX = x;
                        fY = y;
                    }
                    else
                    {
                        validLocation = false;
                    }
                }
                foodExists = true;
            }
            //update map
            for(int i = 0; i < mapSize; i++)
            {
                for(int j = 0; j < mapSize; j++)
                {
                    bool segmentExists = false;
                    for(int k = 0; k < 400; k++)
                    {
                        if(player.segmentArray[k].getActive() && player.segmentArray[k].getX() == j && player.segmentArray[k].getY() == i)
                        {
                            segmentExists = true;
                            if(k == 0)
                            {
                                gameMap.m_Grid[j][i].setLabel(1);
                                if(gameMap.m_Grid[j][i].getLabel()==3)
                                {
                                    gameMap.m_Grid[j][i].setLabel(1);
                                }
                            }
                            else if(k > 0)
                            {
                                gameMap.m_Grid[j][i].setLabel(2);
                            }
                        }
                    }
                    if(!segmentExists && gameMap.m_Grid[j][i].getLabel() != 3 && gameMap.m_Grid[j][i].getLabel() != 4)
                    {
                        gameMap.m_Grid[j][i].setLabel(0);
                    }
                }
            }

            cout << "SCORE: " << player.getScore() << endl;
            gameMap.displayMap();

            //check for input
            int arrowKey;
            for(int i = 0; i < gameDelay; i++)
            {
                if(kbhit())
                {
                    arrowKey = getch();
                }
            }

            switch(arrowKey)
            {
                case 75:
                    player.setDir('L');
                    break;
                case 72:
                    player.setDir('U');
                    break;
                case 77:
                    player.setDir('R');
                    break;
                case 80:
                    player.setDir('D');
                    break;
            }

             //move player
            char direction = player.getDir();
            switch(direction)
            {
                case 'U':
                    player.update(cX, cY-1);
                    if(!walls && cY-1 < 0)
                    {
                        player.update(cX, mapSize-1);
                    }
                    break;
                case 'D':
                    player.update(cX, cY+1);
                    if(!walls && cY+1 > mapSize)
                    {
                        player.update(cX, 0);
                    }
                    break;
                case 'L':
                    player.update(cX-1, cY);
                    if(!walls && cX-1 < 0)
                    {
                        player.update(mapSize-1, cY);
                    }
                    break;
                case 'R':
                    player.update(cX+1, cY);
                    if(!walls && cX+1 > mapSize)
                    {
                        player.update(0, cY);
                    }
                    break;
                default:
                    player.update(cX, cY-1);
                    break;
            }
        }
        if(ateFood)
        {
            player.push(fX, fY);
            foodExists = false;
            ateFood = false;
        }
        system("cls");
    }
}


void listHighScores()
{
    system("cls");
    int fSize = 0;
    ifstream hs;
    hs.open("scores.txt");
    if(!hs)
    {
        cerr << "Scores file not found! Aborting...." << endl;
    }
    else
    {
        string temp;
        while(getline(hs, temp))
        {
            fSize++;
        }
    }
    hs.close();

    int scores[fSize/2];
    string names[fSize/2];

    ifstream hs2;
    hs2.open("scores.txt");
    for(int i = 0; i < fSize/2; i++)
    {
        hs2 >> names[i];
        hs2 >> scores[i];
    }

    if(fSize==0)
    {
        cout << "No High Scores" << endl;
    }
    else
    {
        cout << "High Scores" << endl;
        cout << "-----------" << endl;
        cout << endl;

        for(int i = 0; i < fSize/2; i++)
        {
            cout << i+1 << ") " << names[i] << ": " << scores[i] << endl;
        }
        system("pause");
    }
}

/*
void saveScore(int s)
{
    bool newHighScore = false;
    bool createHSFile = false;

    ifstream hsFile;
    hsFile.open("scores.txt");
    if(!hsFile)
    {
        createHSFile = true;
        hsFile.close();
    }

    if(createHSFile)
    {
        ofstream makeFile;
        makeFile.open("scores.txt");
        makeFile.close();
    }

    hsFile.open("scores.txt");

    int sizeCounter = 0;
    string temp;
    while(getline(hsFile, temp))
    {
        sizeCounter++;
    }
    hsFile.close();

    int scores[sizeCounter/2];
    string names[sizeCounter/2];
    hsFile.open("scores.txt");
    for(int i = 0; i < sizeCounter/2; i++)
    {
        hsFile >> names[i];
        hsFile >> scores[i];
    }
    hsFile.close();

    if(sizeCounter/2 < 10)
    {
        newHighScore = true;
    }
    else
    {
        for(int i = 0; i < sizeCounter/2; i++)
        {
            if(s > scores[i])
            {
                newHighScore = true;
            }
        }
    }

    if(newHighScore)
    {
        int place = 0;
        while(s < scores[place])
        {
            place++;
        }

        cout << "You have placed " << place+1 << "!" << endl;
        cout << "Would you like to save your score?" << endl;
        cout << "a) Yes" << endl;
        cout << "b) No" << endl;
        char choice;
        cin >> choice;
        if(choice == 'a')
        {
            cout << "Please enter your name: ";
            string newName;
            cin >> newName;

            int updateScores[sizeCounter/2+1];
            string updateNames[sizeCounter/2+1];

            for(int i = 0; i < place; i++)
            {
                updateNames[i] = names[i];
                updateScores[i] = scores[i];
            }

            updateNames[place] = newName;
            updateScores[place] = s;

            for(int i = place+1; i < sizeCounter/2+1; i++)
            {
                updateNames[i] = names[i];
                updateScores[i] = scores[i];
            }

            //write to file
            ofstream overWrite;
            overWrite.open("scores.txt");
            for(int i = 0; i < sizeCounter/2+1; i++)
            {
                overWrite << updateNames[i] << endl;
                overWrite << updateScores[i] << endl;
            }
        }
    }
}
*/


