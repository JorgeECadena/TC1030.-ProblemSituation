#pragma once

#include <iostream>
#include <string>

class Video {
    public:
        // Constructors
        Video();    // Default constructor
        Video(int id, std::string name, float length, std::string genre);    // Parameterized constructor

        // Destructor
        ~Video();

        // Getters
        int getId(void);
        std::string getName(void);
        float getLength(void);
        std::string getGenre(void);

        // Setters
        void setId(int id);
        void setName(std::string name);
        void setLength(float length);
        void setGenre(std::string genre);

    protected:
        // Virtual methods
        virtual void getRating(void);
        virtual void addVote(unsigned short value);

    private:
        // Define class attributes
        int id;
        std::string name;
        float length;
        std::string genre;
};