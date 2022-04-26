#include "player.h"
#include <iostream>
using std::cout;
using std::endl;

void GRID::setLabel(int L)
{
    if(L >= 0 && L <= 4)
    {
        g_Label = L;
    }
}

const int GRID::getLabel()
{
    return g_Label;
}

void MAP::displayMap()
{
    for(int i = 0; i < m_Size; i++)
    {
        for(int j = 0; j < m_Size; j++)
        {
            char temp;
            if(m_Grid[j][i].getLabel()==0)
            {
                temp = ' ';
            }
            else if(m_Grid[j][i].getLabel()==1)
            {
                temp = 'O';
            }
            else if(m_Grid[j][i].getLabel()==2)
            {
                temp = 'o';
            }
            else if(m_Grid[j][i].getLabel()==3)
            {
                temp = 'x';
            }
            else
            {
                temp = '#';
            }

            cout << temp;
        }
        cout << endl;
    }
}

void MAP::initializeMap(bool walls)
{
    if(walls)
    {
        for(int i = 0; i < m_Size; i++)
        {
            m_Grid[0][i].setLabel(4);
            m_Grid[m_Size-1][i].setLabel(4);
            m_Grid[i][0].setLabel(4);
            m_Grid[i][m_Size-1].setLabel(4);
        }
    }
    int xTemp = m_Size/2;
    int yTemp = xTemp;

    m_Grid[xTemp][yTemp].setLabel(1);

}

void SEGMENT::setParent(int x, int y)
{
    s_PX = x;
    s_PY = y;
}
void SEGMENT::setLocation(int x, int y)
{
    s_X = x;
    s_Y = y;
}
void SEGMENT::setActive(bool A)
{
    s_Active = A;
}

int SEGMENT::getParentX()
{
    return s_PX;
}
int SEGMENT::getParentY()
{
    return s_PY;
}
int SEGMENT::getX()
{
    return s_X;
}
int SEGMENT::getY()
{
    return s_Y;
}
bool SEGMENT::getActive()
{
    return s_Active;
}

PLAYER::PLAYER(int x, int y)
{
    p_headX = x;
    p_headY = y;

    segmentArray[0].setLocation(x, y);
    segmentArray[0].setActive(true);
}

void PLAYER::setHead(int x, int y)
{
    p_headX = x;
    p_headY = y;
    segmentArray[0].setLocation(x, y);
}

void PLAYER::push(int x, int y)
{
    segmentArray[segments].setLocation(x, y);
    segmentArray[segments].setActive(true);
    segments++;
}

void PLAYER::update(int x, int y)
{
    //current locations
    int cXarr[segments];
    int cYarr[segments];
    for(int i = 0; i < segments; i++)
    {
        cXarr[i] = segmentArray[i].getX();
        cYarr[i] = segmentArray[i].getY();
    }

    //new locations
    int nXarr[segments];
    int nYarr[segments];
    for(int i = 0; i < segments; i++)
    {
        if(i==0)
        {
            nXarr[i] = x;
            nYarr[i] = y;
            p_headX = x;
            p_headY = y;
        }
        else
        {
            nXarr[i] = cXarr[i-1];
            nYarr[i] = cYarr[i-1];
        }
    }

    //update
    for(int i = 0; i < segments; i++)
    {
        int nX = nXarr[i];
        int nY = nYarr[i];

        segmentArray[i].setLocation(nX, nY);
    }
}

void PLAYER::setDir(char L)
{
    if(L=='U')
    {
        if(p_direction != 'D')
        {
            p_direction = L;
        }
    }
    else if(L=='D')
    {
        if(p_direction != 'U')
        {
            p_direction = L;
        }
    }
    else if(L=='L')
    {
        if(p_direction != 'R')
        {
            p_direction = L;
        }
    }
    else if(L=='R')
    {
        if(p_direction != 'L')
        {
            p_direction = L;
        }
    }
}
char PLAYER::getDir()
{
    return p_direction;
}

int PLAYER::getScore()
{
    return p_Score;
}

void PLAYER::setScore(int s)
{
    p_Score += s;
}

int PLAYER::getHeadX()
{
    return p_headX;
}

int PLAYER::getHeadY()
{
    return p_headY;
}


