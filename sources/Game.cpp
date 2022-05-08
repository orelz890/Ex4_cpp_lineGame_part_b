
#include "Game.hpp"
#include <iostream>

namespace coup
{

    Game::Game()
    {
        this->player_turn = 0;
        this->game_is_on = false;
    }

    void Game::add_player(std::string &name)
    {
        for (int i = 0; i < this->active_players.size(); i++)
        {
            if (strcmp(this->active_players.at((unsigned int)i).c_str(), name.c_str()) == 0)
            {
                throw std::runtime_error("This nickname already in use!");
            }
        }

        if (!this->active_players.empty())
        {
            this->game_is_on = true;
        }

        this->active_players.insert(active_players.cend(), name);
        this->action[name] = ZERO;
        this->kill_list[name] = "";
    }

    bool Game::get_game_is_on(){
        return this->game_is_on;
    }
    void Game::kill_player(std::string &name)
    {
        std::cout<< "im in kill_player\n";
        fflush(stdout);
        for (int i = 0; i < this->active_players.size(); i++)
        {
            std::cout << "player " << i << " == " << active_players.at((unsigned int)i) << '\n';

            if (strcmp(this->active_players.at((unsigned int)i).c_str(),name.c_str()) == 0)
            {                
                if (i < player_turn)
                {
                    this->player_turn -= 1;
                    std::cout << "player turn -= 1\nnow player == " << this->player_turn << '\n';
                    fflush(stdout);
                }
                std::cout << "killed player " << active_players.at((unsigned int)i) << "\n";
                this->active_players.erase(this->active_players.begin() + i);
                this->action.erase(name);
                this->kill_list.erase(name);
                break;
            }
        }
        set_next_player_turn();
    }

    void Game::set_next_player_turn()
    {
        this->player_turn = (this->player_turn + 1) % (int)this->active_players.size();
    }

    void Game::set_player_action(const int do_action, std::string &to)
    {
        this->action.at(to) = do_action;
    }

    void Game::clear_action(std::string &name){
        this->action.at(name) = ZERO;
    }

    int Game::get_player_action(std::string &name){
        return this->action.at(name);
    }

    void Game::set_kill_list(std::string &who_to_kill, std::string &name){
        // this->kill_list.at(name) = who_to_kill;
        this->kill_list.at(who_to_kill) = name;
    }

    std::string Game::get_is_killed(std::string &name){
        return this->kill_list.at(name);
    }

    std::string Game::turn()
    {
        return this->active_players.at((unsigned int)player_turn);
    }

    std::string Game::winner()
    {
        std::vector<std::string> temp;
        for (std::string name : this->active_players)
        {
            if (this->kill_list.at(name).empty())
            {
                temp.insert(temp.cend(),name);
            }
        }
        if (temp.size() != 1)
        {
            throw std::runtime_error("There is no winner yet!");
        }

        return temp.at((unsigned int)0);
    }

    std::vector<std::string> Game::players()
    {
        this->active_players_show.clear();
        for (std::string name : this->active_players)
        {
            if (strcmp(get_is_killed(name).c_str(), "") == 0)
            {
                active_players_show.insert(active_players_show.cend(),name);
            }
        }
        return active_players_show;
    }

}
