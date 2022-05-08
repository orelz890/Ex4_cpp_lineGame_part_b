#pragma once

#include "Player.hpp"

namespace coup{

    class Captain : public Player{

        public:
        Captain(Game &game, std::string name);
        void set_vic_coins(const int amount);
        virtual bool before_my_turn();
        void steal(Player& player);
        void block(Player& captain);
    };



}