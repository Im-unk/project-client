#ifndef JSON_SERIALIZER_H
#define JSON_SERIALIZER_H

#include <string>
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "model/User.h" // Assuming you have a User data model

class JsonSerializer {
public:
    static std::string serializeToJson(const user& user);
    static user deserializeFromJson(const std::string& json);
};

std::string JsonSerializer::serializeToJson(const user& user) {
    rapidjson::Document document;
    document.SetObject();

    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

    // Serialize user data to JSON
    document.AddMember("id", user.getID(), allocator);
    document.AddMember("fullName", rapidjson::StringRef(user.getFullName().c_str()), allocator);
    document.AddMember("userName", rapidjson::StringRef(user.getUserName().c_str()), allocator);
    document.AddMember("email", rapidjson::StringRef(user.getEmail().c_str()), allocator);

    // Convert JSON to string
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    return buffer.GetString();
}

user JsonSerializer::deserializeFromJson(const std::string& json) {
    rapidjson::Document document;
    document.Parse(json.c_str());

    // Deserialize JSON to user object
    user user;
    user.setID(document["id"].GetInt());
    user.setFullName(document["fullName"].GetString());
    user.setUserName(document["userName"].GetString());
    user.setEmail(document["email"].GetString());

    return user;
}

#endif /* JSON_SERIALIZER_H */
