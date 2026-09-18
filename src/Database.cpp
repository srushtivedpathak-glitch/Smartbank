#include "../include/Database.h"
#include <iostream>

Database::Database()
{
    connection = nullptr;
}

bool Database::connect()
{
    connection = mysql_init(nullptr);

    if (connection == nullptr)
    {
        std::cout << "MySQL initialization failed." << std::endl;
        return false;
    }

    if (mysql_real_connect(
            connection,
            "localhost",
            "root",
            "27062007",
            "smartbank",
            3306,
            nullptr,
            0) == nullptr)
    {
        std::cout << "Database connection failed: "
                  << mysql_error(connection) << std::endl;

        mysql_close(connection);
        connection = nullptr;

        return false;
    }

    std::cout << "Database connected successfully." << std::endl;
    return true;
}

void Database::disconnect()
{
    if (connection != nullptr)
    {
        mysql_close(connection);
        connection = nullptr;
    }
}

MYSQL* Database::getConnection()
{
    return connection;
}