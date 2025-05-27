#include "card.hpp"

Card::Card(const std::string& front_text,
           const std::string& back_text,
           const std::string& front_image,
           const std::string& back_image,
           const std::string& code)
           : c_front_text(front_text),
             c_back_text(back_text),
             c_front_image_path(front_image),
             c_back_image_path(back_image),
             c_code(code)
           {}

// Getters
const std::string& Card::getFront() const {
    return c_front_text;
}

const std::string& Card::getBack() const {
    return c_back_text;
}

const std::string& Card::getFrontImagePath() const {
    return c_front_image_path;
}

const std::string& Card::getBackImagePath() const {
    return c_back_image_path;
}

const std::string& Card::getCodeSnippet() const {
    return c_code;
}

// Setters
void Card::setFront(const std::string& question) {
    c_front_text = question;
}

void Card::setBack(const std::string& answer) {
    c_back_text = answer;
}

void Card::setFrontImagePath(const std::string& path) {
    c_front_image_path = path;
}

void Card::setBackImagePath(const std::string& path) {
    c_back_image_path = path;
}

void Card::setCodeSnippet(const std::string& snippet) {
    c_code = snippet;
}

// Utilities
bool Card::hasImage() const {
    return !(c_front_image_path.empty() | c_back_image_path.empty());
}

bool Card::hasCode() const {
    return !c_code.empty();
}