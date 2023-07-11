#ifndef JSON_DESERIALIZER_H
#define JSON_DESERIALIZER_H

#include <string>
#include "rapidjson/document.h"
#include "model/user.h" // Assuming you have a User data model

class JsonDeserializer {
public:
    static user deserializeUserFromJson(const std::string& json);
};

user JsonDeserializer::deserializeUserFromJson(const std::string& json) {
    rapidjson::Document document;
    document.Parse(json.c_str());

    user user;

    if (document.IsObject()) {
        if (document.HasMember("id") && document["id"].IsInt()) {
            user.setID(document["id"].GetInt());
        }
        if (document.HasMember("fullName") && document["fullName"].IsString()) {
            user.setFullName(document["fullName"].GetString());
        }
        if (document.HasMember("userName") && document["userName"].IsString()) {
            user.setUserName(document["userName"].GetString());
        }
        if (document.HasMember("email") && document["email"].IsString()) {
            user.setEmail(document["email"].GetString());
        }
    }

    return user;
}

#endif /* JSON_DESERIALIZER_H */
