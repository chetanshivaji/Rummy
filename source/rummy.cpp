#include<iostream>
using namespace std;
#include"rummy.h"
///////private
//
void Rummy::getCards()
{
    vSuits.resize(NUMSUITS);
    vJokers.resize(NUMSUITS);
    
    cout<<vSuits.size()<<endl;
    //get cards from user
    int numberOfCards = 13;
    cout<<"Enter 13 cards; in form symbol space card number from 1 to 14 \n \
        0 for heart,\n \
        1 for diamonds \n \
        2 for spades \n \
        3 for clubs \n \
        9 9 for real joker with no symbol no number\n" ;
    cout<< "J Q K A are sequentially 11 12 13 1 "<<endl;
    cout<<"At end enter joker\n";
    int x,y;
    while(numberOfCards--)
    {
        cin>>x>>y;
        vSuits[x].insert(y);
        //cout<<x<<" "<<y<<endl;
    }
    //getting gamejoker
    cin>>x>>y;
    gameJoker.first = x;
    gameJoker.second = y;
    
}

void Rummy::initSeperateCards()
{

}
void Rummy::printCardsSuitWise()
{
    cout<<"printing suits------>";
    for(int i=0;i<NUMSUITS;i++)
    {
        cout<<"suit "<<i<<endl;
        for(auto it = vSuits[i].begin();it!=vSuits[i].end();it++)
        {
            cout<<*it<<"  ";
        }
        cout<<endl;
    }
}

void Rummy::printGroupsSuitWise()
{
    cout<<"Printing groups------>"<<endl;
    
    for(int i=0;i<NUMSUITS;i++)
    {
        cout<<"suit "<<i<<endl;
        for(auto it = vGroups[i].begin();it!=vGroups[i].end();it++)
        {
            cout<<*it<<"  ";
        }
        cout<<endl;
    }
}
void Rummy::printJokers()
{
    cout<<"Printing groups------>"<<endl;
    
    for(int i=0;i<NUMSUITS;i++)
    {
        cout<<"suit "<<i<<endl;
        for(auto it = vJokers[i].begin();it!=vJokers[i].end();it++)
        {
            cout<<*it<<"  ";
        }
        cout<<endl;
    }
}

bool isLife()
{
    //check if pure sequence available
#if 0 
    if(seq)
        return true;
    else
        return false;
#endif 
    return false;
}

void Rummy::takeOutJokers()
{
    for(int i=0; i<NUMSUITS; i++)
    {
        //for each suit
        for(auto it = (vSuits[i].begin());it!=vSuits[i].end(); it++)
        {
            if(*it == gameJoker.second )
            {
                vJokers[i].insert(*it); //put in jokers colletion
                auto itBack = it;
                vSuits[i].erase(itBack); //remove from original cards set
            }           
        }
        
    }
}


void Rummy::sortAndCheckLife()
{
    for(int i=0; i<NUMSUITS; i++)
    {
        //for each suit
        int seqCount = 0;
        multiset<int>sTemp;
        multiset<int>::iterator itSeqBeg,it,itPrev;
        for(it=next(vSuits[i].begin());    it!=vSuits[i].end();   it++)
        {
            itPrev = prev(it);
            if((*it-*itPrev) == 1)
            {
                    if(seqCount==0)
                    {//coming in for first time, take begin iterator of sequence used later to delete from orignal.
                        itSeqBeg = itPrev;
                    }
                    seqCount++;
                    sTemp.insert(*itPrev);
            }
            else
            {
                if(seqCount>=2)
                {
                    lifeWithoutJoker = true;    //got life
                    //got sequence
                    sTemp.insert(*itPrev);
                    vGroups.push_back(sTemp);
                    //remove from orig.
                    vSuits[i].erase(itSeqBeg, it); //delete begin to current range from orig
                }
                else
                {
                    sTemp.clear();
                }
                seqCount = 0;
            }
            
        }
        if(seqCount>=2)
        {
            lifeWithoutJoker = true;    //got life
            //got sequence
            sTemp.insert(*itPrev);
            vGroups.push_back(sTemp);
            //remove from orig.
            vSuits[i].erase(itSeqBeg, it); //delete begin to current range from orig
        }
                
    }
}

void Rummy::createGroups()
{
    //first take out all jokers;
    takeOutJokers();
    //once jokers are taken out look for life in purse sequence.
    sortAndCheckLife();
    
    printCardsSuitWise();
    printGroupsSuitWise();
    printJokers();
    
    //in each suits see if any life(groups with ascending sequcne of diff 1 present)
    
}
//////public
void Rummy::showInfo()
{
    cout<<"This is Rummy Game of 13 cards, \n\
            this program is to help single player \n\
            win, with trying multiple combinations each time \n\
            \n";
    

}
void Rummy::startGame()
{
    
    showInfo();
    getCards();
    printCardsSuitWise();
    createGroups();
    
    bool done=false;
    #if 0
    while(done == false)
    {
        
        //arrange(); //first arrange 
        bool done  = isDone();
        if(done)
        {
            cout<<"I WIN"<<endl;
            return true;
        }
        else
        {
            //first we need to check joker
            bool life = isLife();
            if(life)
            {
                //int jokerNumber = getJoker();
                //arrangeWithJoker();
            }
        
        }    
    }
    #endif
}

void Rummy::GetNewCard()
{
    
}
void Rummy::fetchStackCard()
{
    
}
void Rummy::tryCombination()
{
    
}
void Rummy::throwCard()
{
    
}