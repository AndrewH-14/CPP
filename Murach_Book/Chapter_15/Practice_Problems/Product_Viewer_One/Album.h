#ifndef MURACH_ALBUM_H
#define MURACH_ALBUM_H

#include <string>
#include "Media.h"

using namespace std;

class Album : public Media
{
    private:
        string artist;

    public:
        Album(string name         = "",
              double price        = 0.0,
              int disc_pct        = 0,
              string artist_param = "",
              string format       = "") : Media(name, price, disc_pct, format)
        {
            artist = artist_param;
        }

        void set_artist(string artist_param)
        {
            artist = artist_param;
        }

        string get_artist() const
        {
            return artist;
        }

        string get_description() const
        {
            return name + " by " + artist + " - " + format;
        }
};

#endif // MURACH_ALBUM_H