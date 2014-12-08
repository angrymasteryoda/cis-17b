#ifndef GAMESAVE_H
#define GAMESAVE_H

class GameSave
{
public:
    GameSave( int*, int*, int, int );
    ~GameSave();

    int getTimePlayed() const;
    int getLevel() const;
    int *getBoard() const;
    int *getMask() const;

    void setTimePlayed(int value);
    void setLevel(int value);
    void setBoard(int *value);
    void setMask(int *value);
private:
    int* mask;
    int* board;
    int level;
    int timePlayed;
};

#endif // GAMESAVE_H
