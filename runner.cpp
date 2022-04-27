/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_unitTestsEquals_init = false;
#include "C:\Users\Nathan\Documents\UNR\Semester 6\CS 491\Snake\cxxTestSuite.h"

static unitTestsEquals suite_unitTestsEquals;

static CxxTest::List Tests_unitTestsEquals = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_unitTestsEquals( "cxxTestSuite.h", 4, "unitTestsEquals", suite_unitTestsEquals, Tests_unitTestsEquals );

static class TestDescription_suite_unitTestsEquals_testGridEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_unitTestsEquals_testGridEquals() : CxxTest::RealTestDescription( Tests_unitTestsEquals, suiteDescription_unitTestsEquals, 7, "testGridEquals" ) {}
 void runTest() { suite_unitTestsEquals.testGridEquals(); }
} testDescription_suite_unitTestsEquals_testGridEquals;

static class TestDescription_suite_unitTestsEquals_testPlayerInitialize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_unitTestsEquals_testPlayerInitialize() : CxxTest::RealTestDescription( Tests_unitTestsEquals, suiteDescription_unitTestsEquals, 17, "testPlayerInitialize" ) {}
 void runTest() { suite_unitTestsEquals.testPlayerInitialize(); }
} testDescription_suite_unitTestsEquals_testPlayerInitialize;

static class TestDescription_suite_unitTestsEquals_testPlayerSetHead : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_unitTestsEquals_testPlayerSetHead() : CxxTest::RealTestDescription( Tests_unitTestsEquals, suiteDescription_unitTestsEquals, 29, "testPlayerSetHead" ) {}
 void runTest() { suite_unitTestsEquals.testPlayerSetHead(); }
} testDescription_suite_unitTestsEquals_testPlayerSetHead;

static class TestDescription_suite_unitTestsEquals_testPlayerSetScore : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_unitTestsEquals_testPlayerSetScore() : CxxTest::RealTestDescription( Tests_unitTestsEquals, suiteDescription_unitTestsEquals, 42, "testPlayerSetScore" ) {}
 void runTest() { suite_unitTestsEquals.testPlayerSetScore(); }
} testDescription_suite_unitTestsEquals_testPlayerSetScore;

static class TestDescription_suite_unitTestsEquals_testPlayerDirection : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_unitTestsEquals_testPlayerDirection() : CxxTest::RealTestDescription( Tests_unitTestsEquals, suiteDescription_unitTestsEquals, 54, "testPlayerDirection" ) {}
 void runTest() { suite_unitTestsEquals.testPlayerDirection(); }
} testDescription_suite_unitTestsEquals_testPlayerDirection;

static unitTestsNotEquals suite_unitTestsNotEquals;

static CxxTest::List Tests_unitTestsNotEquals = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_unitTestsNotEquals( "cxxTestSuite.h", 65, "unitTestsNotEquals", suite_unitTestsNotEquals, Tests_unitTestsNotEquals );

static class TestDescription_suite_unitTestsNotEquals_testPlayerChangeHead : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_unitTestsNotEquals_testPlayerChangeHead() : CxxTest::RealTestDescription( Tests_unitTestsNotEquals, suiteDescription_unitTestsNotEquals, 68, "testPlayerChangeHead" ) {}
 void runTest() { suite_unitTestsNotEquals.testPlayerChangeHead(); }
} testDescription_suite_unitTestsNotEquals_testPlayerChangeHead;

static class TestDescription_suite_unitTestsNotEquals_testPlayerInvalidDirection : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_unitTestsNotEquals_testPlayerInvalidDirection() : CxxTest::RealTestDescription( Tests_unitTestsNotEquals, suiteDescription_unitTestsNotEquals, 85, "testPlayerInvalidDirection" ) {}
 void runTest() { suite_unitTestsNotEquals.testPlayerInvalidDirection(); }
} testDescription_suite_unitTestsNotEquals_testPlayerInvalidDirection;

static class TestDescription_suite_unitTestsNotEquals_testGridInvalidLabel : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_unitTestsNotEquals_testGridInvalidLabel() : CxxTest::RealTestDescription( Tests_unitTestsNotEquals, suiteDescription_unitTestsNotEquals, 103, "testGridInvalidLabel" ) {}
 void runTest() { suite_unitTestsNotEquals.testGridInvalidLabel(); }
} testDescription_suite_unitTestsNotEquals_testGridInvalidLabel;

static unitTestIsFalse suite_unitTestIsFalse;

static CxxTest::List Tests_unitTestIsFalse = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_unitTestIsFalse( "cxxTestSuite.h", 115, "unitTestIsFalse", suite_unitTestIsFalse, Tests_unitTestIsFalse );

static class TestDescription_suite_unitTestIsFalse_testSegmentActive : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_unitTestIsFalse_testSegmentActive() : CxxTest::RealTestDescription( Tests_unitTestIsFalse, suiteDescription_unitTestIsFalse, 118, "testSegmentActive" ) {}
 void runTest() { suite_unitTestIsFalse.testSegmentActive(); }
} testDescription_suite_unitTestIsFalse_testSegmentActive;

static unitTestIsTrue suite_unitTestIsTrue;

static CxxTest::List Tests_unitTestIsTrue = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_unitTestIsTrue( "cxxTestSuite.h", 126, "unitTestIsTrue", suite_unitTestIsTrue, Tests_unitTestIsTrue );

static class TestDescription_suite_unitTestIsTrue_testSegmentActive : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_unitTestIsTrue_testSegmentActive() : CxxTest::RealTestDescription( Tests_unitTestIsTrue, suiteDescription_unitTestIsTrue, 129, "testSegmentActive" ) {}
 void runTest() { suite_unitTestIsTrue.testSegmentActive(); }
} testDescription_suite_unitTestIsTrue_testSegmentActive;

static unitTestLessThan suite_unitTestLessThan;

static CxxTest::List Tests_unitTestLessThan = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_unitTestLessThan( "cxxTestSuite.h", 138, "unitTestLessThan", suite_unitTestLessThan, Tests_unitTestLessThan );

static class TestDescription_suite_unitTestLessThan_testScoreIncrease : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_unitTestLessThan_testScoreIncrease() : CxxTest::RealTestDescription( Tests_unitTestLessThan, suiteDescription_unitTestLessThan, 141, "testScoreIncrease" ) {}
 void runTest() { suite_unitTestLessThan.testScoreIncrease(); }
} testDescription_suite_unitTestLessThan_testScoreIncrease;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
