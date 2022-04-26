#ifndef PLAYER_H_
#define PLAYER_H_
#define mapSize 20

class GRID
{
    public:
        void setLabel(int);
        const int getLabel();

    private:
        int g_Label = 0;

};

class MAP
{
    public:
        void initializeMap(bool);
        void displayMap();
        GRID m_Grid[mapSize][mapSize];

    private:
        int m_Size = mapSize;
};

class SEGMENT
{
    public:
        void setParent(int, int);
        void setLocation(int, int);
        void setActive(bool);

        int getParentX();
        int getParentY();
        int getX();
        int getY();
        bool getActive();

    private:
        int s_PX;
        int s_PY;
        int s_X;
        int s_Y;

        bool s_Active = false;
};

class PLAYER
{
    public:
        PLAYER(int, int);

        void setHead(int, int);
        void push(int, int);

        int getHeadX();
        int getHeadY();

        void setScore(int);
        int getScore();

        void setDir(char);
        char getDir();

        void update(int, int);
        SEGMENT segmentArray[400];

    private:
        int segments = 1;


        int p_headX;
        int p_headY;

        int p_Score = 0;

        char p_direction = 'U';
};
#endif // PLAYER_H_
