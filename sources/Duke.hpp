#pragma once
#include "Player.hpp"

namespace coup{

    class Duke : public Player{

        public:
        Duke(Game &game, std::string name);
        
        void tax();
        void block(Player& blocked_player);
    };

}