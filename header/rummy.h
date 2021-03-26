
#ifndef RUMMY_H
#define RUMMY_H
#include<vector>
#include<set>
#define NUMSUITS 4

class Rummy
{
private:
    vector<multiset<int>>vSuits,vGroups,vJokers;
    pair<int,int> gameJoker;
    
    bool lifeWithoutJoker;
    bool LifeWithJoker;
    
    void getCards();
    void initSeperateCards();
    void createGroups();
    void sortCards();
    bool isLife();
    void printCardsSuitWise();
    void printGroupsSuitWise();
    void printJokers();
    void sortAndCheckLife();
    void takeOutJokers();
    
public:
    Rummy():lifeWithoutJoker(false),LifeWithJoker(false)
    {}
    void showInfo();
    void startGame();
    void GetNewCard();
    void fetchStackCard();
    void tryCombination();
    void throwCard();

};

#endif