#ifndef _POSCDT_H_
#define _POSCDT_H_
#include <stdlib.h>

typedef struct flightCDT * flightADT;
typedef struct airportCDT * airportADT;
typedef struct airlineQueryCDT * airlineQueryADT;
typedef struct destinationCDT * destinationADT;
typedef struct internationalCDT * internationalADT;

typedef struct airline * tAirline;
typedef struct airport * tAirport;
typedef struct flight * tFlight;
typedef struct destination * tDestination;

enum days {SUN=0, MON, TUE, WED, THU, FRI, SAT};


struct flight
{
    char date [ 11 ];		/* Formato DD/MM/YYYY */
    char time [ 6 ];		/* Formato HH:MM */
    int type;				/* ( 1 = Internacional / 0 = N/A / -1 = Cabotaje ) */
    int mov;				/* ( 1 = Aterrizaje / 0 = N/A / -1 = Despegue ) */
    char * orOaci;		/* No puede estar en blanco */
    char * dstOaci;		/* No puede estar en blanco y puede contener codigos que no sean aeropuertos conocidos */
    char * airline;
};

struct airport
{
	char * oaci;
	char local[4];
	char * name;
	char iata[4];
	int type;
	int condition;
	int isInternational;
	unsigned int takeOffs;
	unsigned int landings;
	enum days day;
	destinationADT destinations;	/* Lista de struct destination */
};

struct destination
{
	char * oaci; /* debo poner char * por los codigos del tipo AR-XXXX sino seria char dest[5]*/
	unsigned int landings;
	unsigned int takeOffs;
};

struct airline
{
	char * name;
	unsigned int movs;
};

#endif
