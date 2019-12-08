#include "player_record.h"

player_record::player_record(unsigned int score)
    : score(score),
    name("") {}

player_record::player_record(unsigned int score, QStringList name)
    : score(score),
    name(name) {}

player_record::player_record(const player_record& p)
    : score(p.score),
    name(p.name) {}


unsigned int player_record::get_score() const
{
    return score;
}

QStringList player_record::get_name() const
{
    return name;
}

bool player_record::operator>(player_record& p) {
    return score > p.score;
}

bool player_record::operator<(player_record& p){
    return score < p.score;
}

bool player_record::operator>=(player_record& p) {
    return score >= p.score;
}

bool player_record::operator<=(player_record& p) {
    return score <= p.score;
}

bool player_record::operator==(player_record& p) {
    return score == p.score;
}

bool player_record::operator!=(player_record& p) {
    return score != p.score;
}

player_record& player_record::operator+=(player_record& p) {
    if (
            // duplication check
            this == &p ||
            // score must be equal
            score != p.score
            )
        // do nothing
        return *this;
    // append names to QStringList
    name.append(p.name);
    // remove duplicates of the same name
    name.removeDuplicates();
    return *this;
}
