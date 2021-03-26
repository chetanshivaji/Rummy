#include <stdio.h>
#include<iostream>
using namespace std;
#include"rummy.h"
//Priorities
//conditions
//options
//creating possibilities


/*
 //INIT  : always prioritize pure sequence
 1. Get cards
 2. put in different suits
 3. sort each group
 4. look for life sequence, if no sequence look for sets -> sets needs to be reconsidered when no pure sequence present and if something makes pure sequence.
  *     - first take out all jokers
  *     - look for life sequence without jokers
  *     - life yes -> never touch life triplet or more.
  *            no  -> take help of jokers and see if life possible
  *                     yes -> every turn need to check if triplet having joker and forming life can be replaced by new card to make triplet so joker can be used elsewhere.
  *                     no  -> just create triplet with use of jokers a. checking diff 2. b. prefix c. postfix to put joker at.
  *     - check two trials -> 1. sequence with jokers or 2. set with jokers 3. pure sets   
 5. remaining diff of 2 use joiker, 
            a. consider how many jokers.
            b. consider how many diff of 2
            c. consider bigger cards, to make set first with jokers
 
  * 
  * // Each turn  :always prioritize pure sequence
  * 

6. two cards possbile 
    A. thrown or B. take from stack
     *   *     1. card can be normal number
               2. joker

    A. Thrown card try combinations.
    1. makes full sequence 1. to make new triplet 2. with pre or post fix in existing sequence.
        both above cases call throw.
    2. Doesn't make sequence. B. get new card from stack. try case one aobve or below.
        1. see if it makes half sequence
            a. Two card sequence.
                call throw, if easy throw of very odd card not possible, ie. all others are two card sequence in throw, throw, bigger card in existing sequence
            b. diff two sequence.
                 call throw,if easy throw of very odd card not possible,ie.  all other diff two sequence, in throw, throw, bigger card in existing sequence.
    

    if card is joker.
     * think think think
     1. check diff 2 in all suits put with bigger and make triplet.(if any extra points with sequence of same symbol prefer same symbol)
     2. if no diff 2 put aside and call throw.
    

Thow logic
1. same cards.  a. if more than two same  cards throw bigger 
 *              b. put in queue of throwing another same card.
2. only one in suit throw bigger.
3. 
*/

    
int main(int argc, char **argv)
{
    Rummy*game = new Rummy();
    game->startGame();
    return 0;
}
