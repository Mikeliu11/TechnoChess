#include "link.h"
using namespace std;

char Link::getName() { return name; }

int Link::getStrength() { return strength; }

int Link::getSpeed() { return speed; }

LinkType Link::getType() { return type; }

bool Link::getDownloaded() { return downloaded; }

bool Link::getRevealed() { return revealed; }

void Link::reveal() { revealed = true; }

void Link::download()
{
    reveal();
    downloaded = true;
}

void Link::incrementSpeed() { speed++; }

void Link::incrementStrength() { strength++; }

void Link::toggleType()
{
    if (type == LinkType::Data)
    {
        type = LinkType::Virus;
    }
    else
    {
        type = LinkType::Data;
    }
}

int Link::getWhose()
{
    return whoseLink;
}