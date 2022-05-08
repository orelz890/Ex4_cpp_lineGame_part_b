
#include "Assassin.hpp"
#include <iostream>

namespace coup
{

    Assassin::Assassin(Game &game, std::string name) : Player(game, name)
    {
        this->my_role = "Assassin";
        game.add_player(name);
    }

    void Assassin::coup(Player &player)
    {
        if (!this->my_game->get_game_is_on())
        {
            throw std::runtime_error("The game didn't start yet..\n");
        }
        if (strcmp(this->my_game->turn().c_str(), name.c_str()) != 0)
        {
            throw std::runtime_error("Not your turn " + my_role + " " + name + "!!");
        }
        if (before_my_turn())
        {
            std::vector<std::string> players_left = this->my_game->players();
            bool flag = false;
            for (std::string &name : players_left)
            {
                if (strcmp(name.c_str(), player.get_player_name().c_str()) == 0)
                {
                    flag = true;
                }
            }
            if (!flag)
            {
                throw std::runtime_error("There is no player who match the player you want to coup!\n");
            }
            if (this->coins() < ASSASSIN_COUP_COST)
            {
                std::string temp = this->role() + " " + this->name + " doesn't have enough coins for couping!";
                std::cout << this->role() + " " + this->name + " has " << this->coins() << " coins\n";
                throw std::runtime_error(temp);
            }
            if (this->coins() < COUP_COST)
            {
                this->set_coins(this->coins() - ASSASSIN_COUP_COST);
                this->last_action[0] = "Assasin_kill";
                this->last_action[1] = player.get_player_name();
                if ( players_left.size() != 2)
                {
                    this->my_game->set_player_action(ASSASSIN_COUP , player.get_player_name());
                    this->my_game->set_kill_list(player.get_player_name(),this->name);
                    this->my_game->set_next_player_turn();
                }
                else
                {
                    this->my_game->kill_player(player.get_player_name());
                }                
            }
            if (this->coins() >= COUP_COST)
            {   
                this->my_game->kill_player(player.get_player_name());
                this->set_coins(this->coins() - COUP_COST);
                this->last_action[0] = "kill";
                this->last_action[1] = player.get_player_name();
            }
        }
    }

}
