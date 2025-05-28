#include "database.hpp"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFileInfo>

QSqlDatabase Database::db = QSqlDatabase();

bool Database::initialize(const QString &dbPath) {
    if (!QSqlDatabase::isDriverAvailable("QSQLITE")) {
        qDebug() << "SQLite driver not available";
        return false;
    }

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QFileInfo(dbPath).absoluteFilePath());
    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    return query.exec(R"(
        CREATE TABLE IF NOT EXISTS flashcards (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        front TEXT NOT NULL,
        back TEXT NOT NULL,
        front_image_path TEXT,
        back_image_path TEXT,
        code TEXT
        )
    )");
}

bool Database::addCard(const Card &card) {
    QSqlQuery query;
    query.prepare("INSERT INTO flashcards (front, back, front_image_path, back_image_path, code) VALUES (:fr, :bk, :fimg, :bimg, :c)");
    query.bindValue(":fr", QString::fromStdString(card.getFront()));
    query.bindValue(":bk", QString::fromStdString(card.getBack()));
    query.bindValue(":fimg", QString::fromStdString(card.getFrontImagePath()));
    query.bindValue(":bimg", QString::fromStdString(card.getBackImagePath()));
    query.bindValue(":c", QString::fromStdString(card.getCodeSnippet()));

    if (!query.exec()) {
        qDebug() << "Insert error:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<Card> Database::getAllCards() {
    QList<Card> cards;

    QSqlQuery query("SELECT front, back, front_image_path, back_image_path, code FROM flashcards");
    if (!query.exec()) {
        qDebug() << "Select error:" << query.lastError().text();
        return cards;
    }

    while (query.next()) {
        std::string front = query.value(0).toString().toStdString();
        std::string back = query.value(1).toString().toStdString();
        std::string frontImg = query.value(2).toString().toStdString();
        std::string backImg = query.value(3).toString().toStdString();
        std::string code = query.value(4).toString().toStdString();

        cards.append(Card(front, back, frontImg, backImg, code));
    }

    return cards;
}
