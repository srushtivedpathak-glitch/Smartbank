#ifndef DATABASE_H
#define DATABASE_H

#include <mysql.h>

class Database
{
private:
    MYSQL* connection;

public:
    Database();

    bool connect();
    void disconnect();

    MYSQL* getConnection();
};

#endif