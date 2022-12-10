#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Player {
    bool isAlive;
    size_t saveCards;
    const size_t ID;
    Player(size_t id): isAlive(true), saveCards(0), ID(id) {}
};

unsigned int kittens( const string cards, size_t players) {
    std::queue<char> cardsQ;
    std::queue<Player> playerTurn;
    for(int i = 1; i <= players; ++i) {
        playerTurn.push(Player(i));
    }
    for(int i = 0; cards[i] != '\0'; ++i) {
        cardsQ.push(cards[i]);
    }
    while(playerTurn.size() > 1) {
        Player onTurn = playerTurn.front();
        playerTurn.pop();
        char curCard  = cardsQ.front();
        cardsQ.pop();
        if(curCard == 'B' && onTurn.saveCards != 0) {
            onTurn.saveCards--;
            cardsQ.push(curCard);
        }
        else if(curCard == 'B' && onTurn.saveCards == 0){
            onTurn.isAlive = false;
        }
        if(curCard == 'S') {
            onTurn.saveCards++;
        }
        if(onTurn.isAlive) playerTurn.push(onTurn);
    }
    return playerTurn.front().ID;
}

int bfs(const vector<vector<int>>& g, unsigned from, unsigned to) {
    if (!g[from].size())  return -1;
    size_t size = g.size();
    std::vector<bool> visited(size);
    for (int i = 0; i < size; ++i) {
        visited[i] = false;
    }

    std::queue<int> neighbours;
    neighbours.push(from);
    visited[from] = true;
    int point;
    int steps = 0;
    while (!neighbours.empty()) {
        point = neighbours.front();
        neighbours.pop();
        if (!visited[point]) visited[point] = true;
        for (int i = 0; i < g[point].size(); ++i) {
            if (!i) steps++;
            if (!visited[g[point][i]]) {
                neighbours.push(g[point][i]);
                visited[g[point][i]] = true;
            }
        }
        if (visited[to])
            return steps;
    }
    if (visited[to])
        return steps;
    return -1;
}

unsigned int horse( const string from, const string to) {
    return 0;
}

unsigned int islands(const vector<vector<int>>& g) {
    return 0;
}

