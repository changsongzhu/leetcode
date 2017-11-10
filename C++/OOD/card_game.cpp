Card Game

//Another Solution
enum Suit { SPADES, CLUBS, HEARTS, DIAMONDS, };
enum Face { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, };

class Card {
public:
    Card(Suit suit, Face face) : suit(suit), face(face) {}
    Card(const Card& orig) : suit(orig.suit), face(orig.face) {}
    Suit getSuit() const { return suit; }
    Face getFace() const { return face; }
private:
    Card() {}
    Suit suit;
    Face face;
    friend class Deck;
};

class Deck {
public:
    Deck() {
        int index = 0;
        for (int i = 0; i < SUITS_PER_DECK; ++i) {
            for (int j = 0; j < CARDS_PER_SUIT; ++j) {
                index = i * CARDS_PER_SUIT + j;
                cards[index].suit = (Suit) i;
                cards[index].face = (Face) j;
            }
        }
    }

    Deck(const Deck& orig) {
        for (int i = 0; i < SUITS_PER_DECK * CARDS_PER_SUIT; ++i) {
            cards[i] = orig.cards[i];
        }
    }

    void Shuffle() {
        int bagSize = SUITS_PER_DECK * CARDS_PER_SUIT;
        int index = 0;
        srand(time(NULL));
        while (bagSize) {
            index = rand() % bagSize;
            swap(cards[--bagSize], cards[index]);
        }
    }

    static const int SUITS_PER_DECK = 4;
    static const int CARDS_PER_SUIT = 13;
private:
    Card cards[SUITS_PER_DECK * CARDS_PER_SUIT];
    friend ostream & operator<<(ostream&, const Deck&);
};



//my Solution


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

