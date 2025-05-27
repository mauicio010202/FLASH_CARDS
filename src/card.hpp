#ifndef CARD_HPP
#define CARD_HPP

#include <string>

class Card{
    private:
        std::string c_front_text;
        std::string c_back_text;
        std::string c_front_image_path;
        std::string c_back_image_path;
        std::string c_code;
    public:
        Card(const std::string& front_text,
             const std::string& back_text,
             const std::string& front_image = "",
             const std::string& back_image = "",
             const std::string& code = "");

        // Getters
        const std::string& getFront() const;
        const std::string& getBack() const;
        const std::string& getFrontImagePath() const;
        const std::string& getBackImagePath() const;
        const std::string& getCodeSnippet() const;

        // Setters
        void setFront(const std::string& front);
        void setBack(const std::string& back);
        void setFrontImagePath(const std::string& front_image);
        void setBackImagePath(const std::string& back_image);
        void setCodeSnippet(const std::string& snippet);

        // Utilities
        bool hasImage() const;
        bool hasCode() const;
};

#endif