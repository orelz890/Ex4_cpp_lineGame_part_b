#pragma once

#include "Game.hpp"
#include "Player.hpp"

namespace coup{

    class Assassin : public Player{

        public:
        Assassin(Game &game, std::string name);
        virtual void coup(Player& player);
    };



}