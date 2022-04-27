#include "cxxtest/TestSuite.h"
#include "player.h"

class unitTestsEquals : public CxxTest::TestSuite
  {
  public:
      void testGridEquals(void)
      {
          //check if grid label is set correctly
          GRID g1;
          int a = 1;
          g1.setLabel(1);
          int b = g1.getLabel();
          TS_ASSERT_EQUALS(a, b);
      }

      void testPlayerInitialize(void)
      {
          //initialize player's head position
          int x = 10;
          int y = 6;
          PLAYER p1(x, y);
          int xTest = p1.getHeadX();
          int yTest = p1.getHeadY();
          TS_ASSERT_EQUALS(xTest, x);
          TS_ASSERT_EQUALS(yTest, y);
      }

      void testPlayerSetHead(void)
      {
          //change player's head posistion
          int x = 5;
          int y = 5;
          PLAYER p1(0,0);
          p1.setHead(x, y);
          int xTest = p1.getHeadX();
          int yTest = p1.getHeadY();
          TS_ASSERT_EQUALS(xTest, x);
          TS_ASSERT_EQUALS(yTest, y);
      }

      void testPlayerSetScore(void)
      {
          //check if score is changed correctly.
          PLAYER p1(0,0);
          int s1 = 5;
          int s2 = 7;
          p1.setScore(s1);
          p1.setScore(s2);
          int sF = p1.getScore();
          TS_ASSERT_EQUALS(sF, s1+s2);
      }

      void testPlayerDirection(void)
      {
          PLAYER p1(0,0);
          char setChar = 'R';
          p1.setDir(setChar);
          char getChar = p1.getDir();
          TS_ASSERT_EQUALS(setChar, getChar);
      }
  };


class unitTestsNotEquals : public CxxTest::TestSuite
{
    public:
        void testPlayerChangeHead(void)
        {
            //test to see if the new head position is different from the old one
            int x1 = 0;
            int y1 = 0;
            int x2 = 5;
            int y2 = 5;
            PLAYER p1(x1, y1);
            p1.setHead(x2, y2);

            int x2return = p1.getHeadX();
            int y2return = p1.getHeadY();

            TS_ASSERT_DIFFERS(x1, x2return);
            TS_ASSERT_DIFFERS(y1, y2return);
        }

        void testPlayerInvalidDirection(void)
        {
            //a player should not be able to move in the opposite direction it is
            //currently traveling. Therefor, if an invalid direction is sent to it,
            //it should not switch to that direction

            char curDir = 'U';
            char invalidDir = 'D';

            PLAYER p1(0, 0);
            p1.setDir(curDir);
            p1.setDir(invalidDir);

            char returnDir = p1.getDir();

            TS_ASSERT_DIFFERS(invalidDir, returnDir);
        }

        void testGridInvalidLabel(void)
        {
            //Tests to make sure a grid box does not accept an invalid label
            GRID g1;
            int invalidLabel = 7;
            g1.setLabel(invalidLabel);
            int returnLabel = g1.getLabel();

            TS_ASSERT_DIFFERS(invalidLabel, returnLabel);
        }
};

class unitTestIsFalse : public CxxTest::TestSuite
{
    public:
        void testSegmentActive(void)
        {
            //segments by default should be inactive
            SEGMENT s1;
            TS_ASSERT(!s1.getActive());
        }
};

class unitTestIsTrue : public CxxTest::TestSuite
{
    public:
        void testSegmentActive(void)
        {
            //activating segment
            SEGMENT s1;
            s1.setActive(true);
            TS_ASSERT(s1.getActive());
        }
};

class unitTestLessThan : public CxxTest::TestSuite
{
    public:
        void testScoreIncrease(void)
        {
            //score should not decrease when changed
            PLAYER p1(0,0);
            int s1 = 10;
            int s2 = 5;
            p1.setScore(s1);
            p1.setScore(s2);

            int fScore = p1.getScore();

            TS_ASSERT_LESS_THAN_EQUALS(s1, fScore);
            TS_ASSERT_LESS_THAN_EQUALS(s2, fScore);
        }
};
