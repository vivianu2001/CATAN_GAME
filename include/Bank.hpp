#ifndef BANK_HPP
#define BANK_HPP

class Player;

class Bank
{
public:
    virtual bool canAfford(const Player &player) const = 0;
    virtual void purchase(Player &player) = 0;
    virtual ~Bank() = default;
};

#endif // BANK_HPP
