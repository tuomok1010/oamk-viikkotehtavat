#include "notifikaattori.h"
#include "seuraaja.h"

int main()
{
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);

    n.postita("Tama on viesti 1");
    n.poista(&b);
    n.postita("Tama on viesti 2");

    return 0;
}
