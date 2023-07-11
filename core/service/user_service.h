#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include "../model/user.h"
#include <vector>

// Interface for the user service
class IUserService {
public:
    virtual ~IUserService() {}

    virtual std::vector<user> getUsers() = 0;
    virtual user getUserByID(int id) = 0;
    virtual user addUser(const user& user) = 0;
    virtual user updateUser(const user& user) = 0;
    virtual void deleteUser(int id) = 0;
};

// Implementation of the user service
class UserService : public IUserService {
public:
    std::vector<user> getUsers() override;
    user getUserByID(int id) override;
    user addUser(const user& user) override;
    user updateUser(const user& user) override;
    void deleteUser(int id) override;
};

#endif /* USER_SERVICE_H */
