
#include "Ambassador.hpp"
#include <iostream>

namespace coup
{

    Ambassador::Ambassador(Game &game, std::string name) : Player(game, name) 
    {
        this->my_role = "Ambassador";
        game.add_player(name);
    }

    void Ambassador::transfer(Player& from, Player& to)
    {
        if (strcmp(this->my_game->turn().c_str(), name.c_str()) != 0)
        {
            throw std::runtime_error("Not your turn " + my_role + " " + name + "!!");
        }
        if (this->coins() >= MUST_COUP_AMOUNT)
        {
            throw std::runtime_error(this->get_player_name() + " you have more than 10 coins you must coup!\n");
        }
        if (from.coins() < TRANSFER_AMOUNT)
        {
            throw std::runtime_error("Problem! " + from.role() + " " + from.get_player_name() + " dosn't have enough money..\n");
        }
                
        if (before_my_turn())
        {
            from.set_coins(from.coins() - TRANSFER_AMOUNT);
            to.set_coins(to.coins() + TRANSFER_AMOUNT);
            this->last_action[0] = "transfer";
            this->last_action[1] = "";
        }
        this->my_game->set_next_player_turn();
    }

    void Ambassador::block(Player &captain)
    {
        if (strcmp(captain.role().c_str(), "Captain") != 0)
        {
            throw std::runtime_error(captain.get_player_name() + " is not a captain you are an Ambassador!\n");
        }
        if (this->my_game->get_player_action(captain.get_player_name()) == STEAL)
        {
            throw std::runtime_error(captain.get_player_name() + " didnt steal from anyone therfore, you cant block him!\n");
        }
        captain.set_coins(captain.coins() - STEAL);
        captain.inc_vic_coins(STEAL);
    }


}