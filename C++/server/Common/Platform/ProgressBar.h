
#ifndef SUNYOUSERVER_PROGRESSBAR_H
#define SUNYOUSERVER_PROGRESSBAR_H

#include <stdio.h>

class barGoLink
{
    char const * empty;
    char const * full;

    int rec_no;
    int rec_pos;
    int num_rec;
    int indic_len;

    public:

        void step( void );
        barGoLink( int );
        ~barGoLink();
};
#endif
