#ifndef PLAYER_RECORD_H
#define PLAYER_RECORD_H

#include <string>

using namespace std;

class player_record
{
public:
    player_record(int a);
    player_record(int a, string b);
    int get_score();
    string get_name();

private:
    int score;
    string name;
};

#endif // PLAYER_RECORD_H
