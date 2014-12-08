#include "gamesave.h"

GameSave::GameSave( int* mask, int* board, int level, int time ){
    this->mask = mask;
    this->board = board;
    this->level = level;
    this->timePlayed = time;
}

GameSave::~GameSave(){
    delete [] mask;
    delete [] board;
}

int GameSave::getTimePlayed() const
{
    return timePlayed;
}

void GameSave::setTimePlayed(int value)
{
    timePlayed = value;
}
int GameSave::getLevel() const
{
    return level;
}

void GameSave::setLevel(int value)
{
    level = value;
}
int *GameSave::getBoard() const
{
    return board;
}

void GameSave::setBoard(int *value)
{
    board = value;
}
int *GameSave::getMask() const
{
    return mask;
}

void GameSave::setMask(int *value)
{
    mask = value;
}



