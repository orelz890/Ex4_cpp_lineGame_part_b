#pragma once

#include <string>
#include <string.h>
#include <vector>
#include <map>

const int ZERO = 0;
const int MUST_COUP_AMOUNT = 10;
const int LAST_ACTION_VALS = 2;

const int COUP = -1;
const int COUP_COST = 7;
const int TRANSFER = 1;
const int TRANSFER_AMOUNT = 1;
const int STEAL = 2;
const int STEAL_BLOCKED = -2;
const int TAX = 3;
const int ASSASSIN_COUP = -3;
const int ASSASSIN_COUP_COST = 3;
const int ASSASSIN_COUP_BLOCKED = -4;
const int FOREGIN_AID = 4;
const int FOREGIN_AID_AMOUNT = 2;
const int FOREGIN_AID_BLOCKED = -5;
const int BLOCKED = -6;


namespace coup
{

    class Game
    {
    private:
        std::vector<std::string> active_players;
        std::vector<std::string> active_players_show;
        std::map<std::string, int> action;
        std::map<std::string, std::string> kill_list;
        int player_turn;
        bool game_is_on;

    public:
        Game();
        void add_player(std::string &name);
        bool get_game_is_on();
        void kill_player(std::string &name);
        void set_next_player_turn();
        void set_player_action(const int do_action, std::string &to);
        void set_kill_list(std::string &who_to_kill, std::string &name);
        std::string get_is_killed(std::string &name);
        int get_player_action(std::string &name);
        void clear_action(std::string &name);
        std::string turn();
        std::string winner();
        std::vector<std::string> players();
    };

}
