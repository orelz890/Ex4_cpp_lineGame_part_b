
#include "Captain.hpp"

namespace coup
{
    Captain::Captain(Game &game, std::string name) : Player(game, name)
    {
        this->my_role = "Captain";
        this->vic = Player();
        game.add_player(name);
    }

    bool Captain::before_my_turn()
    {
        if (!this->my_game->get_is_killed(this->name).empty())
        {
            std::string temp;
            this->my_game->set_kill_list(name, temp);
            this->my_game->kill_player(name);
            return false;
        }
        int act = this->my_game->get_player_action(this->name);
        if (act == FOREGIN_AID_BLOCKED)
        {
            this->my_game->set_player_action(ZERO, name);
            this->money -= 2;
        }
        if (act == STEAL_BLOCKED)
        {
            this->my_game->set_player_action(ZERO, name);
            this->set_coins(this->coins() - STEAL_AMOUNT);
            vic.set_coins(vic.coins() + STEAL_AMOUNT);
            vic = Player();
        }
        return true;
    }

    void Captain::steal(Player &player)
    {
        if (strcmp(this->my_game->turn().c_str(), name.c_str()) != 0)
        {
            throw std::runtime_error("Not your turn " + my_role + " " + name + "!!");
        }
        if (this->coins() >= MUST_COUP_AMOUNT)
        {
            throw std::runtime_error(this->get_player_name() + " you have 10 coins you must coup!\n");
        }
        if (before_my_turn())
        {
            this->my_game->set_player_action(STEAL, player.get_player_name());
            this->last_action[0] = "steal";
            this->last_action[1] = player.get_player_name();
            this->set_coins(this->coins() + 1);
            player.set_coins(player.coins() - 1);
            vic = player;
        }
        this->my_game->set_next_player_turn();
    }

    void Captain::block(Player &captain)
    {
        if (strcmp(captain.role().c_str(),"Captain") != 0)
        {
            throw std::runtime_error(captain.get_player_name() + " is not a captain you can't block him " + this->role() + " " + this->name + "\n");
        }
        if (this->my_game->get_player_action(captain.get_player_name()) != STEAL)
        {
            throw std::runtime_error(captain.get_player_name() + " didnt steal from anyone therfore, you cant block him!\n");
        }
        this->my_game->set_player_action(STEAL_BLOCKED, captain.get_player_name());
    }

}
