#pragma once

#include "Player.hpp"

namespace coup
{
    class Ambassador : public Player
    {
        public:
        Ambassador(Game &game, std::string name);

        void transfer(Player& from, Player& to);

        void block(Player& captain);
    };

}
