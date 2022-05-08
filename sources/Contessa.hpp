#pragma once

#include "Player.hpp"

namespace coup{

    class Contessa : public Player{
        public:
        Contessa(Game &game, std::string name);
        void block(Player& player);

    };



}