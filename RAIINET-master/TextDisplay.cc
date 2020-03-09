#include "TextDisplay.h"
#include <string>
#include <vector>

string TextDisplay::getDownloaded(int player) const {
    string downloaded = "";
    downloaded += to_string(board->getPlayer(player).getNumOfData());
	downloaded += "D, ";
    downloaded += to_string(board->getPlayer(player).getNumOfVirus());
	downloaded += "V";	
	return downloaded;
}

string TextDisplay::getLinks(int player) const {
    string links = "";
    int whichPlayer = 0;
    if (player == 1)
        whichPlayer = 32;
    for (int i = 0; i < 8; ++i) {
        char id = (char)'A' + i + whichPlayer;
        Link &link = board->getPlayer(player).getLink(id);
        links.push_back(id); 
		links += ": ";
        if (board->getTurn() == player || link.getRevealed()) {
            if (link.getType() == LinkType::Data) {
                links += "D";
            } else {
                links += "V";
            }
            string strength = to_string(link.getStrength());
            links += strength;
            links += " ";
        } else {
            links += "? ";
        }
		if (i == 3) {
			links += '\n';
		}
    }
    return links;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
    Board *b = td.getBoard();

    out << "Player 1:" << endl;
    out << "Downloaded: " << td.getDownloaded(1) << endl;
    out << "Abilities: ";
    out << b->getPlayer(1).getNumOfAbilities();
    out << endl;
    out << td.getLinks(1) << endl;
    out << "========" << endl;
    int height = b->getGrid().size();
    int width = b->getGrid()[0].size();
    for (int i = 0; i < height; ++i) {
        for (int k = 0; k < width; ++k) {
            out << b->getGrid()[i][k].print();
        }
        out << endl;
    }
    out << "========" << endl;
    out << "Player 2:" << endl;
    out << "Downloaded: " << td.getDownloaded(2) << endl;
    out << "Abilities: ";
    out << b->getPlayer(2).getNumOfAbilities();
    out << endl;
    out << td.getLinks(2) << endl << endl;
    return out;
}

void TextDisplay::showBoard() {
    cout << *this;
}
