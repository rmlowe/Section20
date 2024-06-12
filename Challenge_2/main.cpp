// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "Playing:" << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    for (auto &song: playlist) {
        std::cout << song << std::endl;
    }
    
    std::cout << "Current song:" << std::endl;
    std::cout << current_song << std::endl;
}

char get_selection() {
    display_menu();
    
    char result;
    std::cin >> result;
    return std::toupper(result);
}

auto add_song(std::list<Song> &playlist, std::list<Song>::iterator &current_song) {
    std::string name;
    std::string artist;
    int rating;
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter artist: ";
    std::getline(std::cin, artist);
    std::cout << "Enter rating: ";
    std::cin >> rating;
    
    return playlist.insert(current_song, {name, artist, rating});
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    display_playlist(playlist, *current_song);
    
    char selection {};
    
    while ((selection = get_selection()) != 'Q') {
        switch (selection) {
            case 'F':
                current_song = playlist.begin();
                play_current_song(*current_song);
                break;
            case 'N':
                current_song++;
                
                if (current_song == playlist.end()) {
                    current_song = playlist.begin();
                }
                
                play_current_song(*current_song);
                break;
            case 'P':
                if (current_song == playlist.begin()) {
                    current_song = playlist.end();
                }
                
                current_song--;
                play_current_song(*current_song);
                break;
            case 'A':
                current_song = add_song(playlist, current_song);
                play_current_song(*current_song);
                break;
            case 'L':
                display_playlist(playlist, *current_song);
                break;
            default:
                std::cout << "Invalid selection" << std::endl;
                break;
        }
    }

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}