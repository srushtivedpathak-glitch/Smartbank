#include "../include/Database.h"
#include <mysql.h>
#include <iostream>

Database::Database()
{
}

bool Database::connect()
{
    MYSQL* conn = mysql_init(NULL);

    if (conn == NULL)
    {
        std::cout << "MySQL initialization failed." << std::endl;
        return false;
    }

    if (mysql_real_connect(
            conn,
            "localhost",
            "root",
            "27062007",
            "smartbank",
            3306,
            NULL,
            0) == NULL)
    {
        std::cout << "Database connection failed: "
                  << mysql_error(conn) << std::endl;

        mysql_close(conn);
        return false;
    }

    std::cout << "Database connected successfully!" << std::endl;

    mysql_close(conn);
    return true;
}

void Database::disconnect()
{
}