#include "gtest/gtest.h"
#include "../../include/gameboard.h"
#include "../../include/util.h"


class GameBoardTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        gb = new Gameboard(9);
    }

    virtual void TearDown() {
        delete gb;
        gb = NULL;
    }

    static Gameboard* gb;
};

Gameboard* GameBoardTest::gb = NULL;


TEST(Gameboard, GameBoardInitalTest) {
    EXPECT_NE(new Gameboard(5), nullptr);
}

/*
 * TODO
 * Failed öfter mal, checken warum.
 */
TEST_F(GameBoardTest, MoveInvalidWhenSameNumberInSeg) {
    gb->nextMove(1,1,4);
    EXPECT_FALSE(gb->nextMove(1,2,4));
}

TEST_F(GameBoardTest, MoveValidWhenDifferentNumbersInSeg) {
    gb->nextMove(1,1,6);
    EXPECT_TRUE(gb->nextMove(1,2,7));
}

TEST_F(GameBoardTest, MoveValidWhenDifferentNumbersInCol) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,2,5);
    EXPECT_TRUE(gb->nextMove(1,5,8));
}

TEST_F(GameBoardTest, MoveInvalidWhenSameNumberInCol) {
    gb->nextMove(1,1,5);
    EXPECT_FALSE(gb->nextMove(1,6,5));
}

TEST_F(GameBoardTest, NextMoveColumnOutOfLowerBounds) {
    //ASSERT_DEATH(gb->nextMove(-1,1,1), "");
}

/**
 * Warum schlägt hier der assert nicht an?
 */
TEST_F(GameBoardTest, NextMoveColumnOutOfUpperBounds) {
    //ASSERT_DEATH(gb->nextMove(10,9,1), "");
}

TEST_F(GameBoardTest, MoveValidWhenDifferentNumbersInRow) {
    gb->nextMove(2,1,6);
    EXPECT_TRUE(gb->nextMove(4,1,7));
}

TEST_F(GameBoardTest, MoveInvalidWhenSameNumberInRow) {
    gb->nextMove(1, 3, 3);
    EXPECT_FALSE(gb->nextMove(9, 3, 3));
}

TEST_F(GameBoardTest, NextMoveRowOutOfUpperBounds) {
    EXPECT_FALSE(gb->nextMove(9,11,1));
}

TEST_F(GameBoardTest, InitializeEmptyTest) {
    auto smallergb = new Gameboard(2);
    EXPECT_TRUE(smallergb->get2DArray()[0][0] == 0 && smallergb->get2DArray()[0][1] == 0
                && smallergb->get2DArray()[1][0] == 0 && smallergb->get2DArray()[1][1] == 0 );
}

TEST_F(GameBoardTest, UndoTestWithNoMovesOnStackReturnsFalse) {
    EXPECT_FALSE(gb->undo());
}

TEST_F(GameBoardTest, UndoTestWithMovesOnStackReturnsTrue) {
    gb->nextMove(1,1,1);
    EXPECT_TRUE(gb->undo());
}

TEST_F(GameBoardTest, UndoAfterOneMoveResultsInEmptyBoard) {
    gb->nextMove(1,1,1);
    EXPECT_TRUE(gb->get2DArray()[0][0] == 1);
    gb->undo();
    EXPECT_TRUE(gb->get2DArray()[0][0] == 0);
}

TEST_F(GameBoardTest, IsSolvedReturnsFalseOnEmptyField) {
    EXPECT_FALSE(gb->isSolved());
}
