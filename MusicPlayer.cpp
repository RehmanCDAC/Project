#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a Song structure to represent individual songs
struct Song {
    string title;
    string artist;
    string duration;
};

// Define a MusicPlayer class to manage the playlist and playback
class MusicPlayer {
private:
    vector<Song> playlist;
    int currentSongIndex;
    bool isPlaying;

public:
    MusicPlayer() : currentSongIndex(0), isPlaying(false) {}

    // Method to add a song to the playlist
    void addSong(string title, string artist, string duration) {
        playlist.push_back({title, artist, duration});
        cout << "Song added to the playlist: " << title << " - " << artist << endl;
    }

    // Method to play the current song
    void play() {
        if (!playlist.empty()) {
            isPlaying = true;
            cout << "Playing: " << playlist[currentSongIndex].title << " - " << playlist[currentSongIndex].artist << endl;
        } else {
            cout << "Playlist is empty. Add songs to the playlist." << endl;
        }
    }

    // Method to pause the current song
    void pause() {
        if (isPlaying) {
            isPlaying = false;
            cout << "Paused: " << playlist[currentSongIndex].title << endl;
        } else {
            cout << "No song is currently playing." << endl;
        }
    }

    // Method to skip to the next song
    void next() {
        if (!playlist.empty()) {
            currentSongIndex = (currentSongIndex + 1) % playlist.size();
            play();
        } else {
            cout << "Playlist is empty. Add songs to the playlist." << endl;
        }
    }

    // Method to display the current playlist
    void displayPlaylist() {
        cout << "\nPlaylist:" << endl;
        for (const auto& song : playlist) {
            cout << song.title << " - " << song.artist << " [" << song.duration << "]" << endl;
        }
    }
};

int main() {
    MusicPlayer player;
    int choice;
    do {
        // Display menu options
        cout << "\nMusic Player" << endl;
        cout << "1. Add Song to Playlist" << endl;
        cout << "2. Play" << endl;
        cout << "3. Pause" << endl;
        cout << "4. Next" << endl;
        cout << "5. Display Playlist" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, artist, duration;
                cout << "Enter song title: ";
                cin >> title;
                cout << "Enter artist name: ";
                cin >> artist;
                cout << "Enter song duration: ";
                cin >> duration;
                player.addSong(title, artist, duration);
                break;
            }
            case 2:
                player.play();
                break;
            case 3:
                player.pause();
                break;
            case 4:
                player.next();
                break;
            case 5:
                player.displayPlaylist();
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
