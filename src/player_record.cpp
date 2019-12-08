#include "player_record.h"

player_record::player_record(int a){
    score= a;
    name= " ";
}

player_record::player_record(int a, string b)
{
    score= a;
    name= b;
}

int player_record::get_score()
{
    return score;
}

string player_record::get_name()
{
    return name;
}
