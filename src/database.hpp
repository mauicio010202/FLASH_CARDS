#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <QSqlDatabase>
#include <QList>
#include "Card.hpp"

class Database {
public:
    static bool initialize(const QString &dbPath = "flashcards.db");
    static bool addCard(const Card &card);
    static QList<Card> getAllCards();

private:
    static QSqlDatabase db;
};

#endif // DATABASE_HPP
