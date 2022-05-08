
#pragma once
#include "Game.hpp"

namespace coup
{
    class Player
    {

    protected:
        Game* my_game;
        Player* vic;
        std::string name;
        std::string my_role;
        int money;

    public:
        std::string last_action[LAST_ACTION_VALS];
        Player();
        Player(Game &game, std::string &name);
        Game& get_game(){
            return *this->my_game;
        }
        virtual bool before_my_turn();
        std::string& get_player_name();
        void inc_vic_coins(const int amount);
        int coins() const;
        void set_coins(const int c);
        void set_last_action(std::string act, std::string name);
        std::string role();
        void income();
        void foreign_aid();
        virtual void coup(Player& player);
    };

}
