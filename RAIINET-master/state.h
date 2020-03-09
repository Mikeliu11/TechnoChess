#ifndef STATE_H
#define STATE_H

enum class LinkType {Data, Virus};

struct State {
    int downloadingPlayer;
    LinkType linkType;
};

#endif
