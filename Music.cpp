#include <iostream>
//#include <string>

using namespace std;


struct Song {
    string title;
    string artist;
    string duration;
};

class MusicPlayer {
private:
    static const int MAX_PLAYLIST_SIZE = 100;
    Song playlist[MAX_PLAYLIST_SIZE];
    int playlistSize;
    int currentSongIndex;
    bool isPlaying;

public:
    MusicPlayer() : playlistSize(0), currentSongIndex(0), isPlaying(false) {}

    void addSong(string title, string artist, string duration) {
        if (playlistSize < MAX_PLAYLIST_SIZE) {
            playlist[playlistSize++] = {title, artist, duration};
            cout << "Song added to the playlist: " << title << " - " << artist << endl;
        } else {
            cout << "Playlist is full. Cannot add more songs." << endl;
        }
    }

    void play() {
        if (playlistSize > 0) {
            isPlaying = true;
            cout << "Playing: " << playlist[currentSongIndex].title << " - " << playlist[currentSongIndex].artist << endl;
        } else {
            cout << "Playlist is empty. Add songs to the playlist." << endl;
        }
    }
 
    void pause() {
        if (isPlaying) {
            isPlaying = false;
            cout << "Paused: " << playlist[currentSongIndex].title << endl;
        } else {
            cout << "No song is currently playing." << endl;
        }
    }

    void next() {
        if (playlistSize > 0) {
            currentSongIndex = (currentSongIndex + 1) % playlistSize;
            play();
        } else {
            cout << "Playlist is empty. Add songs to the playlist." << endl;
        }
    }

    void displayPlaylist() {
        cout << "\nPlaylist:" << endl;
        for (int i = 0; i < playlistSize; ++i) {
            cout << playlist[i].title << " - " << playlist[i].artist << " [" << playlist[i].duration << "]" << endl;
        }
    }
};

int main() {
    MusicPlayer player;
    int choice;
    do {
        
        cout << "\nMusic Player" << endl;
        cout << "1. Add Song to Playlist" << endl;
        cout << "2. Play" << endl;
        cout << "3. Pause" << endl;
        cout << "4. Next" << endl;
        cout << "5. Display Playlist" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the input buffer
        cin.ignore();

        switch (choice) {
            case 1: {
                string title;
                string artist;
                string duration;
                cout << "Enter song title: \n";
                getline(cin, title);
                cout << "Enter artist name: \n";
                getline(cin, artist);
                cout << "Enter song duration: \n";
                getline(cin, duration);
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
