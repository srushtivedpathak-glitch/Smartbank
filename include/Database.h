#ifndef DATABASE_H
#define DATABASE_H

class Database
{
public:
    Database();

    bool connect();
    void disconnect();
};

#endif