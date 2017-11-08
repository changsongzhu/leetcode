Card Game

enum class Suit { Diamonds=1, Hearts, Clubs, Spades};

class Card{

    Card(int value, Suit suit)
    {
         this->val=value;
         this->suit=suit;
    }
    void setVal(int val)
    {
         this->val=val;
    }
    void setSuit(Suit suit)
    {
         this->suit=suit;
    }
    int getVal()
    {
         return val;
    }
    int getSuit()
    {
        return suit;
    }
private:
    int val;
    Suit suit;
};

class CardGame{
public:
    CardGame()
    {
         vector<Suit> suits={Suit::Diamonds, Suit::Hearts, Suit::Clubs, Suit::Spades};
         cards.resize(52);
         int cnt=0;
         for(int i=0;i<suits.size();i++)
         {
             for(int j=1;j<13;j++)
             {
                  cards[cnt].setVal(i);
                  cards[cnt].setSuit(suits[i]);
                  cnt++;
             }
         }
    }

    void shuffleCards()
    {
         for(int i=0;i<52;i++)
         {
             int idx=rand()%52;
             swap(cards[i], cards[idx]);
         }
    }
    void resetCards()
    {
         int cnt=0;
         vector<Suit> suits={Suit::Diamonds, Suit::Hearts, Suit::Clubs, Suit::Spades};
         for(int i=0;i<suits.size();i++)
         {
             for(int j=1;j<13;j++)
             {
                  cards[cnt].setVal(i);
                  cards[cnt].setSuit(suits[i]);
                  cnt++;
             }
         }
    }

private:
    vector<Card> cards;
};

