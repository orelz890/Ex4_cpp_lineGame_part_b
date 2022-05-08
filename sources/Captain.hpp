#pragma once

#include "Player.hpp"

const int STEAL_AMOUNT = 1;

namespace coup{

    class Captain : public Player{

        private:
        Player vic;

        public:
        Captain(Game &game, std::string name);
        virtual bool before_my_turn();
        void steal(Player& player);
        void block(Player& captain);
    };



}