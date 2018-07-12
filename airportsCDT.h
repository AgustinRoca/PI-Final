#ifndef _POSCDT_H_
#define _POSCDT_H_

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
    int move;				/* ( 1 = Aterrizaje / 0 = N/A / -1 = Despegue ) */
    char orOaci[ 5 ];		/* No puede estar en blanco */
    char dstOaci[ 5 ];		/* No puede estar en blanco y puede contener codigos que no sean aeropuertos conocidos */
    char * airline;
};

struct airport
{
	char oaci[5];
	char local[4];
	char * name;
	char iata[4];
	int isInternational;
	size_t takeOffs;
	size_t landings;
	enum days day;
	destinationADT destinations;	/* Lista de struct destination */
};

struct destination
{
	char * oaci; /* debo poner char * por los codigos del tipo AR-XXXX sino seria char dest[5]*/
	size_t landings;
	size_t takeOffs;
};

struct airline
{
	char * name;
	size_t movs;
};

#endif