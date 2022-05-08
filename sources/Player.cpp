
#include "Player.hpp"
#include <iostream>

namespace coup
{
    Player::Player()
    {
        this->name = "non";
        this->money = 0;
        this->my_game = NULL;
        this->vic = NULL;
    }

    Player::Player(Game &game, std::string &name)
    {
        this->my_game = &game;
        this->vic = NULL;
        this->name = name;
        this->money = 0;
    }

    bool Player::before_my_turn()
    {
        if (!this->my_game->get_game_is_on())
        {
            throw std::runtime_error("The game didn't start yet..\n");
        }
        this->my_game->set_game_started();
        if (!this->my_game->get_is_killed(name).empty())
        {
            std::string temp;
            this->my_game->set_kill_list(name,temp);
            this->my_game->kill_player(name);
            return false;
        }        
        int act = this->my_game->get_player_action(this->name);
        if (act == FOREGIN_AID_BLOCKED)
        {
            this->my_game->set_player_action(ZERO, name);
            this->money -= 2;
        }
        return true;
    }

    void Player::inc_vic_coins(const int amount){
        this->vic->set_coins(this->vic->coins() + amount);
    }

    std::string &Player::get_player_name()
    {
        return name;
    }

    int Player::coins() const
    {
        return this->money;
    }

    void Player::set_coins(const int c)
    {
        this->money = c;
    }

    std::string Player::role()
    {
        return this->my_role;
    }

    void Player::income()
    {
        if (strcmp(this->my_game->turn().c_str(), name.c_str()) != 0)
        {
            throw std::runtime_error("Not your turn " + my_role + " " + name + "!!");
        }
        if (before_my_turn())
        {
            if (this->money >= MUST_COUP_AMOUNT)
            {
                throw std::runtime_error("Must coup!\n");
            }
            this->money++;
            this->last_action[0] = "income";
            this->last_action[1] = "";
        }
        this->my_game->set_next_player_turn();
    }

    void Player::foreign_aid()
    {
        if (strcmp(this->my_game->turn().c_str(), name.c_str()) != 0)
        {
            throw std::runtime_error("Not your turn " + my_role + " " + name + "!! it's " + this->my_game->turn() + " turn!");
        }
        if (before_my_turn())
        {
            if (this->money >= MUST_COUP_AMOUNT)
            {
                throw std::runtime_error("Must coup!\n");
            }
            this->my_game->set_player_action(FOREGIN_AID, name);
            this->last_action[0] = "foreign_aid";
            this->last_action[1] = "";
            this->money += 2;
        }
        this->my_game->set_next_player_turn();
    }

    void Player::coup(Player &player)
    {
        if (strcmp(this->my_game->turn().c_str(), name.c_str()) != 0)
        {
            throw std::runtime_error("Not your turn " + my_role + " " + name + "!!");
        }
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
        if (before_my_turn())
        {
            if (this->money < COUP_COST)
            {
                std::string warning = this->name + " dont has enough coins!";
                std::cout << warning << " he has only " << this->coins() << " coins!\n";
                throw std::runtime_error(warning);
            }
            this->my_game->kill_player(player.get_player_name());
            this->money -= COUP_COST;
            this->last_action[0] = "kill";
            this->last_action[1] = name;
        }
    }

}
