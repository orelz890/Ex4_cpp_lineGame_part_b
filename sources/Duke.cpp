
#include "Duke.hpp"

namespace coup
{

    Duke::Duke(Game &game, std::string name) : Player(game, name)
    {
        this->my_role = "Duke";
        game.add_player(name);
    }

    void Duke::tax()
    {
        if (strcmp(this->my_game->turn().c_str(), name.c_str()) != 0)
        {
            throw std::runtime_error("Not your turn " + my_role + " " + name + "!!");
        }
        if (before_my_turn())
        {
            if (this->coins() >= MUST_COUP_AMOUNT)
            {
                throw std::runtime_error("Must coup!\n");
            }
            this->my_game->set_player_action(ZERO, name);
            this->set_coins(this->coins() + TAX);
            this->last_action[0] = "tax";
            this->last_action[1] = "";
        }
        this->my_game->set_next_player_turn();
    }

    void Duke::block(Player &blocked_player)
    {
        if (this->my_game->get_player_action(blocked_player.get_player_name()) != FOREGIN_AID)
        {
            throw std::runtime_error("Duke can't block this player action");
        }
        this->my_game->set_player_action(FOREGIN_AID_BLOCKED, blocked_player.get_player_name());
    }

}