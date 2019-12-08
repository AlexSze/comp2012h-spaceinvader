#ifndef PLAYER_RECORD_H
#define PLAYER_RECORD_H

#include <QStringList>

using namespace std;

class player_record
{
public:
    player_record(unsigned int);
    player_record(unsigned int, QStringList);
    player_record(const player_record&);

    unsigned int get_score() const;
    QStringList get_name() const;

    bool operator>(player_record&);
    bool operator<(player_record&);
    bool operator>=(player_record&);
    bool operator<=(player_record&);
    bool operator==(player_record&);
    bool operator!=(player_record&);

    // concat
    player_record& operator+=(player_record&);

private:
    unsigned int score;
    QStringList name;
};

#endif // PLAYER_RECORD_H
