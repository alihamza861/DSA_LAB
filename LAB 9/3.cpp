#include <iostream>
using namespace std;

class Player {
public:
    int playerID;
    int score;
    Player* next;

    Player(int id, int s) {
        playerID = id;
        score = s;
        next = NULL;
    }
};

class Game {
private:
    Player* current;

public:
    Game() {
        current = NULL;
    }


    void addPlayer(int id, int score) {
        Player* newPlayer = new Player(id, score);


        if (current == NULL) {
            current = newPlayer;
            newPlayer->next = newPlayer;
        }
        else {
            Player* temp = current;


            while (temp->next != current) {
                temp = temp->next;
            }

            temp->next = newPlayer;
            newPlayer->next = current;
        }

        cout << "Player " << id << " joined the game.\n";
    }


    void displayPlayers() {
        if (current == NULL) {
            cout << "No players in game.\n";
            return;
        }

        Player* temp = current;

        cout << "\nPlayers in Game:\n";

        do {
            cout << "PlayerID: " << temp->playerID
                << " Score: " << temp->score << endl;
            temp = temp->next;
        } while (temp != current);
    }


    void removePlayer(int id) {
        if (current == NULL) {
            cout << "Game is empty.\n";
            return;
        }

        Player* temp = current, * prev = NULL;


        if (current->playerID == id && current->next == current) {
            delete current;
            current = NULL;
            cout << "Player " << id << " removed.\n";
            return;
        }


        if (current->playerID == id) {


            Player* last = current;
            while (last->next != current) {
                last = last->next;
            }

            Player* del = current;
            current = current->next;
            last->next = current;

            delete del;

            cout << "Player " << id << " removed.\n";
            return;
        }


        prev = current;
        temp = current->next;

        while (temp != current && temp->playerID != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == current) {
            cout << "Player not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;

        cout << "Player " << id << " removed.\n";
    }


    void nextTurn() {
        if (current == NULL)
            return;

        current = current->next;

        cout << "Current Turn -> Player "
            << current->playerID << endl;
    }


    void skipPlayer() {
        if (current == NULL)
            return;

        cout << "Skipping Player "
            << current->next->playerID << endl;

        current = current->next->next;

        cout << "Now it's Player "
            << current->playerID << "'s turn.\n";
    }


    void checkWinner() {
        if (current != NULL && current->next == current) {
            cout << "\nGame Over!\n";
            cout << "Winner is Player "
                << current->playerID << endl;
        }
    }
};

int main() {

    Game game;


    game.addPlayer(101, 20);
    game.addPlayer(102, 15);
    game.addPlayer(103, 40);
    game.addPlayer(104, 10);

    game.displayPlayers();


    cout << "\n--- Turn Rotation ---\n";
    game.nextTurn();
    game.nextTurn();


    cout << "\n--- Skip Turn ---\n";
    game.skipPlayer();


    cout << "\n--- Removing Players ---\n";
    game.removePlayer(102);
    game.displayPlayers();

    game.removePlayer(103);
    game.removePlayer(104);

    game.displayPlayers();


    game.checkWinner();

    return 0;
}