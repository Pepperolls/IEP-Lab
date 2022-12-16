using namespace std;

#include <iostream>
#include <string>
#include <memory>

class CristianoRonaldo
{
private:
    shared_ptr<string> celebration;

public:
    CristianoRonaldo(shared_ptr<string> sound) : celebration(sound) {}

    void siu() const
    {
        cout << *celebration << endl;
    }
};

class Messi
{
private:
    auto_ptr<string> commentary;

public:
    Messi(auto_ptr<string> sound) : commentary(sound) {}

    void ankaraMessi() const
    {
        cout << *commentary << endl;
    }
};

template <typename T>
class Player
{
private:
    T *pointer;
    int *counter;

public:
    Player(T *ptr) : pointer(ptr), counter(new int(1)) {}

    Player(const Player &secondPlayer)
        : pointer(secondPlayer.pointer), counter(secondPlayer.counter)
    {
        ++(*counter);
    }

    Player &operator=(const Player &secondPlayer)
    {
        if (this != &secondPlayer)
        {
            if (--(*counter) == 0)
            {
                delete pointer;
                delete counter;
            }

            pointer = secondPlayer.pointer;
            counter = secondPlayer.counter;

            ++(*counter);
        }
        return *this;
    }

    ~Player()
    {
        if (--(*counter) == 0)
        {
            delete pointer;
            delete counter;
        }
    }

    T *getReference()
    {
        return pointer;
    }

    int *getCounter()
    {
        return counter;
    }
};

int main(int, char **)
{
    shared_ptr<string> commonSiu(new string("SIUUUUU"));

    // create two Cristiano Ronaldos
    CristianoRonaldo CristianoRonaldo1(commonSiu);
    CristianoRonaldo CristianoRonaldo2(commonSiu);

    // both CristianoRonaldos siu
    CristianoRonaldo1.siu();
    CristianoRonaldo2.siu();

    // when both CristianoRonaldos are off the pitch, the siu is no longer

    auto_ptr<string> messiCommentary(new string("Ankara Messi Ankara Messi Ankara Messi Ankara Messi Ankara Messi"));

    // create a Messi
    Messi Messi(messiCommentary);

    // Messi scores a goal, hence the commentator goes wild
    Messi.ankaraMessi();
    // Messi is off the pitch, so the commentator cools down

    Player<string> player(new string("GOAT"));
    // a copy of the first Player
    Player<string> player2 = player;

    // another copy through the use of the copy constructor
    Player<string> player3(player);

    player = player3;
    cout << *(player.getReference()) << '\n';
    cout << *(player.getCounter()) << '\n';

    return 0;
}
