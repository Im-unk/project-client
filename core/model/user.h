#ifndef USER_H
#define USER_H

#include <string>

// User represents a user
class user {
public:
    user();
    user(int id, const std::string& fullName, const std::string& userName, const std::string& email);

    // Getter methods
    int getID() const;
    std::string getFullName() const;
    std::string getUserName() const;
    std::string getEmail() const;

    // Setter methods
    void setID(int id);
    void setFullName(const std::string& fullName);
    void setUserName(const std::string& userName);
    void setEmail(const std::string& email);

private:
    int m_id;
    std::string m_fullName;
    std::string m_userName;
    std::string m_email;
};

#endif /* USER_H */
